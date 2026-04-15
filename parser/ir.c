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
        if (symtab[sym_count - 1].name) free(symtab[sym_count - 1].name);
        if (symtab[sym_count - 1].type) free(symtab[sym_count - 1].type);
        sym_count--;
    }
    
    if (scope_level > 0) scope_level--;
}

/* ─────────────────────────────────────────────────────────────────────────
   Temporary and Label Generation
   ───────────────────────────────────────────────────────────────────────── */

char* new_temp(void)
{
    static char buf[MAX_TEMP_NAME];
    snprintf(buf, MAX_TEMP_NAME, "t%d", ++temp_counter);
    
    /* Add to symbol table as temporary */
    sym_insert(buf, "temp", 1);
    
    return buf;
}

char* new_label(void)
{
    static char buf[MAX_LABEL_NAME];
    snprintf(buf, MAX_LABEL_NAME, "L%d", ++label_counter);
    return buf;
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
   Quadruple Access
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

    /* Strict quadruple format: row, op, arg1, arg2, result */
    fprintf(fp, "%-5s | %-10s | %-12s | %-12s | %-12s\n",
            "row", "op", "arg1", "arg2", "result");
    fprintf(fp, "------+------------+--------------+--------------+--------------\n");

    /* Print each quadruple */
    for (int i = 0; i < quad_count; i++) {
        Quadruple *q = &quads[i];

        const char *op     = q->op     ? q->op     : "";
        const char *arg1   = q->arg1   ? q->arg1   : "";
        const char *arg2   = q->arg2   ? q->arg2   : "";
        const char *result = q->result ? q->result  : "";

        fprintf(fp, "%-5d | %-10s | %-12s | %-12s | %-12s\n",
                i + 1, op, arg1, arg2, result);
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
        if (quads[i].op) free(quads[i].op);
        if (quads[i].arg1) free(quads[i].arg1);
        if (quads[i].arg2) free(quads[i].arg2);
        if (quads[i].result) free(quads[i].result);
    }
    
    /* Free symbol table strings */
    for (int i = 0; i < sym_count; i++) {
        if (symtab[i].name) free(symtab[i].name);
        if (symtab[i].type) free(symtab[i].type);
    }
    
    quad_count = 0;
    sym_count = 0;
}