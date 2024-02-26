# Due: January 29

## Objectives:

   * Write simple recursive functions
   * Perform analysis on recursive functions
   * Observe the behavior that runtime has on performance.

## Starter files:

Starter files are available within your repository. 

## Part 1 - Recursive Programming

### Starter file details

* **lab2tester.cpp** will test your 3 functions.  it will compile even if your functions are wrong or empty but you won't pass testing.
* **lab2timing.cpp** is a separate main() program that is designed to help you look at the the timing for a function.  Once your program passes testing you can use this main() instead of the tester to get a timing value for a run of the fib() function.  Feel free to modify this file as you see fit to do your timing
* **timer.h/timer.cpp** these files allow you to time a small block of code.  NOTE: if you are on windows using VS, please remember to change the ```#define PLATFORM``` statement at the top of timer.h or it won't compile.

### Factorial Function:
* in the lab2.cpp file write the following functions **recusively**:

``` c++
unsigned long long factorial (unsigned int n);
```
This function returns n! (read n factorial). n! is calculating by multiplying every number between 1 and n:

n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1

Example:
factorial(4)

4! = 4 * 3 * 2 * 1 = 24

### Power Function:
* in the lab2.cpp file write the following function **recursively**:



``` c++
unsigned long long power (unsigned int base, unsigned int n);

```
This function returns base^n = base * base * base * ... * base   (n base values multiplied together)
Ex. 
power(2.0, 4) = 2^4 = 2 * 2 * 2 * 2 = 16


### Fibonacci Function:
* in the lab2.cpp file write the following function **recursively**:

``` c++
unsigned long long fibonacci (unsigned int n);
```
This function returns the nth fibonacci number in the fibonacii sequence (denoted Fn below)

*  F0 (fibonacci(0)) = 0
*  F1 (fibonacci(1)) = 1
*  F2 sum of F0 and F1 = 0+1 = 1
*  F3 sum of F1 and F2 = 1 + 1 = 2
*  F4 sum of F3 and F4 = 1 + 2 = 3
*  F5 sum of F4 and F5 = 2 + 3 = 5

## Part 2 - Analysis and Reflection:


* Add a file called **lab2.md** to lab2 folder of your lab repository
* Perform a full analysis of both the **power()** and **factorial()** function (**but NOT fibonacci()**).  That is for these two functions, find T(n) which represents the worst case complexity for these two functions.  State their upper bounds.  Please see https://catherine-leung.gitbook.io/data-strutures-and-algorithms/recursion/analysis-of-a-recursive-function on how to do a recursive analysis.
* Answer the following questions regarding the **fibonacci()** function (You do NOT need do an analysis of fibonacci()):
  1. Did you find it easier to write the recursive fibonacii() function or the iterative version?
  1. **Without performing a full analysis**
      * there is no right or wrong to this question ... just give it your honest best guess.  Its a hypothesis... **don't google for the answer**.  This is a hypothesis.  You do this then see if your observations support what you think.  Its ok to be wrong.
      * what do you think the runtime of your recursive fibonacci function is (stated with big-O notation)? 
      * Explain why you think this.
  2. Modify the file lab2timing.cpp to get a timing of running the fibonacci function. Record the time needed to run fib for n ranging from 21 to 45 inclusive (timing results for values smaller than 21 are pretty small but feel free to run and include them if you want).  Feel free to modify lab2timing.cpp however you want to get the data you need.
  3. Take the data you generated and create a line graph using a spreadsheet program such as google spreadsheet or excel.  The line graph should be organized as follows:
     * x axis represents n
     * y axis represents time
     * provide clear labeling and titles
     * place the image of the graph into your lab2.md file as part of your answer.  The easiest way to do this is to plot the graph using google spreadsheet and then use the built in sharing function and embedding functionality to create a link to the image for your lab2.md.  However, there are other ways and you are free to use whatever method you want as long as there is an image of the graph in your lab2.md.
  4. Given the timing, and your original guess, does the run time fit your original hypothesis?

## Challenge (Optional):

This section is completely optional.  You do not need to do it and it is worth no marks.  Do this as a challenge to yourself and to gain a deeper understanding of the course material.

The straight forward way to look at the power() function is to calculate base^n as base * base^(n-1).  Doing so would lead to an analysis that is similar to that of the factorial() function and lead to a runtime of O(n).

The challenge is to find a solution that is better than O(n).  Write the function and do an analysis to show that your solution is better than O(n).


## Submitting your lab

In order to get a mark for this lab, you must submit:
* a successful pull request (or push) of your lab2.cpp file into main branch with a successful build step
* your code via github in the main branch of your repo (in the lab2 folder)
* your analysis in a file called lab2.md added to your reo in the lab2 folder

Please make sure you follow the steps listed below fully

### A successful pull request or push of your lab2.cpp file into the main branch

This step is similar to what you did in lab1, just with lab2 files instead.


### Submitting your code/analysis and reflection on github

* submit lab2.cpp and if you did the challenge, the challenge file.
* Do not alter the structure of the files in your lab repositories in any way.
* Do not add extra folders.
* Do not add extra files.  
* Do not upload an entire VS solution.

  
All branches should be pushed to your private btp500 github repos (These were provided by completing lab 0).  **DO NOT** put it in your own public repo as  **that would violate academic policy (cheating)**

## Lab Rubric:

| Criteria | Poor - 0 mark | Fair - 0.5 marks | Good - 1 marks| 
|---|---|---|---|
| Lab Completion | Missing either a successful run with recursively written functions or analysis of recursive functions | Successfully written code and while there is an analysis/reflection it was poorly done with missing details  | A good attempt at completing all parts of the lab, may have some small flaws but a good effor had been made | 
