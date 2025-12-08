*This project has been created as part of the 42 curriculum by jperez-s*

# Description
This project consists of sorting data in a stack using a limited set of instructions, aiming to achieve the lowest possible number of actions. While learning about sorting algorithms and their complexity.
The following are the set of instructions available to move around the numbers between stack A and stack B:
- sa (swap a): Swap the first 2 elements at the top of stack a.
- sb (swap b): Swap the first 2 elements at the top of stack b.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
- pb (push b): Take the first element at the top of a and put it at the top of b.
- ra (rotate a): Shift up all elements of stack a by 1.
- rb (rotate b): Shift up all elements of stack b by 1.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
- rrr : rra and rrb at the same time.

# Instructions
First of all the proyect needs to be compiled with a Makefile using the rule 'make', that gives us a program called 'push_swap' which receives a set of arguments as an input; example (./push_swap 42 -42 0).
The output or result of the program is a set of instructions by which the stack A is sorted by using stack B as well, for the previous input the output will be: 'ra'.
Furthermore the output can be checked by later compiling the 'checker' with the rule in the Makefile 'bonus', this program takes the output from the push_swap program, execute all instructions and validate that all the numbers are in stack A and that stack B is empty. If the rules are correct and the conditions are met the program will display 'OK' else it will display 'KO'.
Both programs will display 'Error' followed by a newline if the arguments passed are not valid (duplicate numbers, outside the range of int, and if non numeric characters are placed).

# Resources
The main resources are from Wikipedia about the complexity of algorithms, blogs explaining different cases as well as youtube videos, and the use of AI to create and test limit cases such as long long int which overflowed and ended up passing as arguments, also to understand.
