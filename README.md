# <div align="center">⚙️ push_swap (a [42](https://42perpignan.fr/) project) ⚙️</div>
## 📑 Introduction
School 42's `push_swap` is a very simple and a highly straightforward algorithm project :
data must be sorted.\
The goal is to write a program in C which calculates and displays on the standard output the smallest number of intructions, that sorts the integers received as arguments. The integers are stored as a stack, a total of two stacks are available, and eleven intructions for moving integers from one stack to another, rotate a stack etc etc...\
Having to sort the elements of a stack is restrictive and unconventional, especially when only a limited number of different instructions are available. The challenge is to find an algorithm that's efficient and versatile enough to sort any set of integers, and to write it down in C.\
My algorithm is a kind of [QuickSort](https://en.wikipedia.org/wiki/Quicksort) implementation for two stacks. It consists of 3 steps: 
1. Send all the integers to the second stack, pre-sorting them at the same time.
2. Return all the integers one by one to the first stack, looking for the most optimized move to sort them into the first stack.
3. Make final rotations to replace the sorted stack.

In the case where the input consists of three intergers or less, I've also implemented a way of sorting them in two moves or less.

Subject : <a href=asset/en.subject.pdf>en.push_swap_subject.pdf<a/>
### My grade
[![nsalles's 42 push_swap Score](https://badge42.coday.fr/api/v2/clshyl91d071301p436jjiyqr/project/3378261)](https://github.com/Coday-meric/badge42)
## Usage
Download `push_swap` and enter the repo :
```sh
git clone https://github.com/Floperatok/42-push_swap.git && cd 42-push_swap
```
Compile the project :
```sh
make && make clean
```
Execute the program and enter a list of integers of your choice :
```sh
./push_swap -5 7 97 12 0
```
The program should return a list of instructions within the stacks for sorting theme.
### Intructions
| Name | Effect |
| ---- | ------ |
| `sa` | (swap a) Swap the first 2 elements at the top of stack a |
| `sb` | (swap b) Swap the first 2 elements at the top of stack b |
| `ss` | sa and sb at the same time |
| `pa` | (push a) Take the first element at the top of b and put it at the top of a |
| `pb` | (push a) Take the first element at the top of a and put it at the top of b |
| `ra` | (rotate a) Shift up all elements of stack a by 1. The first element becomes the last one |
| `rb` | (rotate b) Shift up all elements of stack b by 1. The first element becomes the last one |
| `rr` | ra and rb at the same time |
| `rra` | (reverse rotate a) Shift down all elements of stack a by 1. |
| `rrb` | (reverse rotate b) Shift down all elements of stack b by 1. |
| `rrr` | rra and rrb at the same time |

## Bonus
As a bonus, we can obtionally write down a program named the `checker` that check if the set of instructions returned by `push_swap` correctly sort the stack.\
Compile `push_swap` and the `checker` :
```sh
make && make bonus && make clean
```
Pipe `push_swap` and the `checker` together with the same list of integers :
```sh
ARGS="-5 7 98 12 0" ; ./push_swap $ARGS | ./checker $ARGS
```
The `checker` should return the set of instructions for sorting the stack, and write `ok` if the stack is sorted, `ko` otherwise. And `Error` if wrong arguments are given.