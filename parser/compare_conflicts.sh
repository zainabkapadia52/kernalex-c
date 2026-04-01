#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
PARSER_DIR="$ROOT_DIR/parser"
LEXER_SRC="$ROOT_DIR/lexer/kernalex.l"
OUT_DIR="$PARSER_DIR/comparison_outputs"
mkdir -p "$OUT_DIR"

build_debug_parser() {
    local grammar="$1"
    local base_name="$2"
    local tab_c="$PARSER_DIR/${base_name}.tab.c"
    local tab_h="$PARSER_DIR/${base_name}.tab.h"
    local lex_c="$PARSER_DIR/${base_name}.lex.c"
    local bin="$PARSER_DIR/${base_name}"

    bison -d -o "$tab_c" "$grammar"
    flex -o "$lex_c" "$LEXER_SRC"
    gcc -Wall -Wextra -std=c99 -DYYDEBUG=1 -DPARSER_MODE -I"$ROOT_DIR" -o "$bin" "$tab_c" "$lex_c"
}

run_case() {
    local bin="$1"
    local input_file="$2"
    local output_file="$3"
    "$bin" "$input_file" > "$output_file" 2>&1
}

build_debug_parser "$PARSER_DIR/kernalex_before.y" "kernalex_before_dbg"
build_debug_parser "$PARSER_DIR/kernalex.y" "kernalex_after_dbg"

run_case "$PARSER_DIR/kernalex_before_dbg" "$PARSER_DIR/tests/pointer_decl_conflict.kl" "$OUT_DIR/pointer_decl_before.txt"
run_case "$PARSER_DIR/kernalex_after_dbg" "$PARSER_DIR/tests/pointer_decl_conflict.kl" "$OUT_DIR/pointer_decl_after.txt"
paste "$OUT_DIR/pointer_decl_before.txt" "$OUT_DIR/pointer_decl_after.txt" > "$OUT_DIR/pointer_decl_compare.txt"

run_case "$PARSER_DIR/kernalex_before_dbg" "$PARSER_DIR/tests/dangling_else_conflict.kl" "$OUT_DIR/dangling_else_before.txt"
run_case "$PARSER_DIR/kernalex_after_dbg" "$PARSER_DIR/tests/dangling_else_conflict.kl" "$OUT_DIR/dangling_else_after.txt"
paste "$OUT_DIR/dangling_else_before.txt" "$OUT_DIR/dangling_else_after.txt" > "$OUT_DIR/dangling_else_compare.txt"

echo "Saved comparison outputs to $OUT_DIR"
