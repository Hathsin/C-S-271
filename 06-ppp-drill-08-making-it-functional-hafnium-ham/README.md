# PPP - Drill 08: Making It Functional

Adapted version of Drill 08 from Programming: Principles and Practice

## IMPORTANT - Using the local autograder functionality. 

This template includes `local_autograde.py`, a Python script that can make use of GitHub Classroom's autograder settings to check your code without expending action minutes. Please check your code with the local autograder before committing as much as you can. The local autograder is still a work-in-progress and generally does not properly handle the special tests that require running other Unix commands or shell scripts. 

To use the local autograder, make sure you are in the directory for the project you want to check, then call it through the Python interpreter in a terminal window, like so:

`python3 local_autograde.py`

The local autograder will then run in the terminal; you should see it run all the tests, then will provide detailed results on what did and did not work. 

## Provided Files

The following files are provided for the assignment, based on the steps. Note that some of the base files will not compile yet -- they are either empty or just provide the code directly from the book that needs fixing.

+ `std_lib_facilities.h`, `local_autograde.py`: Our usual support files. 
+ `my.h`, `my.cpp`, `use.cpp`: The three empty files that need to be written and compiled together; use these for Step 0 and Step 1. 
+ `Makefile`: An empty file for you to write your `make` commands for Step 0 that are used to compile Step 1.
+ `namespaces_main.cpp` and `namespaces_xyz.cpp`: `namespaces_main.cpp` contains the `main()` from Step 3 and `include`s `namespaces_xyz.cpp` -- you may not edit this file! Do the work of Step 3 in `namespaces_xyz.cpp`. `namespaces_main.cpp` will be compiled and run through the autograder.

## Instructions

This is the first assignment that starts to make use of compiling multiple classes, making it an excellent place for us to start learning to use `make` to manage compilation for us! We will use `make` from here on out. 

