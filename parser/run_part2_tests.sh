#!/usr/bin/env bash
set -u

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

OUT_FILE="parser/part2_tests/all_table_outputs.txt"
: > "$OUT_FILE"

echo "=== PART 1: EXPRESSION TESTS ==="

total=0
ok=0

# Loop through all .kl files in the part2_tests directory
for f in parser/part2_tests/*.kl; do
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
  
  # Run the parser, grab stderr & stdout, and use sed to extract just the Quadruple Table
  ./parser/kernalex_parser "$f" 2>&1 | sed -n '/=== Generated Intermediate Code (Quadruple Table) ===/,$p' | sed 's/=== Generated Intermediate Code (Quadruple Table) ===/---Generated Intermediate Code (Quadruple Table) ---/' >> "$OUT_FILE"
  ec=${PIPESTATUS[0]} # Grab the exit code of kernalex_parser, before the pipe

  if [ $ec -eq 0 ]; then
    ok=$((ok + 1))
  else
    echo "[WARNING] $f returned non-zero exit code ($ec)" >> "$OUT_FILE"
  fi
  
  echo "" >> "$OUT_FILE"
  echo "" >> "$OUT_FILE"
  echo "" >> "$OUT_FILE"
done

echo "========================================"
echo "RESULT: $ok/$total tests ran successfully."
echo "Tables saved to: $OUT_FILE"
echo "========================================"
