[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8300963&assignment_repo_type=AssignmentRepo)
# PPP-Drill-03-modified-Interactive-Letter-Writer
Modified version of Drill for Chapter 03 from Programming: Principles and Practice

## Instructions

Follow the process outlined here, rather than the one in the text. You will find the instructions reference the chapter, and you will need to look at it to complete the assignment. You may also just find that the text is very helpful in figuring all of this out. 

The `std_lib_facilities.h` header file is included in this template so you will have ready access to it. The script file `err_catch.sh` is used for testing if your code is properly using exceptions -- DO NOT MODIFY IT.

After each step of this drill, run your program to make sure it is really doing what you expect it to. Keep a list of what mistakes you make so that you can try to avoid these in the future. 

## How the Assignment Will be Graded

Test cases will be based on the steps below using the GitHub Classroom autograding. The autograder will expect you to update the README.md as specified, use any syntax expressly noted in the assignment, and will scan the output for outputs that are specified in this document, nothing more. To run your program, it will first compile it with something like:

`g++ -std=c++11 form_letter.cpp -o <name>.out`

Then will run the resulting file with something like...

`./<name>.out`

...and supply responses to the prompts in the following order:

    <name of the person to whom the letter is written>
    <name of the mutual friend>
    <pronouns of the mutual friend>
    <age of the person to whom the letter is written>

This follows the order below. If you ask the questions in a different order, the autograder will not pass your code.

Where text is in quotes, it's expected to be copied over verbatim (with variables substituted, as noted). The autograder will check against the quoted text in many cases. 

For example, when checking for step 4, if the second input value (`<name of mutual friend>`) is `Rime` and the third input value (`<pronouns of the mutual friend>`) is `z`, then the program must have the following as part of the output:

`If you see Rime please ask zir to call me.`

If you alter the quoted sections, the test will not pass. So the above is fine, but things like:

`If you catch up with Rime, please ask zir to ping me.`

`Rime's my good good bud I wonder what ze are up to.`

etc., while following the spirit of letter-writing, will not pass the testing!

## Certification of Work Done

There are seven steps to the assignment. As you complete them, check them on here by adding an `x` inside the squares. (So, change the `[ ]` to `[x]` -- note that variations on this do *not* work!). The autograder will check for this! If you consulted any sources (students, web resources, books, etc.), note them at the prompt at the bottom.

- [x] 1. Update the salutation for a friend.
- [x] 2. Add some introductory lines.
- [x] 3. Ask the user for a mutual friend's name and comment on them.
- [x] 4. Get the mutual friend's pronouns and respond appropriately.
- [x] 5. Get the friend's age and error out for bad inputs. 
- [x] 6. Add commentary on the friend's age. 
- [x] 7. Add the closing. 

Outside resources that were used: 

## Activities to Perform

Note that the use of whitespace is very particular in this program. You should have a salutation; an indented, single-paragraph body; and a closing. *All sentences should have a space after their punctuation!* Follow the specification below to pass all the tests!

The assignment goes step-by-step, but you'll need to first ask the user for the data you need. Once you've collected all of the data, produce the letter based on the specification at each step. 

*To be clear: you should not print anything from the letter until you have collected all the data.*

1. This drill is to write a program that produces a simple form letter based on user input. The code from Section 3.1 is included in this template for you to work from. This program takes in a variable `first_name` from the user. Modify the code as follows: change the prompt to "Enter the name of the person you want to write to" and change the output to "Dear `first_name`,". Don't forget the comma!

2. Add an introductory line or two, like "How are you? I am fine. I miss you." Be sure to indent the first line (hint: the control character `\t` inserts a tab!). Add a few more lines of your choosing -- it's your letter. 

3. Now prompt the user for the name of another friend, and store it in `friend_name`. Add a line to your letter: "Have you seen `friend_name` lately?"

4. There are many issues for many people in the world because software has not been developed inclusively or with a diverse set of interests. The original version of this assignment includes such a failure. We don't have the tools right now to do this piece completely inclusively, but we can do better than the textbook! More insights on how to build inclusive software can be found through the [HCI Guidelines for Gender Equity and Inclusivity](https://www.morgan-klaus.com/gender-guidelines.html). 

	To *really* do this properly, we should allow the user to enter an arbitrary set of pronouns, not just choose from predefined options. For now, we'll do our best.

	Declare a `char` variable called `friend_pronouns` and initialize its value to 0. Prompt the user to enter:

	* a `z` for ze / zir
	* a `t` for they / them
	* an `s` for she / her
	* an `h` for he / him

	Assign the value to the variable `friend_pronouns`. Then use four `if`-statements, do not use `else`, as you will most likely get something wrong! Make your program write the following:

	* If the friend uses ze / zir, write "If you see `friend_name` please ask zir to call me."
	* If the friend uses they / them, write "If you see `friend_name` please ask them to call me."
	* If the friend uses she / her, write "If you see `friend_name` please ask her to call me."	
	* If the friend uses he / him, write "If you see `friend_name` please ask him to call me."

5. Prompt the user to enter the age of the recipient and assign it to an `int` variable `age`. Check the age and respond appropriately. 

	* If `age` is 0 or less or 150 or more, call `simple_error("you're kidding!")` using `simple_error()` from `std_lib_facilities.h`.
	* If `age` is between 0 and 150, have your program write "I hear you just had a birthday and are `age` years old." 

6. Add this to your letter:

	* If your friend is under 12, write "Next year you will be `age+1`."
	* If your friend is 17, write "Next year you will be able to vote."
	* If your friend is over 70, write "I hope you are enjoying retirement."
	
7. Make sure there is a blank line (the first `\n` will end the current line; you'll need `\n\n` to get a full blank line), add "Yours sincerely," followed by *two* blank lines (most likely needing `\n\n\n`!) for a signature; followed by your name. 

## Example Output 

The following is not exhaustive, but shows a successful run of the software (your output will likely wrapped to the window, but the way GitHub markdown works, you'll need to scroll to the right to read the whole thing): 

    Dear Zelda,
        How are you? As ever, I'm doing alright. A bit burned out. I miss you! Have you seen Link lately? If you see Link please ask zir to call me. I hear you just had a birthday and are 100 years old. I hope you are enjoying retirement. 
    
    Yours sincerely,
    
    
       Phœbe T. D.
