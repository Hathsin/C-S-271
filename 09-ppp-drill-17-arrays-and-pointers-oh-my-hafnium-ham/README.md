# PPP - Drill 17: Arrays and Pointers Oh My!

By Matthew Groover

Drill from Chapter 17 of Programming: Principles and Practice

This exercise will follow drill 17 from PPP page 622-623. The drill is split up into two parts: one is on `vector`s and arrays the second covers pointers. The main goal is famalirize yourself with pointers and `vector`s and how they can be used in a program. You are allowed to modify the functions you generate in the steps beyond their initial scope should you wish.

In the repository you are provided with:
```
vectors.cpp //the first part will go in this file
```
```
pointers.cpp // the second part will go in this file
```
 You are also provided with `std_lib_facilities.h` this should cover any libraries needed. 
 
 There is a `Makefile`, but it is empty -- you will need to develop at least two targets to cover the two parts of the assignment. Name these targets `vectors` and `pointers` -- they should compile the `main()` functions from `vectors.cpp` and `pointers.cpp`, respectively.   
 
 you are also provided with `local_autograde.py` which can be run with:
 ```
 python3 local_autograde.py
 ```

## How It's Graded 

This first part is autograded this will count as 50/100 points. The autograder will compile your code by running `make vectors`. 

The second part must be manually graded by the TA or instructor. This is necessary because we are working with memory addresses which will vary heavily between computers. The remaining 50 points come from: 

- Correct `Makefile`: 10%
- Correct output: 20%
- Pointer methods used: 20%

## Example Runs

`vector.cpp` (note: after each array, there is an additional newline)
```
make 
./vectors
0 
0 
0 
0 
0 
0 
...
0

10
11
etc.
```

`pointer.cpp`
```
make 
./pointers
adress val: 0x7ffedf53ac24
val store: 7
adress val: 0x19532c0
val store: 1 2 4 8 16 32 64 
adress val post moval: 0x19532c0
val store: 1
adress val post move: 0x19532c0
val store: 1 2 4 8 16 32 64 
adress val step3: 0x19532c0
val store: 0 0 0 0 16 32 64 0 0 0 
adress val step3: 0x19532f0
val store: 0 0 0 0 0 0 0 0 0 0 
vals swapped: 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 16 32 64 0 0 0 
 vector vals before swap: 
100 101 102 103 104 105 106 107 108 109  
200 201 202 203 204 205 206 207 208 209  
 vector vals post swap: 
200 201 202 203 204 205 206 207 208 209  
100 101 102 103 104 105 106 107 108 109 

```
