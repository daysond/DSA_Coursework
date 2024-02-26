## Due: February 5

## Objectives:

* complete the implementation of a basic doubly linked list
* explore the use of sentinel nodes

## Starter file:

* [drawing templates for linked lists](../blanklldiagrams.pdf)
* lab3.h (in repo)
* lab3tester.cpp (in repo)
 

## Part 1: Coding of doubly linked list:

Complete the push_front(), push_back(), pop_front(), pop_back() and destructor functions for a DList class.

## Part 2: Coding of a Sentinel Linked list

Sentinel nodes exist at the front and back of a linked list that stores no data. They always exist even when the list is empty. Their purpose is to simplify implementation. When inserting into a list with sentinel nodes, the data nodes go between the sentinels. Thus the first node with data is the second node in the linked list. Due to their existence, functions can be greatly simplified. Complete the push_front(), push_back(), pop_front(),pop_back() and destructor functions for Sentinel class

## Submitting your lab

In order to get a mark for this lab, you must submit:
* a successful pull request (or push) of your lab3.h file into main branch with a successful build step
* your code via github in the main branch of your repo (in the lab3 folder)

Please make sure you follow the steps listed below fully

### A successful pull request or push of your lab3.h file into the main branch

This step is similar to what you did in lab1, just with lab3 files instead.


### Submitting your code on github

* submit lab3.h
* Do not alter the structure of the files in your lab repositories in any way.
* Do not add extra folders.
* Do not add extra files.  
* Do not upload an entire VS solution.

  
All branches should be pushed to your private btp500 github repos (These were provided by completing lab 0).  **DO NOT** put it in your own public repo as  **that would violate academic policy (cheating)**

## Lab Rubric:

| Criteria | Poor - 0 mark | Fair - 0.5 marks | Good - 1 marks| 
|---|---|---|---|
| Lab Completion | Successful PR with successful build not submitted or code submitted but analysis and reflection component is missing | Successful PR but Reflection/analysis is incomplete or lacks detiails | A good attempt at completing all parts of the lab, may have some small flaws | 