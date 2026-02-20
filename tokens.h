#ifndef TOKENS_H
#define TOKENS_H

// Token types
typedef enum {
    // End of file
    TOK_EOF = 0,
    
    // Keywords - Type keywords
    TOK_INT,
    TOK_SHORT,
    TOK_FLOAT,
    TOK_CHAR,
    TOK_VOID,
    TOK_BOOL,
    TOK_BOOLEAN,
    TOK_STRUCT,
    TOK_INT8_T,
    TOK_INT16_T,
    TOK_INT32_T,
    TOK_INT64_T,
    
    // Type modifiers/storage
    TOK_SIGNED,
    TOK_UNSIGNED,
    TOK_EXTERN,
    TOK_STATIC,
    
    // Control flow
    TOK_IF,
    TOK_ELSE,
    TOK_FOR,
    TOK_WHILE,
    TOK_REPEAT,
    TOK_UNTIL,
    TOK_SWITCH,
    TOK_CASE,
    TOK_DEFAULT,
    TOK_BREAK,
    TOK_CONTINUE,
    TOK_RETURN,
    
    // Other
    TOK_SIZEOF,
    TOK_BEGIN,
    TOK_END,
    TOK_TRUE,
    TOK_FALSE,
    
    // Identifiers and literals
    TOK_IDENTIFIER,
    TOK_INTEGER,
    TOK_FLOAT_LIT,
    TOK_CHAR_LIT,
    TOK_STRING_LIT,
    
    // Operators
    TOK_PLUS,
    TOK_MINUS,
    TOK_MULT,
    TOK_DIV,
    TOK_MOD,
    TOK_ASSIGN,
    TOK_EQ,
    TOK_NE,
    TOK_LT,
    TOK_LE,
    TOK_GT,
    TOK_GE,
    TOK_SPACESHIP,
    TOK_AND,
    TOK_OR,
    TOK_NOT,
    TOK_BITAND,
    TOK_BITOR,
    TOK_XOR,
    TOK_BITNOT,
    TOK_LSHIFT,
    TOK_RSHIFT,
    TOK_INC,
    TOK_DEC,
    TOK_PLUSEQ,
    TOK_MINUSEQ,
    TOK_MULTEQ,
    TOK_DIVEQ,
    TOK_MODEQ,
    TOK_ARROW,
    TOK_AMP,
    TOK_STAR,
    
    // Punctuation
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_LBRACE,
    TOK_RBRACE,
    TOK_LBRACKET,
    TOK_RBRACKET,
    TOK_SEMICOLON,
    TOK_COMMA,
    TOK_DOT,
    TOK_COLON,
    
    // Comments (documented but not returned as tokens)
    // TOK_COMMENT,
    // TOK_DOC_COMMENT,
    
    TOK_UNKNOWN
} TokenType;

#endif /* TOKENS_H */
