#ifndef IR_H
#define IR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ─────────────────────────────────────────────────────────────────────────
   Three-Address Code (TAC) Quadruple Structure
   ───────────────────────────────────────────────────────────────────────── */

typedef struct {
    char *op;       /* operation: +, -, *, /, =, <, >, ==, !=, if-goto, goto, label, etc. */
    char *arg1;     /* first operand (can be NULL for unary) */
    char *arg2;     /* second operand (NULL for unary or assignment) */
    char *result;   /* destination/result variable */
} Quadruple;

/* ─────────────────────────────────────────────────────────────────────────
   Symbol Table Entry
   ───────────────────────────────────────────────────────────────────────── */

typedef struct {
    char *name;          /* variable identifier */
    char *type;          /* type: "int", "float", "char", etc. */
    int scope_level;     /* scope nesting level (0 = global) */
    int is_temp;         /* 1 if temporary variable, 0 if user-declared */
} SymTabEntry;

/* ─────────────────────────────────────────────────────────────────────────
   Configuration Constants
   ───────────────────────────────────────────────────────────────────────── */

#define MAX_QUADS       10000    /* maximum number of quadruples */
#define MAX_SYMBOLS     5000     /* maximum symbol table entries */
#define MAX_TEMP_NAME   32       /* "t" + number */
#define MAX_LABEL_NAME  32       /* "L" + number */
#define MAX_ID_LEN      256      /* max identifier length */
#define MAX_TYPE_LEN    64       /* max type name length */

/* ─────────────────────────────────────────────────────────────────────────
   Global IR State and API Functions
   ───────────────────────────────────────────────────────────────────────── */

/* Initialize IR subsystem */
void ir_init(void);

/* Symbol table operations */
SymTabEntry* sym_lookup(const char *name);
int sym_insert(const char *name, const char *type, int is_temp);
void sym_push_scope(void);
void sym_pop_scope(void);

/* Temporary variable generation */
char* new_temp(void);
char* new_label(void);

/* Quadruple emission */
void emit_quad(const char *op, const char *arg1, const char *arg2, const char *result);

/* Get quadruple at index */
Quadruple* get_quad(int index);

/* Get current quad count */
int get_quad_count(void);

/* Defer update expression quadruples to the end of the looping blocks */
void ir_defer_update(int start_idx, int end_idx, int current_idx);

/* Output operations */
void print_quads(FILE *fp);
void print_quads_tabular(FILE *fp);

/* Cleanup */
void ir_cleanup(void);

#endif /* IR_H */