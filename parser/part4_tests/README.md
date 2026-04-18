# Part 4 Tests: Error Handling and Diagnostics

This suite validates Part 4 requirements:

- detect invalid expressions and malformed syntax
- detect unsupported constructs during IR generation
- print meaningful diagnostics
- fail gracefully without crashing

## Run

From repository root:

```bash
make part4-tests
```

Outputs are written to:

- `parser/part4_tests/outputs/*.txt`
- `parser/part4_tests/summary.txt`
