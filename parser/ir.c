#include "ir.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ─────────────────────────────────────────────────────────────────────────
   Global IR State
   ───────────────────────────────────────────────────────────────────────── */

static Quadruple quads[MAX_QUADS];           /* quadruple array */
static int quad_count = 0;                   /* number of quadruples emitted */

static SymTabEntry symtab[MAX_SYMBOLS];      /* symbol table */
static int sym_count = 0;                    /* number of symbols */
static int scope_level = 0;                  /* current scope level */

static int temp_counter = 0;                 /* for generating t1, t2, t3... */
static int label_counter = 0;                /* for generating L1, L2, L3... */

/* ─────────────────────────────────────────────────────────────────────────
   Initialization
   ───────────────────────────────────────────────────────────────────────── */

void ir_init(void)
{
    quad_count = 0;
    sym_count = 0;
    scope_level = 0;
    temp_counter = 0;
    label_counter = 0;
    
    memset(quads, 0, sizeof(quads));
    memset(symtab, 0, sizeof(symtab));
}

/* ─────────────────────────────────────────────────────────────────────────
   Symbol Table Operations
   ───────────────────────────────────────────────────────────────────────── */

SymTabEntry* sym_lookup(const char *name)
{
    if (!name) return NULL;
    
    /* Search from most recent to oldest in current or parent scopes */
    for (int i = sym_count - 1; i >= 0; i--) {
        if (symtab[i].name && strcmp(symtab[i].name, name) == 0) {
            return &symtab[i];
        }
    }
    return NULL;
}

int sym_insert(const char *name, const char *type, int is_temp)
{
    if (!name || sym_count >= MAX_SYMBOLS) {
        return -1;
    }
    
    /* Check if already exists in current scope */
    for (int i = sym_count - 1; i >= 0 && symtab[i].scope_level == scope_level; i--) {
        if (symtab[i].name && strcmp(symtab[i].name, name) == 0) {
            /* Already exists at this scope */
            return i;
        }
    }
    
    /* Insert new symbol */
    int idx = sym_count++;
    symtab[idx].name = (char *)malloc(strlen(name) + 1);
    if (symtab[idx].name) strcpy(symtab[idx].name, name);
    
    symtab[idx].type = (char *)malloc(strlen(type ? type : "unknown") + 1);
    if (symtab[idx].type) strcpy(symtab[idx].type, type ? type : "unknown");
    
    symtab[idx].scope_level = scope_level;
    symtab[idx].is_temp = is_temp;
    
    return idx;
}

void sym_push_scope(void)
{
    scope_level++;
}

void sym_pop_scope(void)
{
    /* Remove all symbols at current scope level */
    while (sym_count > 0 && symtab[sym_count - 1].scope_level == scope_level) {
        if (symtab[sym_count - 1].name) {
            free(symtab[sym_count - 1].name);
            symtab[sym_count - 1].name = NULL;
        }
        if (symtab[sym_count - 1].type) {
            free(symtab[sym_count - 1].type);
            symtab[sym_count - 1].type = NULL;
        }
        sym_count--;
    }
    
    if (scope_level > 0) scope_level--;
}

/* ─────────────────────────────────────────────────────────────────────────
   Temporary and Label Generation
   ───────────────────────────────────────────────────────────────────────── */

char* new_temp(void)
{
    char buf[MAX_TEMP_NAME];
    snprintf(buf, MAX_TEMP_NAME, "t%d", ++temp_counter);
    
    /* Add to symbol table as temporary */
    sym_insert(buf, "temp", 1);
    
    char *res = (char *)malloc(strlen(buf) + 1);
    if (res) strcpy(res, buf);
    return res;
}

char* new_label(void)
{
    char buf[MAX_LABEL_NAME];
    snprintf(buf, MAX_LABEL_NAME, "L%d", ++label_counter);
    char *res = (char *)malloc(strlen(buf) + 1);
    if (res) strcpy(res, buf);
    return res;
}

/* ─────────────────────────────────────────────────────────────────────────
   Quadruple Emission
   ───────────────────────────────────────────────────────────────────────── */

void emit_quad(const char *op, const char *arg1, const char *arg2, const char *result)
{
    if (!op) {
        fprintf(stderr, "Error: invalid IR operation (NULL op)\n");
        return;
    }

    if (quad_count >= MAX_QUADS) {
        fprintf(stderr, "Error: Quadruple buffer overflow\n");
        return;
    }
    
    Quadruple *q = &quads[quad_count++];
    
    q->op = (char *)malloc(strlen(op) + 1);
    if (q->op) strcpy(q->op, op);
    
    q->arg1 = arg1 ? (char *)malloc(strlen(arg1) + 1) : NULL;
    if (q->arg1) strcpy(q->arg1, arg1);
    
    q->arg2 = arg2 ? (char *)malloc(strlen(arg2) + 1) : NULL;
    if (q->arg2) strcpy(q->arg2, arg2);
    
    q->result = result ? (char *)malloc(strlen(result) + 1) : NULL;
    if (q->result) strcpy(q->result, result);
}

/* ─────────────────────────────────────────────────────────────────────────
   Quadruple Access and Manipulation
   ───────────────────────────────────────────────────────────────────────── */

Quadruple* get_quad(int index)
{
    if (index >= 0 && index < quad_count) {
        return &quads[index];
    }
    return NULL;
}

