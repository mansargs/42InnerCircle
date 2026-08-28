# Push_swap

## Overview

`push_swap` is a project that sorts a stack of integers using a limited set of operations, aiming to use the minimum number of moves. The project is typically assigned in coding schools like 42, and is a great exercise in algorithmic thinking and optimization.

The project consists of two main programs:
- **push_swap**: Outputs the sequence of operations needed to sort the stack.
- **checker**: (Bonus) Verifies if a given sequence of operations sorts the stack correctly.

## Project Structure

```
Push_swap/
  bonus/           # Bonus checker and utilities
    checker.c
    checker.h
    get_next_line_utils.c
    get_next_line.c
    get_next_line.h
    stack_operations.c
  common/          # Shared logic and helpers
    clear_functions.c
    common.h
    indexing.c
    list_management.c
    split_and_convert.c
    str_helpers.c
    Validator_Utils.c
  mandatory/       # Main push_swap logic and algorithms
    butterfly.c
    push_swap.c
    push_swap.h
    stack_operations.c
    stack_sorting.c
  Makefile         # Build instructions
```

## How to Build

```bash
make
```

## How to Use

To generate a sequence of operations to sort a stack:
```bash
./push_swap <list of integers>
```

To check if a sequence of operations sorts the stack (bonus):
```bash
./checker <list of integers>
```
Then input the operations, one per line.

## Allowed Operations

- `sa`, `sb`, `ss`: Swap the first two elements of stack a, b, or both.
- `pa`, `pb`: Push the top element from one stack to the other.
- `ra`, `rb`, `rr`: Rotate stack a, b, or both upwards.
- `rra`, `rrb`, `rrr`: Rotate stack a, b, or both downwards.

---

## The Butterfly Algorithm

The **Butterfly algorithm** is an efficient sorting strategy for the `push_swap` project, especially for large stacks. It is inspired by the Radix sort and works by distributing elements between two stacks (`a` and `b`) in a pattern that resembles the wings of a butterfly.

### How It Works

1. **Indexing**:
   Each number in the stack is replaced by its index in the sorted order. This normalization step allows the algorithm to work with a predictable range of values.

2. **Bitwise Distribution**:
   The algorithm iterates over each bit position (from least significant to most significant) of the indexed values:
   - For each bit position, it pushes elements with a `0` in that bit to stack `b`, and rotates elements with a `1` in that bit within stack `a`.
   - After processing all elements for a bit position, it pushes all elements back from stack `b` to stack `a`.

3. **Repeat**:
   This process is repeated for each bit position. After all bits have been processed, the stack is sorted.

### Why "Butterfly"?

The movement of elements between the two stacks, based on their bit values, creates a pattern reminiscent of a butterfly’s wings: elements "fly" out to stack `b` and return to stack `a` in a new order, gradually sorting themselves.

### Advantages

- **Efficiency**: O(n log n) time complexity.
- **Simplicity**: Only uses allowed stack operations.
- **Scalability**: Works well for large input sizes.

---

## Credits

- Developed as part of the 42 school curriculum.
- Butterfly algorithm inspired by Radix sort.
