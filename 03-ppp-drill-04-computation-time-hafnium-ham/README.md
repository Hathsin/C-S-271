[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8428992&assignment_repo_type=AssignmentRepo)
# PPP-Drill-04-Computation-Time
Adapted version of Drill for Chapter 04 from Programming: Principles and Practice (pg.126).

## Instructions

Follow the instructions for the Chapter 4 drill (page 126), but note that this assignment requires you to split the work into two source files for grading. The steps are split into two files: steps 1-5 go into `largeandsmall.cpp`.  While the remaining steps 6-11 go into `computation.cpp`. Both base files (containing a basic hello world that you should delete) are included with this template.

The `std_lib_facilities.h` header file is included in this template so you will have ready access to it. 

After each step of this drill, run your program to make sure it is really doing what you expect it to. Keep a list of what mistakes you make so that you can try to avoid these in the future. 

## How the Assignment Will be Graded

Test cases will be based on the steps below using the GitHub Classroom autograding. Use any syntax expressly noted in the assignment. The autograder will scan the output for outputs that are specified in the drill, using the text defined in the drill, nothing more. To run your program, it will first compile it with something like:

`g++ -std=c++11 form_letter.cpp -o <name>.out`

Then will run the resulting file with something like...

`./<name>.out`

Scoring rules are in Canvas. 

## `largeandsmall.cpp`

This file should address steps 1-5 in the drill. Note that the autograder expects the outputs to match the following:

When the numbers are equal write: 

"the numbers are equal\n"

When the numbers are not equal (and not close), the outputs should be:

"the smaller value is:`<smaller number>`\n"
"the larger value is:`<larger number>`\n"

When the numbers are close together write: 

"the numbers are almost equal\n"

First example run: 

    ./largeandsmall.out
    4
    5
    the smaller value is:4
    the larger value is:5
    |

Second example run:

    ./largeandsmall.out
    1000
    1000.0001
    the smaller value is:1000
    the larger value is:1000.0001
    the numbers are almost equal
    100
    100.1
    the smaller value is:100
    the larger value is:100.1
    |

## `computation.cpp`

This file should address steps 6-11 in the drill. Note that once you complete `largeandsmall.cpp`, you should copy it into `computation.cpp` as the starting point for the remaining steps. 

Syntax specific cases: 

When the number is the largest: "`<input value converted to meters>` that is the largest so far\n"

When the number is the smallest: "`<input value converted to meters>` that is the smallest so far\n"

When the loop ends:

"smallest:`<smallest value in meters>`\n"

"largest:`<number in meters of largest>`\n"

"sum:`<sum of all the numbers entered>`\n"

"`<smallest value entered, in meters>`\n"

"`<values in order from smallest to largest>`\n"

"`<largest value entered, in meters>`\n"

Example run:

    ./computation.out
    10cm
    0.1 that is the largest so far
    5cm
    0.05 that is the smallest so far
    |
    smallest:0.05
    largest:0.10
    sum:0.15
    0.05
    0.1
