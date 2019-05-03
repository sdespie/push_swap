# Algorithmic project: push_swap

The push_swap project is a number sorting program in C, using two stacks. The goal of the assignment is to create a program able to **sort** any amount of (different) numbers using a **given set of operations** on two number stacks. There is also another constraint: the sorting has to be done in the **least amount of moves possible**.

[Push_swap.en.pdf](/push_swap.en.pdf) is the task file.

# Authors

**Sebastien De Spiegeleer**: Algorithms, workflow, visualisation, parsing

# How it works

When I tried implementing any of the well-known pre-existing sorting algorithms (i.e *bubble sort*, *insertion sort*, etc..), with the constraints from the subject, the results were less than satisfying, especially concerning the amount of moves.

Instead, I decided to use three different *kinda* simple algorithms, covering **three cases**. I couldn't find an algorithm that was appropriate to single-handedly cover all three cases.

* ## Three numbers or less

In the case where there are only three or two numbers, the first algorithm will very efficiently sort the numbers in less than three moves, by applying the appropriate combination of *swaps* and *rotations* on the first stack, never using the second.

* ## Small amount of numbers (less or equel to 10)

In this case, the second algorithm will push the *smallest* number to the second stack, and will continue to do so until there are only three numbers left. The second stack is thus *reverse-sorted*. It will then apply the algorithm from the first case on the first stack, then push everything from the second stack back to the first.

* ## Every other case

In the case where there are more than 10 numbers, my algorithm will operate with a quick sort algorithm. I'm actually running it twice with 2 differents optimizations, keeping the best.
At any point during the process, I'm checking if we are not in one of the previous situation. Also, I impremented many optimisations including movement optimization and 

## The checker program

The checker program simply checks if the instructions we feed it on the standard input manage to sort the given numbers. It is very useful when checking if the push_swap program outputs a valid answer; simply by using it like <br> `./push_swap x x x x | ./checker x x x x`

# How to clone?

If you want to clone it, you can use the following command:

```
git clone https://github.com/sdespie/push_swap.git
```

# Installation

Clone repository and then go into the created directory and run the following command:

```
make
```
Tested on OS X 10.11.

## Usage

### `checker`

```
Usage: ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
```

### `push_swap`

```
Usage: ./push_swap [-o[speed][v][m][c]]
    speed :
        Set up the display speed between [1 ; 9]. Default = 5.
    v     :
        Activate visualization mode.
    m     :
        Display the median while sorting.
    c     :
        Display with different colors for colorblind persons.
```
