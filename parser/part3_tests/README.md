# Part 3 Tests: Quadruple Output Format

This folder contains small programs for validating Part 3 requirements:

- IR printed in clean tabular quadruple format
- Row-by-row ordering from top to bottom
- Readable temporary names (`t1`, `t2`, ...)
- Clear separation between source and generated IR

## Run all tests

From repository root:

```bash
./parser/run_part3_tests.sh
```

The script writes consolidated output to:

- `parser/part3_tests/all_quadruple_tables.txt`
