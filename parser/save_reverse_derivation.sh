#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
PARSER_BIN="$ROOT_DIR/parser/kernalex_parser"
TEST_DIR="$ROOT_DIR/parser/tests"
OUT_DIR="$ROOT_DIR/parser/reverse_derivation_tree"

mkdir -p "$OUT_DIR"

"$PARSER_BIN" "$TEST_DIR/test_all_comments.kl" > "$OUT_DIR/test_all_comments.txt" 2>&1
"$PARSER_BIN" "$TEST_DIR/test_all_literals.kl" > "$OUT_DIR/test_all_literals.txt" 2>&1
"$PARSER_BIN" "$TEST_DIR/test_all_numeric_formats.kl" > "$OUT_DIR/test_all_numeric_formats.txt" 2>&1
"$PARSER_BIN" "$TEST_DIR/test_simple_all_features.kl" > "$OUT_DIR/test_simple_all_features.txt" 2>&1
"$PARSER_BIN" "$TEST_DIR/dangling_else_conflict.kl" > "$OUT_DIR/dangling_else_tree.txt" 2>&1
"$PARSER_BIN" "$TEST_DIR/pointer_decl_conflict.kl" > "$OUT_DIR/pointer_decl_tree.txt" 2>&1

echo "Saved reverse derivation outputs to $OUT_DIR"
