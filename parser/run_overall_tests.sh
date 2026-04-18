#!/usr/bin/env bash
set -u

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

OUT_DIR="parser/overall_tests"
OUT_FILE="$OUT_DIR/all_outputs.txt"

# Ensure directory exists just in case
mkdir -p "$OUT_DIR"
: > "$OUT_FILE"

echo "=== OVERALL TESTS ==="

total=0
ok=0

# Loop through all .kl files in the overall_tests directory
for f in "$OUT_DIR"/*.kl; do
  # Check if file exists to safely handle empty globs
  [ -e "$f" ] || continue
  
  total=$((total + 1))
  echo "Running test: $f"
  
  echo "================================================================================" >> "$OUT_FILE"
  echo "FILE: $f" >> "$OUT_FILE"
  echo "" >> "$OUT_FILE"
  echo "--- Source Code ---" >> "$OUT_FILE"
  cat "$f" >> "$OUT_FILE"
  echo "" >> "$OUT_FILE"
  
  temp_out=$(mktemp)
  ./parser/kernalex_parser "$f" > "$temp_out" 2>&1
  ec=$?

  if [ $ec -eq 0 ]; then
    # Typically a Part 1, 2, or 3 test (successful code generation)
    ok=$((ok + 1))
    cat "$temp_out" | sed -n '/=== Generated Intermediate Code (Quadruple Table) ===/,$p' | sed 's/=== Generated Intermediate Code (Quadruple Table) ===/---Generated Intermediate Code (Quadruple Table) ---/' >> "$OUT_FILE"
  else
    # Typically a Part 4 test (syntactic/semantic error intentionally triggered)
    echo "--- Error Diagnostics ---" >> "$OUT_FILE"
    if grep -Eq "\[SYNTAX ERROR\]|\[IR ERROR\]" "$temp_out"; then
      status="OK_DIAGNOSTIC"
      ok=$((ok + 1))
    else
      status="MISSING_DIAGNOSTIC"
    fi
    printf "exit=%d status=%s\n\n" "$ec" "$status" >> "$OUT_FILE"
    # Print the last few lines of the output just like part 4 test script
    tail -n 8 "$temp_out" | sed 's/^/  /' >> "$OUT_FILE"
  fi
  
  rm -f "$temp_out"
  
  echo "" >> "$OUT_FILE"
  echo "" >> "$OUT_FILE"
  echo "" >> "$OUT_FILE"
done

echo "========================================"
echo "RESULT: $ok/$total tests passed or emitted correct diagnostics."
echo "Full output saved to: $OUT_FILE"
echo "========================================"
