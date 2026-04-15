#!/usr/bin/env bash
set -u

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

OUT_DIR="parser/part4_tests/outputs"
SUMMARY_FILE="parser/part4_tests/summary.txt"
mkdir -p "$OUT_DIR"
: > "$SUMMARY_FILE"

echo "=== PART 4: ERROR HANDLING TESTS ==="

total=0
ok=0

for f in parser/part4_tests/*.kl; do
  base="$(basename "$f" .kl)"
  out_file="$OUT_DIR/$base.txt"

  total=$((total + 1))
  echo
  echo "=== $f ===" | tee -a "$SUMMARY_FILE"

  ./parser/kernalex_parser "$f" > "$out_file" 2>&1
  ec=$?

  if grep -Eq "\[SYNTAX ERROR\]|\[IR ERROR\]" "$out_file"; then
    status="OK_DIAGNOSTIC"
    ok=$((ok + 1))
  else
    status="MISSING_DIAGNOSTIC"
  fi

  printf "exit=%d status=%s output=%s\n" "$ec" "$status" "$out_file" | tee -a "$SUMMARY_FILE"
  tail -n 8 "$out_file" | sed 's/^/  /'
done

echo >> "$SUMMARY_FILE"
printf "RESULT: %d/%d tests emitted expected diagnostics\n" "$ok" "$total" | tee -a "$SUMMARY_FILE"

echo
cat "$SUMMARY_FILE"
