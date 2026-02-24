# push_swap

Sorting algorithm project from 42 school. Sort a stack of integers using a limited set of operations with the minimum number of moves.

## How it works

Two stacks (A and B) and 11 operations:

| Operation | Description |
|-----------|-------------|
| `sa` `sb` `ss` | Swap first two elements |
| `pa` `pb` | Push top element to other stack |
| `ra` `rb` `rr` | Rotate (first becomes last) |
| `rra` `rrb` `rrr` | Reverse rotate (last becomes first) |

### Algorithm

- **2-5 elements**: Optimized sort (find min, push to B, sort 3, push back)
- **6+ elements**: Turkish algorithm (cost-based insertion sort between stacks)

### Performance

| Size | Avg ops | Max ops | 42 threshold (5/5) |
|------|---------|---------|-------------------|
| 3    | 1       | 2       | <= 3              |
| 5    | 8       | 10      | <= 12             |
| 100  | ~560    | ~600    | < 700             |
| 500  | ~5100   | ~5350   | < 5500            |

## Build

```bash
make          # builds push_swap
make bonus    # builds checker
make re       # clean rebuild
```

## Usage

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23    # OK
```

## Test

```bash
bash tests.sh
```

Runs 34 tests covering error handling, correctness (via checker), and performance benchmarks.

## Visualizer

```bash
python3 visualizer.py 4 67 3 87 23                          # auto-runs push_swap
./push_swap 4 67 3 87 23 | python3 visualizer.py 4 67 3 87 23   # piped mode
```

Terminal-based visualization with colored bars showing both stacks in real-time.
