# Due January 22

## Objectives:

   * Perform analysis on simple functions

## Video:

This video shows you the lab/assignment submission process we use this semester: [lab/assignment submission video](https://web.microsoftstream.com/video/522c4c4c-c56a-4c4b-a3ee-dd9f638ed3d4)

## Setup

**BEFORE YOU BEGIN, complete [Lab 0](lab-0)**.  Lab 0 provides access to starter files for all labs.. as well as some basics on the tools you will be using this term.  It will be a good idea to review how to do the lab.

### Create an Issue:

Issues are a way to keep track of work you still need to do or comment on existing work.  Your lab repository has been set up with templates of task lists for each lab.  Use the lab1 template and create a new Issue.  As you complete your work, update the issue to remind yourself of what you still need to do

### Cloning your Repository

Clone your repository to your desktop or alternative you can use your codespace for the lab (see this video, if you didn't try it out in lab 0: https://web.microsoftstream.com/video/c3f41f80-94d1-4c9f-9e58-604de47bb2bb?list=studio).  Note that if you are working on your own machine and you have never used git/github before, there is a significant setup step that involves getting a git client and going through the security steps.  It will take some time to do, but it may be worthwhile so that you can have a familiar development environment.

## Part 1: Git, Github and Coding

Learning how to use git/github properly is a skill that employers are expecting at this point.  The programming tasks for this lab is not very difficult.  Pay close attention to the git/github steps.


In the task descriptions below:
  * write the functions in an **iterative manner** (**use loops, no recursion allowed**)
  * add the function to your repository into a branch called lab1working.
  * write an analysis for each of the the three functions
  * update the issue as you complete each task


## Git basics:

* go into the repository folder 
* create the lab1working branch (git branch lab1working)
* change into the branch (git checkout lab1working)
* go into the lab1.cpp file and put your name and student number in the comment using whatever is your favorite editor
* add, commit and push your file into your lab1 working branch:
   * ```git add lab1.cpp```
   * ```git commit -m "added name and student number"```
   * ```git push origin lab1working```

* verify that this is correct by doing the following:
    * Go to your repo via the web browser
    * switch branches using the  branch drop down that says main, you should see an option for a branch named lab1working.
    * Click into the lab 1 folder and the lab1.cpp file and you will see lab1.cpp with your name and student number in it.

* update the issue to indicate the task is completed


## Factorial Function:

* in the lab1.cpp file write the following function:

``` c++
unsigned long long factorial (unsigned int n);
```
This function returns n! (read n factorial). n! is calculating by multiplying every number between 1 and n:

n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1

Example:
factorial(4)

4! = 4 * 3 * 2 * 1 = 24

### Testing your function

* compile your program:  (g++ lab1.cpp lab1tester.cpp)
* run tester (a.out)
* there should be no errors for factorial() function.
* there will be errors for power() and fiboannacci() functions at this point.. this is expected as you haven't written it yet.

### Backing up partially completed work:

Once its completed and passes testing, update the file in lab1working branch:
* ```git add lab1.cpp```
* ```git commit -m "factorial function completed"```
* ```git push origin lab1working```
* update the issue

Once you push to your remote repository on github you have created a backup of your work.  Thus if anything were to happen to your local copy you would still have a copy in your repository.

Yous should make it a habit to backup after you complete some task within your lab/assignment.  

## Power Function:
* in the lab1.cpp file write the following function:

``` c++
unsigned long long power (unsigned int base, unsigned int n);
```
This function returns base^n = base * base * base * ... * base   (n base values multiplied together)
Ex. 
power(2.0, 4) = $2^4 = (2)(2)(2)(2)= 16$

### Testing your function

* compile your program:  (g++ lab1.cpp lab1tester.cpp)
* run tester
* there should be no errors for factorial() or power() function.
* there will be errors for fiboannacci() functions at this point.. this is expected as you haven't written it yet.

### Backing up partially completed work:

Once its completed and passes testing, update the file in lab1working:
* ```git add lab1.cpp```
* ```git commit -m "power function completed"```
* ```git push origin lab1working```
* update the issue


## Fibonacci Function:
* in the lab1.cpp file write the following function:

``` c++
unsigned long long fibonacci (unsigned int n);
```
This function returns the nth fibonacci number in the fibonacii sequence (denoted Fn below)

*  F0 (fibonacci(0)) = 0
*  F1 (fibonacci(1)) = 1
*  F2 sum of F0 and F1 = 0+1 = 1
*  F3 sum of F1 and F2 = 1 + 1 = 2
*  F4 sum of F2 and F3 = 1 + 2 = 3
*  F5 sum of F3 and F4 = 2 + 3 = 5

### Testing your function

* compile your program:  (g++ lab1.cpp lab1tester.cpp)
* run tester
   * If your program takes a long time to run after adding fibonacci function, it probably means you wrote it recursively.  Make sure you write all functions for this lab iteratively!
* there should be no errors now.

### Backing up partially completed work:

Once its completed and passing testing, update the file in lab1working:

Once its completed, update the file in lab1working:
* ```git add lab1.cpp```
* ```git commit -m "fibonacci function completed"```
* ```git push origin lab1working```
* update the issue


## Pull Request

Once you are happy with your code and you are ready to submit the code for the lab, you will need to complete a ***Pull Request*** or PR for short.  This is different from previous semesters where you submitted on matrix.  A PR on github merges the code from a branch like lab1working back into your main branch.  During this merging process, it will build and test your code. 

***

As you were pushing your code into lab1working branch , you may have noticed a the following when you looked at your repo on github:

![](https://user-images.githubusercontent.com/1699186/132410214-faba1dec-7a02-435f-9980-80a2863ea6e1.png)

To begin the PR, click that button.  If you do not see this button, go to the Pull Request tab in your repository and click the "New pull request" button

***

This will bring up a page that looks like the following:

![](https://user-images.githubusercontent.com/1699186/132411770-5b5bd298-9922-4286-a376-b3b4448a7dcd.png)

Make sure that you are pulling to main from lab1working.  Feel free to update the title to something like lab1 completed.  

***

Once you hit the button to Create pull request you will see something like the following show up... note that the yellow circle on top will take a second or two longer to show than the green check under it:

![](https://user-images.githubusercontent.com/1699186/132412941-6677b34e-4b44-4a53-93f5-53e629a2d9e6.png)

The top check (yellow circle) is an indicator of build process... essentially compiles your code and runs the tester.  If it is successful, it turns into a green check. If it fails it turns into a red x.  

***

If the build step succeeds, you will eventually see this:

![](https://user-images.githubusercontent.com/1699186/132413791-527e57a0-cd80-433e-bbb7-095a581f33a4.png)

The merge pull request button will be green.  Hit this button to complete the pull request.

***

If some part of the build process fails you will see something that looks like this:

![](https://user-images.githubusercontent.com/1699186/132412102-df90d210-2dcd-408e-a3b0-b649055be575.png)

***

To look into why, hit the details button to see the part of the build process that failed

![](https://user-images.githubusercontent.com/1699186/132414083-9a5c2675-2336-44ae-a343-6e82a91befab.png)

***

If your build process fails, simply fix the error in your local repository and push it back into your working branch without closing the pull request.  By updating your working branch with the fix, the pull request will update with the latest submission.

Doing a pull request is probably an overkill for labs.  However, for assignments where you are working on the same code base with another person, using pull request is a good way to work together without stepping on each others toes too much.  After lab1, if you wish to just push your files directly into your lab that is fine.

## Part 2: Analysis

Add a file called **lab1.md** into your repository.  Putting the file in the repository makes it possible to use LaTex and have it rendered properly.

### Find worst case complexity for your functions

* For each of the above functions (factorial(), power() and fibonacii()), perform an analysis of your function and state the upper bound of T(n) for each of your function using big-O notation.  An analysis is a step by step explanation of how you come to your conclusion, as such you will need to perform all steps of the analysis and not simply arrive at an answer.  Please refer to this example on how to do so:
 
https://catherine-leung.gitbook.io/data-strutures-and-algorithms/algorithms-analysis/how-to-do-an-analysis-in-5-steps

(note that you don't have to actually list off or number the 5 steps.. but you need to follow them... do all 5 steps)

### Analyze the following

*  Analyze the following bubbleSort() function with respect to the size of the array.

``` c++
void bubbleSort(int arr[],int size){
    int tmp;                          
    for (int i=0; i<size-1; i++) {      
        for (int j=0; j<size-1-i; j++){   
            if (arr[j+1] < arr[j]) {    
                tmp = arr[j];             
                arr[j] = arr[j+1];        
                arr[j+1] = tmp;           
            }
        }
    }
}

```
### Update your issue

## Challenge (Optional)

This last part is completely optional and is not required for the lab.  This is an offer to challenge yourself and work to gain a deeper understanding of course material.

Consider the problem described here:

https://adventofcode.com/2020/day/1
Download the data from the problem (the data file changes depending on login name)

A rudimentary starter file has been created that will read the data from the file is in the repository (so you don't have to worry about writing code to do the file I/O).  In that starter file, other than the main and file reading function, you will find the following empty function that you will need to code:

```c++
unsigned int challenge(unsigned int data[], unsigned int numData, unsigned int goal);
```
* **data** is the array of numbers
* **numData** is the size of the array
* **goal** a goal value that we wish to find a pair of values to sum to.

This function finds the two values in the array **data** that sum to **goal** and returns their product.  NOTE: the problem described only requires a sum to a specific goal value of 2020... but this change makes things more interesting...

* Solve the problem by writing the above function
* Analyze your solution

## Submitting your lab

In order to get a mark for this lab, you must submit:
* a successful pull request with a successful build step
* your code via github in the main branch of your repo (in the lab 1 folder)
* your analysis in a file called lab1.md in your course repo 
* a closed issue on github

Please make sure you follow the steps listed below fully

### a successful pull request with a successful build step

See the pull request section in part 1 of this lab.  You can see all attempted builds in the action tab. You should see a green checkmark with Lab 1:....

in the description to the main branch.

![](https://user-images.githubusercontent.com/1699186/132458839-f44495c7-c8bf-4a49-bcb0-da4f598b7196.png)

### Only submit the labs files

* submit lab1.cpp and if you did the challenge, the challenge file.
* Do not alter the structure of the files in your lab repositories in any way.
* Do not add extra folders.
* Do not add extra files.  
* Do not upload an entire VS solution.
  
All branches should be pushed to your private btp500 github repos (These were provided by completing lab 0).  **DO NOT** put it in your own public repo as  **that would violate academic policy (cheating)**


## Lab Rubric:

| Criteria | Poor - 0 mark | Fair - 0.5 marks | Good - 1 marks| 
|---|---|---|---|
| Lab Completion | Missing a either working code (successful PR) or Analysis/reflection.  Both must be completed to get any marks | Successful PR but Reflection/analysis is incomplete or lacks detiails | A good attempt at completing all parts of the lab, may have some small flaws | 
