#!/usr/bin/env python3
"""Render KernaLex reverse derivation output as a Graphviz tree."""

from __future__ import annotations

import argparse
import subprocess
from pathlib import Path

START_MARKER = "=== reverse derivation tree ==="
STOP_PREFIXES = ("***", "#")
INDENT_WIDTH = 2


def read_tree_lines(input_path: Path) -> list[str]:
    text = input_path.read_text(encoding="utf-8", errors="replace")
    lines = text.splitlines()

    try:
        start = lines.index(START_MARKER) + 1
    except ValueError:
        raise SystemExit(f"Missing marker: {START_MARKER}")

    out = []
    for raw in lines[start:]:
        stripped = raw.strip()
        if not stripped:
            continue
        if any(stripped.startswith(prefix) for prefix in STOP_PREFIXES):
            break
        out.append(raw.rstrip())

    if not out:
        raise SystemExit("No derivation tree lines found.")

    return out


def parse_indented_tree(lines: list[str]):
    nodes = []
    edges = []

    stack = []  # (depth, node_id)

    for raw in lines:
        leading_spaces = len(raw) - len(raw.lstrip())
        depth = leading_spaces // INDENT_WIDTH

        label = raw.strip()
        node_id = len(nodes)

        nodes.append((node_id, label))

        while stack and stack[-1][0] >= depth:
            stack.pop()

        if stack:
            parent_id = stack[-1][1]
            edges.append((parent_id, node_id))

        stack.append((depth, node_id))

    return nodes, edges


def write_dot(output_path: Path, nodes, edges):
    output_path.parent.mkdir(parents=True, exist_ok=True)

    with output_path.open("w", encoding="utf-8") as f:
        f.write("digraph ReverseDerivation {\n")
        f.write("  rankdir=TB;\n")
        f.write("  splines=ortho;\n")
        f.write("  nodesep=0.3;\n")
        f.write("  ranksep=0.5;\n")
        f.write('  node [shape=box, style="rounded,filled", fillcolor="#f8f9fa", fontsize=10];\n')
        f.write("\n")

        for node_id, label in nodes:
            safe = label.replace("\\", "\\\\").replace('"', '\\"')
            f.write(f'  n{node_id} [label="{safe}"];\n')

        f.write("\n")

        for parent, child in edges:
            f.write(f"  n{parent} -> n{child};\n")

        f.write("}\n")


def render_png(dot_path: Path, png_path: Path):
    png_path.parent.mkdir(parents=True, exist_ok=True)

    try:
        subprocess.run(
            ["dot", "-Tpng", str(dot_path), "-o", str(png_path)],
            check=True
        )
    except FileNotFoundError:
        raise SystemExit("Graphviz not installed. Run: sudo apt install graphviz")


def main():
    parser = argparse.ArgumentParser(description="Render reverse derivation tree")
    parser.add_argument("input", type=Path)
    parser.add_argument("output_dot", type=Path)
    parser.add_argument("--png", type=Path)

    args = parser.parse_args()

    lines = read_tree_lines(args.input)
    nodes, edges = parse_indented_tree(lines)
    write_dot(args.output_dot, nodes, edges)

    if args.png:
        render_png(args.output_dot, args.png)

    print("Done.")


if __name__ == "__main__":
    main()
