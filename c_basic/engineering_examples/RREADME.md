# 100 Engineering-Style C Examples

This package contains 100 short C files.
They are intentionally small, but the coding style is closer to practical engineering code:

- clear function boundaries
- error checking
- cleanup paths
- const/static usage
- basic resource management
- simple protocol/data handling
- embedded-style bit and state operations

## Build

Example:
```bash
gcc 001_main_template.c -o demo
./demo
```

## Suggested learning order

1. 001-010 basic style
2. 011-020 string and memory
3. 021-040 pointers and resources
4. 041-060 struct and file I/O
5. 061-080 algorithms and runtime control
6. 081-100 data structures and embedded-style snippets

## Notes

- Some file examples create or read `out.txt` or `tmp.txt` in the current directory.
- Examples are standalone and short on purpose.
- These are demo snippets, not a complete production library.
