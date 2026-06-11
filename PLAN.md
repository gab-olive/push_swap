# Program Structure

## Required Variables
- 2 stacks: a & b
    - b is empty, a has numbers
- sort everything into a


## Expected usage

- Take in possible parameters
    - --simple
    - --medium
    - --complex
    - --adaptive
    - --bench (optionally combines with one of the above)
- Take in a stack of numbers to put in A, list of integers separated by space
- Error checking
- Benchmark mode
    - prints operations to stdout,
    - [bench] lines print to stderr
    - prints disorder
    - prints strategy
    - total number of operations
    - count for each op

## output

- operations in stdout
    sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
- 
## Required algorithms

- simple: o(n²)
- medium: o(n sqrt(n))
- complex: o(n log n)
- adaptive: chooses based on disorder (default)

## Expected Results

• For 100 random numbers, your program should use:
◦ Less than 2000 operations to pass (minimum requirement)
◦ Less than 1500 operations for good performance
◦ Less than 700 operations for excellent performance
• For 500 random numbers, your program should use:
◦ Less than 12000 operations to pass (minimum requirement)
◦ Less than 8000 operations for good performance
◦ Less than 5500 operations for excellent performance