For this drill, perform Step 0, then the replacement for Step 1, both provided below. *You may skip Step 2, it will not be graded.* Step 3 has one clarification, but otherwise follows the book. For Step 3, you should just use the old compilation commands (using `make` would require we use extra targets or subdirectories; extra work we won't bother writh right now!). 

`make` is a utility that automates checking that files have been compiled and only recompiling those that are needed. 

The `make` utility uses a file named `Makefile` in your top-level directory. An empty one has been provided for you, but you'll need to get it working before you do anything else. The `Makefile` tells `make` what classes you need compiled and linked to make your program run. Then, to compile, you only call `make` at the command line (rather than `g++ -std=`...). In general, programmers use `make` rather than relying on direct calls to a compiler and/or linker.

### Additional Reading to Prepare

You will highly benefit from coming into this with an understanding of `make`. We will explain along the way here, but you will likely find the [Makefile Tutorial](https://makefiletutorial.com) a handy resource and very worth reading before you do this assignment. Note that it uses C, rather than C++, so the exact commands are slightly different. 

### Step 0 (START HERE!!!)

As noted above, you'll start using `make` from this assignment onward. The autograder tests will invoke commands to `make` to compile your code -- no more complicated compilation command. You'll set this up through the steps here.

The explanation in Step 1 simply asks you to get the files compiled and running (with some suggestions on how to do so on Windows). Ignore those instructions, you'll be using `make` instead and follow the Step 1 we provided, below. For this part of the assignment, you'll write a `Makefile` to compile your code. There are dependencies specified in Step 1 of the assignment that you need to keep in mind here. 

*Before proceeding, read [Step 1](#step-1-replaces-step-1-in-the-text), below, then return here.*

1. A `Makefile` specifies a series of *targets*. A target specifies a file that the target will create / prepare / compile / etc. `make` is a general tool, so how the file is created via the target can be general. *For us*, and in many cases, a target is going to get a file ready for compilation or linking. Note that, very specifically, the name of the target is usually the name of the file that it produces!

    Each target also specifies one or more *dependencies* -- files that need to be up-to-date in order for the target to be run. Each dependency is another target somewhere in the same `Makefile`. This is how we handle multiple files that need compiling -- as we need in this assignment (and many future assignments)! When we run a target, `make` will check the dependencies for that target. If any of the dependencies are too old, it will re-run the dependencies first. (Of course, if any of those dependencies have dependencies, then those are checked as well... on down the line!)

    To specify a target, we write its name, followed by a `:`, followed by any dependencies with spaces between them. After that, a series of commands, each indented with one TAB character (*NOT SPACES!!!*), tells `make` how to produce the file in the target. 

1. Recall that targets are named after the file they produce. At a high level, we want to have a target for the last file we want to produce, which is, generally, the compiled output file that will run our `main()` function. This target is going to be dependent on any other files / targets we need to compile it. 

1. Now -- if we have our targets and their dependencies in place, how do we actually make use of things? At the terminal, we can run `make` followed by the name of the target that we want to be made. As a handy shortcut, simply calling `make` with no target will cause it to run whatever the first target in our `Makefile` is -- normal practice is that we write the first target to be the file that we want `make` to produce for us -- again, probably the one that has our `main()` in it. 

1. So let's make this concrete. In this assignment, you're working on three files: `my.h`, `my.cpp`, and `use.cpp`. One of those files -- `use.cpp` -- has a `main()` function. We've provided empty versions of `my.h` and `my.cpp`, but `use.cpp` has `main()` function right now. Note that, while we have sometimes let our applications be named `<some name>.out`, applications -- compiled code, programs, apps -- normally just do not have a filename extension (the little code after the `.` in the filename). 

    So, with all these things in mind, our final, compiled code with the `main()` function should be living in a compiled file named:

        use

    And, because of this, we should have a first target in our `Makefile` named `use`. We'll need some dependencies once we get going, but, for now, let's just get the first one down. Add the following to your `Makefile`, but take care that you actually have a TAB character in front of the commands (which you will not get if you copy and paste from here!):

        use:
          g++ -std=c++11 -o use use.cpp

1. Now, you can go to a terminal in the repo folder and run:

        make

    That will cause `make` to run and look for a file named `Makefile`. It will read `Makefile` and find the first target in there -- `use`. Then it will follow the commands for `use` -- in this case, use the `g++` compiler to compile `use.cpp` and produce a compiled application named `use`. You can, if you want, run the resulting file (as ever, run `./use`), but, unless you changed it, it will do nothing (but there won't be an error)! 

    Alternatively, you can also invoke your `use` target by calling `make` like this:

        make use

    This will cause `make` to run and look for a file named `Makefile` and scan it for a target named `use` (which you have). Then, as above, it'll run `use`. 

1. Assuming no errors up to now, run `make` (either with a default target or specifically running `use`) twice. The second time around, it should tell you:

        make: 'use' is up to date.

    The timestamps on the dependencies (none) are not different than those of `use`, so `make` is not going to bother re-running! Unfortunately, this doesn't much help us -- if we go and edit `use.cpp`, `make` still won't do anything unless we first delete `use`.

1. Most `Makefile`s include a `clean` target. The purpose of the `clean` target is to ensure that the latest code is fully compiled. It lets us, as the programmer, make absolutely sure that we are working wit the latest version of our software. For this, we'll need to use the terminal command `rm` -- remove (i.e., *PERMANENTLY* delete) a file. Add a `clean` target to your `Makefile`. It should go *after* `use:`, like so:

        use:
          g++ -std=c++11 -o use use.cpp 

        clean:
          rm -r use

    Now, you can clean up this project by calling:

        make clean

    This will delete `use` and the next time you `make`, the `use` target will be re-run and will recompile `use.cpp` into the application: `use`. 

1. But... about those dependencies... We know from the description that, once we work on Step 1, `use.cpp` is going to include `my.h` and that the implementation of `my.h` exists in `my.cpp`! We'll need to do a little more work to our `Makefile` to get this to work. I'll give you some of the structure here, but the rest will be up to you! 

    When we've compiled source files so far, they get turned into applications -- commands that we can run to invoke the `main()` function. That's not *always* the case though, some of our source code files just contain functions that other parts of our program need to run! These are object files -- usually with the filename extension `.o`. These object files need to be *linked* together to create our program. We supply them as arguments to our `g++` command. To make `g++` produce the object files, we should run it like:

        g++ -std=c++11 -c <name of the .cpp file we want to make an object file out of>

    So, what do we need? We need a `Makefile` that compiles `use.cpp` with `my.o`; we get `my.o` by compiling `my.cpp`. There's an ordering there -- a dependency! So, let's handle this in our `Makefile`! We'll add a dependency on `my.o` to our `use` target. Then, we (and by "we" I mean "you as part of your drill") need to define `my.o` and update `clean` accordingly:

        use: my.o
          g++ -std=c++11 -o use use.cpp

        my.o:
          *???*

        clean:
          rm -r use
          *???*

1. Now, if you've got this working right, you should be able to just call `make` when you want to compile this project. If it is up-to-date, you can call `make clean`, then `make` to force a recompile!

#### OPTIONAL -- Get your `Makefile` to work automatically

You can skip this section, if you want, but if you learn to use implicit rules, `make` will be able to automatically recompile only the parts of your code that need recompliation. Generally, you won't need to call `make clean` -- `make` will be able to assess if anything has changed since the last build and act accordingly. 

*Implicit rules* are commonly used and if you read `Makefile`s, you *have to* understand them. They render `Makefile`s hard to understand if you are not familiar. They also involve a lot of hardcoded assumptions about how compilation and linking work. At the same time, they allow you to vastly simplify your build and give you a little more power when it comes to automatically compiling everything. 

`make` is carefully designed with compiling and linking in mind, and so it can make some assumptions about your code and your intent. If you want to make your program, `use`, `make` can assume that the program `use` comes from `use.o`, which, in turn, comes from `use.cpp`. If you set your `Makefile`'s variables properly, then making `use` without any other files is as simple as defining your target as:

    use: use.o

If you invoke this target, `make` will go through and compile `use.o` from `use.cpp`, then link it to make `use`. *Even better*, if you edit `use.cpp`, it will compare the timestamps and automatically recompile it when you call `make`, without needing to call `make clean`!

We don't allow magic in this class, but `make` works with several assumptions. `make` defaults to assume everything is C, not C++, so we need to set our variables. We have to set up three of them. First, we need to set our C compiler variable, `CC` to use our C++ compiler, `g++`. For safety's sake, we'll do the same thing for our C++ compiler variable, `CXX` so that it is also `g++` (it should default to this, but we're being careful and explicit). Finally, recall that we need a flag set when we call `g++` on our own; we need `make` to know about this too, so we set `CXXFLAGS` to be `-std=c++11`. 

To get our basic `use` working, our `Makefile` should look like:

    CC = g++
    CXX = g++
    CXXFLAGS = -std=c++11

    use: use.o

But, recall that we still need to work with TWO source files... You'll need to complete this version of your `Makefile` such that it also compiles and links `my.cpp`. (Hint: you only need to add 5 additional characters.) You also need to add back the `clean` target, if you took it out, as the autograder will still need to call `make clean` on your submissions. 

### Step 1 (Replaces Step 1 in the text.)

(If you are here to read Step 1 as part of doing Step 0, here is a handy link back to the top of [Step 0](#step-0-start-here).)

Use the provided three files: `my.h`, `my.cpp`, and `use.cpp`. The header file `my.h` should contain:

    extern int foo;
    void print_foo();
    void print(int);

The source code file `my.cpp`:
+ `#include`s both `my.h` and `std_lib_facilities.h`;
+ defines `print_foo()` to print the value of `foo` using `cout`; and 
+ defines `print(int i)` to print the value of `i` using `cout`. 

In both of `print_foo()` and `print(int i)`, make sure that, when you print the value, you insert a new line (`endl` or `'\n'`) after the printed value!

The source code file `use.cpp`:
+ `#include`s `my.h` and
+ defines `main()` to:
  + set the value of `foo` to `7` and print it using `print_foo()` and
  + print the value of `99` using `print(int)`. 

Note that `use.cpp` does *not* `#include std_lib_facilities.h` as it doesn't directly use any of those facilities. 

Use your `Makefile` from Step 0 to get these files to compile and run!

### Step 2

Do not do Step 2.

### Step 3 (Modifies Step 3 in the text.)

For Step 3, we have provided two files, one you may edit and the other you may not. Working in `namespaces_xyz.cpp`, follow the directions in the book, but make sure that your `print()` functions include a newline character (`\n` or `endl`) -- the autograder will expect the output to be one print output per line. The autograder will use `namespaces_main.cpp` to compile and run -- do *not* edit it! Do not worry about a `Makefile` for Step 3, just compile it via the usual terminal command. 

## Grading

This assignment is worth 100 points, which are distributed as follows:

+ 20: Step 0.5 - `make` creates `use`
+ 20: Step 0.7 - `make clean` cleans up workspace
+ 30: Step 0.8 - `make` handles the dependency correctly
+ 10: Step 1 - `use` produces the correct output after being constructed by `make`
+ 10: Step 3 - `namespaces_main` produces the correct output after being compiled
+ 10: File Integrity - The scripts in `test_scripts/` and the source file `namespaces_main.cpp` have not been modified. 
