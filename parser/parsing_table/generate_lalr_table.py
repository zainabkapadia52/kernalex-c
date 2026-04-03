#!/usr/bin/env python3
import argparse
import csv
import re
from pathlib import Path

STATE_RE = re.compile(r'^State\s+(\d+)\s*$')
TERMINAL_RE = re.compile(r'^\s{4}(.+?)\s+\((\d+)\)')
NONTERMINAL_RE = re.compile(r'^\s{4}(.+?)\s+\((\d+)\)')
SHIFT_RE = re.compile(r'^\s+(.+?)\s+shift, and go to state\s+(\d+)\s*$')
GOTO_RE = re.compile(r'^\s+(.+?)\s+go to state\s+(\d+)\s*$')
REDUCE_RE = re.compile(r'^\s+(.+?)\s+reduce using rule\s+(\d+)\s+\((.+?)\)\s*$')
DEFAULT_RE = re.compile(r'^\s+\$default\s+reduce using rule\s+(\d+)\s+\((.+?)\)\s*$')
ACCEPT_RE = re.compile(r'^\s+\$default\s+accept\s*$')


class StateInfo:
    def __init__(self):
        self.actions = {}
        self.gotos = {}
        self.default_reduce = None
        self.accept = False


def normalize_symbol(symbol):
    return '$' if symbol == '$end' else symbol


def parse_output(path: Path):
    lines = path.read_text().splitlines()
    terminals = []
    nonterminals = []
    states = {}
    max_state = -1
    mode = None
    current_state = None

    for line in lines:
        if line.startswith('Terminals, with rules where they appear'):
            mode = 'terminals'
            continue
        if line.startswith('Nonterminals, with rules where they appear'):
            mode = 'nonterminals'
            continue
        if line.startswith('State '):
            match = STATE_RE.match(line)
            if match:
                mode = 'state'
                current_state = int(match.group(1))
                max_state = max(max_state, current_state)
                states.setdefault(current_state, StateInfo())
            continue

        if mode == 'terminals':
            if line.startswith('    error '):
                continue
            match = TERMINAL_RE.match(line)
            if match:
                name = normalize_symbol(match.group(1).strip())
                if name not in terminals and name != 'error':
                    terminals.append(name)
            continue

        if mode == 'nonterminals':
            if line.strip() == '' or line.lstrip().startswith('$accept'):
                continue
            match = NONTERMINAL_RE.match(line)
            if match:
                name = normalize_symbol(match.group(1).strip())
                if name not in nonterminals:
                    nonterminals.append(name)
            continue

        if current_state is None:
            continue

        state_info = states[current_state]

        if ACCEPT_RE.match(line):
            state_info.accept = True
            continue

        match = SHIFT_RE.match(line)
        if match:
            symbol = normalize_symbol(match.group(1).strip())
            state_info.actions[symbol] = f's{match.group(2)}'
            continue

        match = GOTO_RE.match(line)
        if match:
            symbol = normalize_symbol(match.group(1).strip())
            state_info.gotos[symbol] = match.group(2)
            continue

        match = DEFAULT_RE.match(line)
        if match:
            state_info.default_reduce = match.group(1)
            continue

        match = REDUCE_RE.match(line)
        if match:
            symbol = normalize_symbol(match.group(1).strip())
            state_info.actions[symbol] = f'r{match.group(2)}'
            continue

    return terminals, nonterminals, states, max_state


def load_state_filter(states_file: Path):
    if states_file is None:
        return None
    selected = []
    for raw_line in states_file.read_text().splitlines():
        line = raw_line.strip()
        if not line or line.startswith('#'):
            continue
        selected.append(int(line))
    return selected


def build_rows(terminals, nonterminals, states, max_state, selected_states=None):
    if selected_states is None:
        state_list = list(range(max_state + 1))
    else:
        allowed = set(selected_states)
        state_list = [state for state in range(max_state + 1) if state in allowed]

    rows = []
    for state in state_list:
        info = states.get(state, StateInfo())
        row = {'State': str(state)}

        for terminal in terminals:
            if terminal == '$' and info.accept:
                row[terminal] = 'acc'
            elif terminal in info.actions:
                row[terminal] = info.actions[terminal]
            elif info.default_reduce is not None:
                row[terminal] = f'r{info.default_reduce}'
            else:
                row[terminal] = ''

        for nonterminal in nonterminals:
            row[nonterminal] = info.gotos.get(nonterminal, '')

        rows.append(row)

    return rows


