[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9069650&assignment_repo_type=AssignmentRepo)
# PPP - Drill 14: Time to Make the Objects

By Phoebe O. Toups Dugas

Drill from Chapter 14 of Programming: Principles and Practice.

## Grading

For this drill, the grading comes from completing the assignments on Canvas. This code template is provided to give you the base files that will help you complete the code portion of the assignment. Your code will not be graded and there is *NO NEED* to commit any code back to your repository. See the Canvas assignments for further detail.

## Instructions

Follow the steps in the textbook and use the code to answer the quiz questions. It is recommended that you do the quiz and write the code at the same time. 

## Provided Files

A number of files are provided for this assignment to simplify you needing to write them yourself. You could also simply construct all of the classes in a single file -- the choice of how to proceed is up to you. 

For some parts of the program, header files are all you need; for others, it makes sense to have a header (`.h`) and a matching source file (`.cpp`). It is recommended that you use `drill13a.cpp` for Steps 1--5; `drill13b.cpp` for Step 6; and `drill13c.cpp` for Step 7. 

The files have **SOME OF** the needed `#include`s provided for you, but you will have to write the code yourself. 

## Compiling the Code

If you make use of the provided files, you will need to make sure that you write your compilation command to compile all the necessary `.cpp` files for the steps. 

In performing Step 1, for example, you likely need to use `drill13a.cpp` for the main file, but also compile `B1.cpp`. As you progress, you need to compile more and more `.cpp` files (unless you take your own approach). 

Because of the number of files involved, you almost certainly will have `.h` files that get `#include`d more than once. **This is a problem for you!** Doing so means that your program will be attempting to re-declare things. 

To get around this issue, you will need to learn how to use **header guards**. This is simple, and **extremely common** in real code. 

Essentially, when you use `#include` you tell the preprocessor to find the `#include`d file and copy the contents of the file to that place. You want to make sure this happens only once when you compile. If you don't, you'll get an error that you've re-defined something -- which is true, if you define a variable in, say, `B1.h` and then `#include "B1.h"` in two files, then you have effectively written the same code twice and, thus, attempted to define the variable in two places! 

To avoid this problem, you can use a **header guard**. At the top of your `.h` files, you have the preprocessor check for a preprocessor variable. You basically tell the preprocessor to check for the preprocessor variable -- if it's defined, skip the file; if it's not, then define the preprocessor variable and copy over the file. 

By convention (i.e., the way everyone does it; you don't have to, but this is how **everyone** does it), the variable's name is the name of the `.h` file in all capital letters, followed by `_H`. So, if you are naming the variable for `B1.h`, the variable's name will be `B1_H`. If you're naming the variable for `Closed_polygon.h`, then your variable is `CLOSED_POLYGON_H`. 

With this in mind, you just need a few lines of code in your `.h` file to ensure that it never gets `#include`d more than once:

````
#ifndef <preprocessor variable>
#define <preprocessor variable>

<ALL OF YOUR CODE>

#endif
````

Concretely, if you're wanting to make sure that `B1.h` is successfully guarded, you'll write:

````
#ifndef B1_H
#define B1_H

<THE CODE FOR B1.h>

#endif
````

For most of the `.h` files provided, you'll likely need to use header guards to get the drill to work. If you need more explanation, start with this resource: https://www.learncpp.com/cpp-tutorial/header-guards/. If you poke around some of the provided files in other assignments (or on the web), you'll see the header guards (though they may not exactly follow the naming convention). 


