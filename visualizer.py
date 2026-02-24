#!/usr/bin/env python3
"""
Push_swap visualizer - Terminal-based visualization
Usage: ./push_swap <args> | python3 visualizer.py <args>
   or: python3 visualizer.py <args>   (runs push_swap automatically)
"""
import sys
import os
import subprocess
import time
import shutil

# ANSI colors
RESET = "\033[0m"
BOLD = "\033[1m"
DIM = "\033[2m"
RED = "\033[91m"
GREEN = "\033[92m"
YELLOW = "\033[93m"
BLUE = "\033[94m"
MAGENTA = "\033[95m"
CYAN = "\033[96m"
WHITE = "\033[97m"
BG_BLUE = "\033[44m"
BG_RED = "\033[41m"


def gradient_color(val, min_val, max_val):
    """Return ANSI color based on value position in range."""
    if max_val == min_val:
        return GREEN
    ratio = (val - min_val) / (max_val - min_val)
    if ratio < 0.2:
        return BLUE
    elif ratio < 0.4:
        return CYAN
    elif ratio < 0.6:
        return GREEN
    elif ratio < 0.8:
        return YELLOW
    return RED


def normalize(args):
    """Normalize values to 0..n-1 like push_swap does."""
    sorted_args = sorted(enumerate(args), key=lambda x: x[1])
    result = [0] * len(args)
    for rank, (orig_idx, _) in enumerate(sorted_args):
        result[orig_idx] = rank
    return result


def draw_stacks(stack_a, stack_b, n, op_name, op_count, total_ops):
    """Draw both stacks side by side with bars."""
    term_w = shutil.get_terminal_size().columns
    term_h = shutil.get_terminal_size().lines
    max_display = min(term_h - 6, max(len(stack_a), len(stack_b), 1))
    bar_area = (term_w - 15) // 2
    max_bar = max(bar_area - 8, 10)

    # Clear screen
    sys.stdout.write("\033[2J\033[H")

    # Header
    header = f" {BOLD}{MAGENTA}push_swap visualizer{RESET}"
    op_info = f" {BOLD}Op {op_count}/{total_ops}: {CYAN}{op_name}{RESET}"
    print(f"{header}  |{op_info}")
    print(f" {DIM}{'─' * (term_w - 2)}{RESET}")

    # Column headers
    a_header = f" {BOLD}{BG_BLUE} Stack A ({len(stack_a)}) {RESET}"
    b_header = f" {BOLD}{BG_RED} Stack B ({len(stack_b)}) {RESET}"
    pad = bar_area + 4
    print(f"{a_header}{' ' * max(0, pad - 20)}{b_header}")

    # Draw rows
    for row in range(max_display):
        # Stack A
        if row < len(stack_a):
            val = stack_a[row]
            bar_len = max(1, int((val + 1) / n * max_bar))
            color = gradient_color(val, 0, n - 1)
            a_str = f" {color}{'█' * bar_len}{RESET} {DIM}{val}{RESET}"
            a_raw_len = bar_len + 2 + len(str(val))
        else:
            a_str = ""
            a_raw_len = 0

        # Stack B
        if row < len(stack_b):
            val = stack_b[row]
            bar_len = max(1, int((val + 1) / n * max_bar))
            color = gradient_color(val, 0, n - 1)
            b_str = f" {color}{'█' * bar_len}{RESET} {DIM}{val}{RESET}"
        else:
            b_str = ""

        padding = max(1, pad - a_raw_len)
        print(f"{a_str}{' ' * padding}{b_str}")

    # Footer
    print(f" {DIM}{'─' * (term_w - 2)}{RESET}")
    sorted_check = stack_a == list(range(n)) and len(stack_b) == 0
    status = f"{GREEN}SORTED!{RESET}" if sorted_check else f"{YELLOW}sorting...{RESET}"
    print(f" {status}  |  {DIM}Total ops: {BOLD}{op_count}{RESET}")


def execute_op(stack_a, stack_b, op):
    """Execute a push_swap operation on the stacks."""
    if op == "sa" and len(stack_a) >= 2:
        stack_a[0], stack_a[1] = stack_a[1], stack_a[0]
    elif op == "sb" and len(stack_b) >= 2:
        stack_b[0], stack_b[1] = stack_b[1], stack_b[0]
    elif op == "ss":
        if len(stack_a) >= 2:
            stack_a[0], stack_a[1] = stack_a[1], stack_a[0]
        if len(stack_b) >= 2:
            stack_b[0], stack_b[1] = stack_b[1], stack_b[0]
    elif op == "pa" and len(stack_b) > 0:
        stack_a.insert(0, stack_b.pop(0))
    elif op == "pb" and len(stack_a) > 0:
        stack_b.insert(0, stack_a.pop(0))
    elif op == "ra" and len(stack_a) > 1:
        stack_a.append(stack_a.pop(0))
    elif op == "rb" and len(stack_b) > 1:
        stack_b.append(stack_b.pop(0))
    elif op == "rr":
        if len(stack_a) > 1:
            stack_a.append(stack_a.pop(0))
        if len(stack_b) > 1:
            stack_b.append(stack_b.pop(0))
    elif op == "rra" and len(stack_a) > 1:
        stack_a.insert(0, stack_a.pop())
    elif op == "rrb" and len(stack_b) > 1:
        stack_b.insert(0, stack_b.pop())
    elif op == "rrr":
        if len(stack_a) > 1:
            stack_a.insert(0, stack_a.pop())
        if len(stack_b) > 1:
            stack_b.insert(0, stack_b.pop())


def main():
    if len(sys.argv) < 2:
        print(f"Usage: ./push_swap <args> | python3 {sys.argv[0]} <args>")
        print(f"   or: python3 {sys.argv[0]} <args>")
        sys.exit(1)

    # Parse arguments
    args = []
    for arg in sys.argv[1:]:
        for num in arg.split():
            args.append(int(num))

    n = len(args)
    normalized = normalize(args)

    # Try to read ops from stdin (piped), or run push_swap
    ops = []
    if not sys.stdin.isatty():
        import select
        if select.select([sys.stdin], [], [], 0.1)[0]:
            ops = [line.strip() for line in sys.stdin if line.strip()]
    if not ops:
        push_swap = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                 "push_swap")
        str_args = [str(a) for a in args]
        result = subprocess.run([push_swap] + str_args, capture_output=True,
                                text=True)
        ops = [line.strip() for line in result.stdout.split('\n')
               if line.strip()]

    stack_a = list(normalized)
    stack_b = []
    total_ops = len(ops)

    # Speed control
    if n <= 10:
        delay = 0.4
    elif n <= 100:
        delay = 0.02
    else:
        delay = 0.005

    # Initial state
    draw_stacks(stack_a, stack_b, n, "initial", 0, total_ops)
    time.sleep(delay * 3)

    # Execute operations
    for i, op in enumerate(ops):
        execute_op(stack_a, stack_b, op)
        draw_stacks(stack_a, stack_b, n, op, i + 1, total_ops)
        time.sleep(delay)

    # Final state
    draw_stacks(stack_a, stack_b, n, "done", total_ops, total_ops)
    print()


if __name__ == "__main__":
    main()
