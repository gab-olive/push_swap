*This project has been created as part of the 42 curriculum by zleullie, gabrielo.*

## Description
**Push_swap** is an algorithmic project from the 42 curriculum. The goal is to sort a stack of integers using a limited set of operations (swapping, pushing, rotating) and a second empty stack, minimizing the total number of operations. The project highlights algorithmic complexity (Big-O notation) and requires implementing multiple sorting strategies to handle arrays of different sizes optimally.

The implemented program evaluates the provided stack and sorts it using four required approaches:
- **Simple algorithm** (O(n²))
- **Medium algorithm** (O(n√n))
- **Complex algorithm** (O(n log n))
- **Adaptive algorithm** (selects strategy based on initial disorder)

## Instructions

### Compilation
Run `make` at the root of the repository to compile the `push_swap` executable.
```bash
make
```

### Execution
Run the compiled binary passing a list of integers as arguments. By default, the program outputs the smallest set of instructions to correctly sort the numbers in ascending order:
```bash
./push_swap 2 1 3 6 5 8
```

**Strategy Selection:**
You can force a specific algorithm by adding its respective flag:
- `--simple` : O(n²) strategy
- `--medium` : O(n√n) strategy
- `--complex` : O(n log n) strategy
- `--adaptive` : Chosen automatically based on the disorder metric (Default behavior).

```bash
./push_swap --complex 4 67 3 87 23
```

**Benchmark Mode:**
You can run the program with a benchmark mode flag (`--bench`) to print execution metrics to standard error (stderr), including the level of disorder, the chosen strategy, the complexity class, and total amount of performed operations.
```bash
./push_swap --bench 4 67 3 87 23
```

## Algorithms

To strictly adhere to target algorithmic complexity constraints using the `push_swap` instruction set, this project implements:

1. **Simple Algorithm ($O(n^2)$)**:
   Uses a minimum extraction strategy (`minsort.c`). It pushes the smallest elements from Stack A to Stack B iteratively, and pushes them back once Stack A is properly oriented. Highly optimal for small configurations.

2. **Medium Algorithm ($O(n \sqrt{n})$)**:
   Uses a block/chunk-based sorting strategy (`chunk.c`). Evaluates chunks of numbers and pushes them into partitions in Stack B, significantly reducing search depth when retrieving the maximum blocks back to Stack A.

3. **Complex Algorithm ($O(n \log n)$)**:
   Uses an adaptation of the Radix Sort algorithm (`radix.c`), executing a stable bitwise sort over the stacks. Perfect for handling significantly large or highly disordered datasets effectively within operation ranges.

4. **Adaptive Strategy**:
   The default mode. It runs an initial `disorder` computation $D$: the fraction of incorrect pair orders compared to total pairs. 
   - If Low Disorder ($D < 0.2$), delegates to the $O(n^2)$ solver.
   - If Medium Disorder ($0.2 \le D < 0.5$), delegates to the $O(n \sqrt{n})$ solver.
   - If High Disorder ($D \ge 0.5$), delegates to the $O(n \log n)$ solver.

## Resources
- **Classic References**: 
  - [Radix Sort](https://en.wikipedia.org/wiki/Radix_sort)
  - [Big-O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- **AI Assistance**: AI was utilized to write this README file, prioritizing comprehensive learning over direct code generation mapping.