def write_csv(prefix: Path, terminals, nonterminals, rows):
    csv_path = prefix.with_suffix('.csv')
    with csv_path.open('w', newline='') as handle:
        writer = csv.writer(handle)
        writer.writerow(['State', 'ACTION'] + [''] * (max(len(terminals) - 1, 0)) + ['GOTO'] + [''] * (max(len(nonterminals) - 1, 0)))
        writer.writerow(['State'] + terminals + nonterminals)
        for row in rows:
            writer.writerow([row['State']] + [row.get(symbol, '') for symbol in terminals] + [row.get(symbol, '') for symbol in nonterminals])
    return csv_path


def write_action_csv(prefix: Path, terminals, rows):
    csv_path = prefix.with_name(prefix.name + '_action').with_suffix('.csv')
    with csv_path.open('w', newline='') as handle:
        writer = csv.writer(handle)
        writer.writerow(['State'] + terminals)
        for row in rows:
            writer.writerow([row['State']] + [row.get(symbol, '') for symbol in terminals])
    return csv_path


def write_goto_csv(prefix: Path, nonterminals, rows):
    csv_path = prefix.with_name(prefix.name + '_goto').with_suffix('.csv')
    with csv_path.open('w', newline='') as handle:
        writer = csv.writer(handle)
        writer.writerow(['State'] + nonterminals)
        for row in rows:
            writer.writerow([row['State']] + [row.get(symbol, '') for symbol in nonterminals])
    return csv_path


def write_html(prefix: Path, terminals, nonterminals, rows, table_type='complete'):
    html_path = prefix.with_name(prefix.name + '_' + table_type).with_suffix('.html')

    action_colspan = len(terminals)
    goto_colspan = len(nonterminals)
    table_html = '<table class="table"><tr><th rowspan="2">State</th>'
    table_html += f'<th colspan="{action_colspan}">ACTION</th>'
    table_html += f'<th colspan="{goto_colspan}">GOTO</th>'
    table_html += '</tr><tr>'
    for terminal in terminals:
        table_html += f'<th>{terminal}</th>'
    for nonterminal in nonterminals:
        table_html += f'<th>{nonterminal}</th>'
    table_html += '</tr>'
    for row in rows:
        table_html += f'<tr><td>{row["State"]}</td>'
        for terminal in terminals:
            table_html += f'<td>{row.get(terminal, "")}</td>'
        for nonterminal in nonterminals:
            table_html += f'<td>{row.get(nonterminal, "")}</td>'
        table_html += '</tr>'
    table_html += '</table>'

    html_content = f'''<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>LALR(1) Parsing Table - {table_type}</title>
<style>
body {{ font-family: Arial, sans-serif; margin: 20px; }}
h1 {{ color: #333; }}
table.table {{ border-collapse: collapse; margin: 20px 0; width: 100%; }}
th, td {{ border: 1px solid #999; padding: 8px 10px; text-align: center; }}
th {{ background-color: #e0e0e0; font-weight: bold; }}
</style>
</head>
<body>
<h1>LALR(1) Parsing Table - {table_type.title()}</h1>
{table_html}
</body>
</html>'''
    
    with html_path.open('w') as handle:
        handle.write(html_content)
    return html_path


def main():
    parser = argparse.ArgumentParser(description='Extract the LALR(1) parsing table from a Bison .output file.')
    parser.add_argument('output_file', type=Path, help='Path to the Bison .output file')
    parser.add_argument('output_prefix', type=Path, help='Output file prefix without extension')
    parser.add_argument('--states-file', type=Path, help='Optional file listing important states to include')
    args = parser.parse_args()

    terminals, nonterminals, states, max_state = parse_output(args.output_file)
    selected_states = load_state_filter(args.states_file)
    
    # Generate complete table
    rows_all = build_rows(terminals, nonterminals, states, max_state, None)
    write_csv(args.output_prefix, terminals, nonterminals, rows_all)
    write_action_csv(args.output_prefix, terminals, rows_all)
    write_goto_csv(args.output_prefix, nonterminals, rows_all)
    write_html(args.output_prefix, terminals, nonterminals, rows_all, 'complete')
    
    # Generate important states table if provided
    if selected_states:
        rows_imp = build_rows(terminals, nonterminals, states, max_state, selected_states)
        prefix_imp = args.output_prefix.with_name(args.output_prefix.name + '_important')
        write_csv(prefix_imp, terminals, nonterminals, rows_imp)
        write_action_csv(prefix_imp, terminals, rows_imp)
        write_goto_csv(prefix_imp, nonterminals, rows_imp)
        write_html(prefix_imp, terminals, nonterminals, rows_imp, 'important')


if __name__ == '__main__':
    main()
