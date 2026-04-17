# Overall Tests: Comprehensive Parser Validation

This folder contains a comprehensive suite of 10 test programs spanning the entire assignment 4 (Parts 1 through 4).

These tests validate:
- Expressions, assignments, and precedence rules (Part 1)
- Control flow and block structures (Part 2)
- Generated Intermediate Code (IR) tabular output formatting (Part 3)
- Correct error diagnostics and recovery for malformed/invalid programs (Part 4)

## Run all tests

From repository root:

```bash
./parser/run_overall_tests.sh
```

The script gracefully handles both successful compilations and expected syntactic errors. It writes the consolidated outputs (source code, generated quadruple tables, and error diagnostics) to:

- `parser/overall_tests/all_outputs.txt`