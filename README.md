*This project has been created as part of the 42 curriculum by jperez-s*

# Push_swap

## Description

Push_swap is a sorting algorithm project that challenges you to sort data on a stack using a limited set of instructions, aiming to achieve the lowest possible number of operations. The project deepens understanding of sorting algorithms and their complexity.

The program receives a list of integers as arguments and outputs a sequence of operations that sort them in ascending order on stack A, using stack B as an auxiliary stack.

### Available Operations

- **sa** (swap a): Swap the first 2 elements at the top of stack A
- **sb** (swap b): Swap the first 2 elements at the top of stack B
- **ss**: Execute sa and sb at the same time
- **pa** (push a): Take the first element at the top of B and put it at the top of A
- **pb** (push b): Take the first element at the top of A and put it at the top of B
- **ra** (rotate a): Shift up all elements of stack A by 1 (first becomes last)
- **rb** (rotate b): Shift up all elements of stack B by 1
- **rr**: Execute ra and rb at the same time
- **rra** (reverse rotate a): Shift down all elements of stack A by 1 (last becomes first)
- **rrb** (reverse rotate b): Shift down all elements of stack B by 1
- **rrr**: Execute rra and rrb at the same time

## Instructions

### Compilation

Compile the project using the provided Makefile:

```bash
make
```

This generates the `push_swap` executable.

For the bonus checker program:

```bash
make bonus
```

This generates the `checker` executable.

### Usage

Run the program with a list of integers as arguments:

```bash
./push_swap 4 67 3 87 23
```

The program outputs the sequence of operations needed to sort the numbers.

### Verification with Checker

To verify that the operations correctly sort the stack:

```bash
./push_swap 4 2 1 3 | ./checker 4 2 1 3
```

The checker program will output:
- `OK` if stack A is sorted in ascending order and stack B is empty
- `KO` if the result is incorrect
- `Error` if invalid arguments are provided

### Error Handling

Both programs display `Error` followed by a newline when:
- Duplicate numbers are provided
- Arguments are outside the integer range (INT_MIN to INT_MAX)
- Non-numeric characters are provided

### Examples

```bash
# Sort a small set
./push_swap 2 1 3

# Sort with negative numbers
./push_swap -42 0 42 -10

# Verify the output
./push_swap 5 4 3 2 1 | ./checker 5 4 3 2 1

# Count operations
./push_swap 4 2 1 3 | wc -l
```

## Resources

### Classic References

- Sorting Algorithms - Wikipedia: Overview of various sorting algorithms and their complexity
- Big O Notation - Wikipedia: Understanding algorithm complexity
- Various blog posts and tutorials on stack-based sorting algorithms
- YouTube videos explaining different sorting approaches and optimization techniques

### AI Usage

AI tools were used for the following tasks:

- **Testing edge cases**: Generation and testing of limit cases such as LONG_MAX and LONG_MIN values that overflow and need proper handling
- **Understanding complexity**: Clarification of time and space complexity concepts for different algorithmic approaches
- **Debugging assistance**: Identifying issues with integer overflow handling and validation logic
- **Code review**: Suggestions for optimization and cleaner implementation patterns

🥭