int get_quad_count(void)
{
    return quad_count;
}

void ir_defer_update(int start_idx, int end_idx, int current_idx)
{
    int len1 = end_idx - start_idx;
    int len2 = current_idx - end_idx;
    if (len1 <= 0 || len2 <= 0) return;
    
    Quadruple *temp = (Quadruple*)malloc(len1 * sizeof(Quadruple));
    if (!temp) return;
    
    for (int i = 0; i < len1; i++) {
        temp[i] = quads[start_idx + i];
    }
    for (int i = 0; i < len2; i++) {
        quads[start_idx + i] = quads[end_idx + i];
    }
    for (int i = 0; i < len1; i++) {
        quads[start_idx + len2 + i] = temp[i];
    }
    free(temp);
}

/* ─────────────────────────────────────────────────────────────────────────
   Output Functions
   ───────────────────────────────────────────────────────────────────────── */

void print_quads(FILE *fp)
{
    fprintf(fp, "\n=== Generated Intermediate Code (Three-Address Code) ===\n\n");
    
    for (int i = 0; i < quad_count; i++) {
        Quadruple *q = &quads[i];
        fprintf(fp, "%4d: ", i + 1);
        
        if (q->op) fprintf(fp, "op=%-10s ", q->op);
        if (q->arg1) fprintf(fp, "arg1=%-10s ", q->arg1);
        if (q->arg2) fprintf(fp, "arg2=%-10s ", q->arg2);
        if (q->result) fprintf(fp, "result=%-10s", q->result);
        
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
}

void print_quads_tabular(FILE *fp)
{
    fprintf(fp, "\n=== Generated Intermediate Code (Quadruple Table) ===\n\n");

    /* Strict quadruple format: pseudo-code, op, arg1, arg2, result */
    fprintf(fp, "%-22s | %-8s | %-13s | %-13s | %-13s\n",
            "", "op", "arg1", "arg2", "result");
    fprintf(fp, "-----------------------+----------+---------------+---------------+---------------\n");

    /* Print each quadruple */
    for (int i = 0; i < quad_count; i++) {
        Quadruple *q = &quads[i];

        const char *op     = q->op     ? q->op     : "";
        const char *arg1   = q->arg1   ? q->arg1   : "";
        const char *arg2   = q->arg2   ? q->arg2   : "";
        const char *result = q->result ? q->result  : "";

        char expr[64];
        if (strcmp(op, "label") == 0) snprintf(expr, sizeof(expr), "label %s:", result);
        else if (strcmp(op, "goto") == 0) snprintf(expr, sizeof(expr), "goto %s", result);
        else if (strcmp(op, "ifFalse") == 0) snprintf(expr, sizeof(expr), "ifFalse %s goto %s", arg1, result);
        else if (strcmp(op, "ifTrue") == 0) snprintf(expr, sizeof(expr), "ifTrue %s goto %s", arg1, result);
        else if (strcmp(op, "return") == 0) {
            if (arg1[0]) snprintf(expr, sizeof(expr), "return %s", arg1);
            else snprintf(expr, sizeof(expr), "return");
        } else if (strcmp(op, "=") == 0) snprintf(expr, sizeof(expr), "%s=%s", result, arg1);
        else if (strcmp(op, "minus") == 0) snprintf(expr, sizeof(expr), "%s=minus %s", result, arg1);
        else if (strcmp(op, "not") == 0) snprintf(expr, sizeof(expr), "%s=not %s", result, arg1);
        else if (strcmp(op, "~") == 0) snprintf(expr, sizeof(expr), "%s=~%s", result, arg1);
        else if (strcmp(op, "&") == 0 && arg2[0] == '\0') snprintf(expr, sizeof(expr), "%s=&%s", result, arg1);
        else if (strcmp(op, "*") == 0 && arg2[0] == '\0') snprintf(expr, sizeof(expr), "%s=*%s", result, arg1);
        else if (arg1[0] && arg2[0] && result[0]) snprintf(expr, sizeof(expr), "%s=%s%s%s", result, arg1, op, arg2);
        else snprintf(expr, sizeof(expr), "%s=%s %s %s", result, op, arg1, arg2);

        fprintf(fp, "%-22s | %-8s | %-13s | %-13s | %-13s\n",
                expr, op, arg1, arg2, result);
    }
    fprintf(fp, "\n");
}

/* ─────────────────────────────────────────────────────────────────────────
   Cleanup
   ───────────────────────────────────────────────────────────────────────── */

void ir_cleanup(void)
{
    /* Free quadruple strings */
    for (int i = 0; i < quad_count; i++) {
        if (quads[i].op) {
            free(quads[i].op);
            quads[i].op = NULL;
        }
        if (quads[i].arg1) {
            free(quads[i].arg1);
            quads[i].arg1 = NULL;
        }
        if (quads[i].arg2) {
            free(quads[i].arg2);
            quads[i].arg2 = NULL;
        }
        if (quads[i].result) {
            free(quads[i].result);
            quads[i].result = NULL;
        }
    }
    
    /* Free symbol table strings */
    for (int i = 0; i < sym_count; i++) {
        if (symtab[i].name) {
            free(symtab[i].name);
            symtab[i].name = NULL;
        }
        if (symtab[i].type) {
            free(symtab[i].type);
            symtab[i].type = NULL;
        }
    }
    
    quad_count = 0;
    sym_count = 0;
}