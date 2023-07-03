# PPP - Drill 07: Complete the Calculator

Drill for Chapter 07 from Programming: Principles and Practice.

## Instructions

Follow the instructions for the Chapter 7 Drill from Programming: Principles and Practice (page 251), but with the notes below.

### The Supplied Files

This template repo provides you with three files:
1. `calculator08buggy.cpp` - a modified version of the file available online that is the base file you should use in this drill. Do not modify it, just copy it's contents to paste into `calculator08fixed.cpp`. If you are not familiar with how to do this, please look it up (do *NOT* hand copy the code over!).
2. `calculator08fixed.cpp` - an empty file into which you should copy the contents of `calculator08buggy.cpp`, then use for Steps 1--5.
3. `calculator08improved.cpp` - another empty file into which you should copy the contents of `calculator08fixed.cpp` once you have completed Steps 1--5. Use it for Steps 6--11.

### A Note on Syntax

The code in the chapter uses `std::istream::putback(char)` (e.g., `cin.putback(ch);`), but the provided code uses `std::istream::unget()` (e.g., `cin.unget()`), which does not take any input (it just remembers what the last `char` that was collected was). This is a slight change to the code design that does not change the logic or output, just something to be aware of when reading the program. You can see this Stack Overflow for more details: [Difference between putback() and unget()](https://stackoverflow.com/questions/6769416/difference-between-putback-and-unget).

### Additional Specification

Step 1: Before you begin, copy over the code in `calculator08buggy.cpp` to `calculator08fixed.cpp`, then make all the changes in Steps 1--5 in `calculator08fixed.cpp`. There is one compilation bug; make sure you keep note of where and what it is so you can succeed on the quiz component. 

Step 3: There are 4 runtime bugs in the code; make sure you keep note of where and what they are so you can succeed on the quiz component.

Step 5: There are two more bugs. There is 1 missing operation -- its operator is there, but its implementation is missing. There is also 1 style bug -- a point the chapter discusses trying to avoid! This bug could easily cause the code to break (but the autograder will not catch it if you leave it or fix it). Make sure you find it and make note of it for the quiz component. 

Step 6: Copy over your complete `calculator08fixed.cpp` to `calculator08improved.cpp`, then make all the changes in Steps 6--11. 

Step 8: Make sure you do this exactly as the other parts of the program do when they encounter unexpected input. Make sure your output message is: "`cannot take square root of a negative number`".

## Testing and Grading

The autograder will compile and run your code as in the other assignments. For this assignment, tests relating to Steps 1--5 will be run on `calculator08fixed.cpp` and tests relating to Steps 6--11 will be run on `calculator08improved.cpp`. Note that the commands each of these programs can accept are different, and this will be reflected in the tests. 

35% of your score will come from the Canvas quiz on the bugs in the code. 25% of the score comes from successfully completing Steps 1--5. The remaining 40% comes from successfully completing Steps 6--11. 
