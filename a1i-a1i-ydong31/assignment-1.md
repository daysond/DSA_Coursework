# A1

## Due: February 19

### This assignment is worth 10% of your final grade

### Late penalties

* up to 1 week late - 10%
* 10% per day there after to a maximum of 50%

### Assignment Completion
For this assignment to be considered complete, you must submit the following:

* a successful pull request (or push) of parts 3 and 4 into the main branch with a passing test for each part.


Note: Assignment completion is the minimum requirement for your assignment to be considered complete.  It does not mean you will receive full marks.
Assignment completion is mandatory to pass the btp500.

## Assignment Objectives

In this assignment, we will be implementing 
*  a doubly linked list. 
*  draw diagrams of your implementation to gain a better insight into how this is accomplished.
*  write a more involved recursive function (separate the problem from the linked list)
*  analyze a more involved recursive function.

NOTE: **as this assignment is about implementing data structures, you are not allowed to make use of the standard library.**

## Repo Creation:

In this assignment, you can work independently or have ONE(1) teammate (work in pairs).  It is entirely your choice to work individually or in teams.  Decide what you want to do, then use the instructions below to create your repository.  Follow the instructions carefully.

* [Repo Creation for 1 person](https://github.com/seneca-btp500-w23/btp500-w23/blob/main/assignments/individual-repo-creation.md)
* [Repo Creation for teams of 2](https://github.com/seneca-btp500-w23/btp500-w23/blob/main/assignments/group-repo-creation.md)


Your team will last for only one assignment.  If you decide you cannot work together after assignment 1, you can find a new partner or work independently for the other assignments.
## Part 1: Drawings (5 marks)

Below are two files that contain diagrams for you to work through. Each diagram has a label indicating the operation to be performed to the linked list. The specification details of what each function does are listed in part 3. Use the appropriate starter file for your implementation. If you plan to implement part 3 using sentinels, then your diagrams should use sentinels. If you plan to implement part 3 without sentinels, then your diagrams should be done using the file without sentinels. Thus, your drawings should match your intended implementation. If you change your mind about how you want to implement, you must redraw the diagrams to match your implementation.


Read through the specifications. Modify the list to show what the result of the operation is. Be clear about what is changing and how. The diagrams need not be neat. But they need to be understandable. The idea is to think through what you need to change to achieve your goals.

### Starter files:

* [sentinel version of diagram file](dlist-sentinel.pdf)
* [non sentinel version of diagram file](dlist-nonsentinel.pdf)


## Part 2: Runtime estimate (4 marks)
In the a1.md file in your repo, you will find a header for Part 2.  There you will find a table listing some of the doubly linked list functions.  Think through the specifications and fill in what you think the optimal run time is for each of the functions listed.

## Part 3: (15 marks)

### Implement a template for a doubly linked linked list.
The basic class declarations can be found in 'dlist.h'.  Please use it as a starting point.  You are welcome to add whatever private/protected members you see fit. 
Nodes in this list will have a pointer not only to the next node but also a pointer to the previous node. 

The data type of the data stored in this list (T) supports the following operator:
* == 
* !=
* =
* <
This means that you can use any of the above operators on the data stored in the nodes of your doubly linked list. You do not need to implement these operators.  It is up to the program using the doubly linked list to implement these operators for the data type. 

The DList class has the following member functions:

```c++
DList();
```
* constructor, creates empty DList

***
```c++
iterator insert(iterator it, const T& data);
```
* adds new node containing ***data*** before the node refer to by ***it***
* function returns iterator to newly added node


***
```c++
iterator begin();
```
* returns iterator to Node containing the first piece of data in the list

***
```c++
iterator end();
```
* returns iterator to the Node ***after*** the node containing the last piece of data of the list


***
```c++
const_iterator cbegin() const;
```
* returns const_iterator to to Node containing the first piece of data in the  list

***
```c++
const_iterator cend() const;
```
* returns const_iterator to the Node ***after*** the node containing the last piece of data of the list


***
```c++
iterator erase(iterator it);
```
* removes the node referred to by ***it***
* returns iterator to node that follows the node that was removed


***
```c++
void sort(iterator first, iterator last);
```

* This function sorts all nodes from ***first*** to ***last***, including ***first*** but not including ***last***. This process must not create any new nodes or deallocate any old nodes.  Furthermore, the data within each node is not to be swapped around... the point is to be able to move nodes around to sort. **Recreating the list, using temporary arrays to sort or swapping data without moving nodes will be graded as incorrect and you will need to resubmit your assignment if you do this**

**For example:**

In the example below

Initial current list: {1, 3, 4, 8, 2, 4, 7, 3, 6, 5, 9, 10}, suppose that ***first*** refers to the node with 8, ***last*** refers to the node with 5. 

The function would sort the nodes with the bolded values:{1, 3, 4, **8,2,4,7,3,6,** 5, 9, 10}

The final list would end up with values in the following order: {1, 3, 4, 2, 3, 4, 6, 7, 8, 5, 9, 10}



***
```c++
iterator search(const T& data);
```
* returns iterator to the node containing data.  If data is not found, returns end()


***

```c++
bool empty() const;
```
* function returns true if the list is empty, false otherwise

***
```c++
int size() const;
```
* function returns number of pieces of data stored in the list

***
```c++
~DList();
DList(const DList&);
DList& operator=(const DList&);
DList(DList&&);
DList& operator=(DList&&);
```
* Your sorted linked list must also implement destructor, copy constructor, assignment operator, move constructor, move operator.


### Iterator

The idea of an iterator is to provide a means to traverse your class.  In the STL, different classes, like vectors or lists have iterators that help you iterate through your list.  For the sorted list, you will also write an iterator class.

You will need two iterators. A const_iterator and an iterator which is derived from const_iterator. For both operators, the following public members/operators are required. You are welcome to add any other private or protected members as you see fit:

```c
iterator();
const_iterator();
```
constructors, returns iterators to nullptrs


***
```c
iterator operator++();           //prefix ++
iterator operator++(int);        //postfix ++
const_iterator operator++();     //prefix ++
const_iterator operator++(int);  //postfix ++
```
* prefix and postfix ++ operator
* makes iterator point to the next node in the list.
* return as appropriate for each operator

***
```c
iterator operator--();           //prefix --
iterator operator--(int);        //postfix --
const_iterator operator--();     //prefix --
const_iterator operator--(int);  //postfix --

```

* prefix and postfix operator -- 
* increments iterator so that it points to previous node in list
* return as appropriate for each operator


***
```c++
bool operator==(const_iterator rhs); - function returns true if rhs and current object refer to the same node
bool operator!=(const_iterator rhs); - function returns true if rhs and current object does not refer to the same node
```

***
```c++
const T& operator*() const;   //in const_iterator
const T& operator*() const;   //in iterator
```
returns a const reference to data in the node referred to by the iterator.


***
```c++
T& operator*();  
```
returns a reference to data in the node referred to by the iterator.

## Part 4: Recursive functions (5 marks)
You are required to implement all methods recursively. **You receive a zero if there is any occurrence of a loop (e.g., for, while).**
- Do not use a loop. Use only recursion. Solutions using loop will not receive credit.
- Hint: For some of the recursive methods you may consider adding private recursive helper methods.

### Fibonacci sequence Problem:
Implement method ***fibArray*** returns an array storing the first `n` numbers in a Fibonacci sequence. The Fibonacci starts with the first two numbers being 1 and 1, then starting from the 3rd number, it is the sum of the previous two numbers. You can assume that `n` is positive. e.g., `fibArray(5)` returns an array `{1, 1, 2, 3, 5}`.

### Integer to Binary Problem:
Write a recursive function ***IntegerToBinary*** convert any decimal number `n > 0` and `n <= 65535` into a binary number, return an array represent the binary number. You can assume that `n` is positive.
a binary (base-2) number. A binary number is made up of one or more binary digits called bits. A bit has a value that is equal to either `0` or `1`.
```
Example:
IntegerToBinary (4)  return [0, 0, 1], where (0*1)+(0*2)+(1*4) = 4 
IntegerToBinary (9)  return [1, 0, 0, 1], where (1*1)+(0*2)+(0*4)+(1*8) = 9
IntegerToBinary (31)  return [1, 1, 1, 1, 1], where (1*1)+(1*2)+(1*4)+(1*8)+(1*16) =31
```



## Part 5: Analysis (6 marks)

**You are not allowed to use any part of the C++ Standard library for this part**


***
**3 marks**
```c++
int* fibArray(int n);
```

Perform an analysis of your implementation of the```int* fibArray(int n) ``` function with respect to the size of the input.  


***
**3 marks**
```c++
int* IntegerToBinary(int n);
```

Perform an analysis of your implementation of the ```int* IntegerToBinary(int n);``` function with respect to the size of the input.

## Part 6: Reflection (5 marks)

1. Write a paragraph or two about things you learned while working on this assignment.  Did you learn a new concept?  A new way to approach a problem?  What was helpful for you when you were trying to implement the coding portions?  What challenges did you face that you overcame?  

*If you are working with someone, you need to each write your own paragraph (please add your name to the header)*.  

## Assignment submission

Overview: 

* submit your drawings for part 1
* submit your estimates, analysis and reflection(parts 2, 5 and 6)
* submit the coding components via a github push or pull request to the main branch

### Submit your drawings

* add the appropriate diagram file that matches your intended implementation. replace the existing file with the updated diagram file and push into your repository

### Submit a test verification


In order for this assignment to be considered completed, you must submit:
* a successful pull request (or push) of your dlist.h and recursivemethods.cpp files
* your code via github in the main branch

Please make sure you follow the steps listed below fully

### A successful pull request or push of your dlist.h and recursivemethods.cpp files into the main branch

This step is similar to what you did in labs, just with part3 and part4 files instead.

### Submitting your code/analysis and reflection on github

* submit recursivemethods.cpp
* submit dlist.h
* update a1.md with parts 2, 5 and 6
* submit diagram file into the main branch without adding extra folders.
* Do not alter the structure of the files in your lab/assignment repositories in any way.
* Do not add extra folders.
* Do not add extra files.  
* Do not upload an entire VS solution.

  
All branches should be pushed to your private btp500-a1 github repository (These were provided by the link above in the repository setup section).  **DO NOT** put it in your own public repository as  **that would violate academic policy (cheating)**

### Submit your Analysis

Your analysis should be written inside a1.md 

## Late penalties

* up to 1 week late 10%
* 10% per day there after to a maximum of 50%

## Resubmissions

With the test verification system, there is very rarely a need to have you resubmit your program.  However, there are instances where the work may pass testing but still miss the point of the assignment entirely. In those cases, your work may need to be resubmitted.  Here are some examples:

* writing a recursive function iteratively
* alteration of repository that bypasses or alters the submission process. 
* writing a totally different data structure than specified (writing a vector type list instead of a linked list for example)
* writing a data structure in a manner that clearly demonstrates a lack of understanding of how the data structure works
* **using any STL container class or function**

Any work that is resubmitted, will receive an automatic 50% penalty. Any work with a grade of resubmit is considered to be not completed until it is submitted correctly.

## Coding Question Grading Breaking

Please see [style guide](https://github.com/cathyatseneca/Common/wiki/style-guide) for details on documentation and coding style

* Documentation - 20%
* Coding Style - 10%
* Memory Management - 20%
* Efficiency - 25%
* Completion and correctness of functions/functionality - 25% - Some aspects of some functions may not be tested by the tester.  Sometimes this is because it simply isn't possible (like destructors for example).  Thus, we reserve the right to read your program and take off marks for anything that does not work.

### Coding Question Rubric

| Criteria | Level 0 | Level 1 | Level 2 | Level 3 | Level 4 |
|---|---|---|---|---|---|
| **Documentation** - Documentation is about Intention.  "This function is suppose to do" X.  It doesn't state HOW "we loop, then there is an if, then ..." - this is an example of what not to do.  It doesn't repeat code.  For each function ensure that it describe what it does (at a high level), what it accepts as arguments and any sort of restrictions (number must be positive for example) and what the function should return under what condition (returns true if found for example) |Almost no documentation of any type |only a few functions got documented and documentation tends to be code description as opposed to code intention. | many function documentation missing or severe lack of details for function description or documentation is done only at code level (within the code) and not as an overall intention| a few functions documentation missing. or function description comments lack some detail.  Over documentation.  documenting every line of code is not a good... let the code speak | For all functions state what parameters are (and any limitations, what return value is, what it does. |
| **Code Styling** Consistent styling is key.  This category describes things like indentation, consistent naming strategies, good variable names, not adding public member functions etc. | more than 5 cases of inconsistent or bad styling | 3 to 5 cases of inconsistent  or bad styling | 2 to 3 cases of inconsistent or bad styling functions | 1 case of inconsistent  or bad styling | Consistency is key. same variable name styling (camel case pref), same data member styling, same curly bracket positioning, correct and consistent indentation, good variable names | 
| **Memory Management** - everything allocated must be deallocated.  Generally speaking the object that does the new, also must do the delete. Memory management looks at making sure that anything not used is properly freed.  It also looks at whether it is done by the correct object.  | 4 or more instances of memory leaks | 3 instances of memory leaks | 2 instances of memory leaks |1 instance of memory leak| no memory leaks|
|**Correctness and Completeness of Code**.  This category generally describes errors in logic or missing functionality in things that cannot be automatically tested. For example publicly declared data members or use of gotos and global variables all fall into this category.  | 4 significant error or missing code function | 3 significant error or missing code | 2 significant error or missing the code| 1 significant error or missing code | all functions completed and correct |
| **Efficiency** - Anything that is completely off from optimal run time will always count as an instance of inefficiency.. thus if runtime can be O(n) and your code is written to O(n^2). Writing unnecessary code will also be counted as inefficient even if runtime is same.. for example copying array more than 1 time during a grow() operation | 4 or more instance of inefficiency | 3 instance of inefficiency | 2 instance of inefficiency| 1 instance of inefficiency | Function is as efficient as possible |


### Analysis Rubric

 Criteria | Level 0 | Level 1 | Level 2 | Level 3 | Level 4 |
|---|---|---|---|---|---|
| Analysis | No analysis completed | Little to no explanation in analysis... arrives at final result as if by magic  | Lacks a significant component to analysis has one or more major errors or miscalculation within the analysis | Has minor errors or some minor missing steps in analysis  | Clearly laid out analysis with correct flow that shows how all mathematical expressions are obtained.  Clear and consistent usage of mathematical symbols.  Complete and clear count of operations |


### Reflection Rubric

 Criteria | Level 0 | Level 1 | Level 2 | Level 3 | Level 4 |
|---|---|---|---|---|---|
| Analysis | No reflection written | Reflection has no specifics with generic statements that can apply to anything | Reflection lacks depth, only a brief description without any details | Reflection shows some depth but writing does not show depth | A well written thoughtful reflection | 













