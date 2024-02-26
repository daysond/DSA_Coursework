## Due: February 12

## Objectives:

* Implement iterators on a doubly linked list

## Starter file:

* [drawing templates for linked lists](../blanklldiagrams.pdf)
* lab4.h
* lab4tester.cpp

## Part 0:

Copy your push_front()/destructor functions from lab3.h into lab4.h

## Part 1: iterators and const_iterators:

The concept of an iterator is to provide uniform access to the container class WITHOUT revealing the underlying implementation of the container itself.  For example, if you consider how you would go through a vector or a list from the C++ Standard Library, you would find that the method is actually pretty much identical regardless of whether you are using a vector or a list:

```c++

vector<int> v;
vector<int>::iterator it;

for(it=v.begin();it!=v.end();it++){
   std::cout << *it << std::endl;
}
```

In the above, prints every item in a vector from the beginning to the end.  The loop to go through and print every item in a list would actually be exactly the same apart from the declaration of the list and iterator.   In this lab you will add support for both an iterator and a const_iterator for our DList and Sentinel classes.

A simplified version of the DList and Sentinel classes (containing only push_front) has been implmented in lab4.h.  This goal of this lab is to implement an iterator and const_iterator for the class.

To support this add the following functions to each of DList and Sentinel classes:

```c++
iterator begin();
const_iterator cbegin() const;
```
These functions returns an iterator/const_iterator to the first node in the list, end() if list is empty.

```c++
iterator end();
const_iterator cend() const;
```
these functions returns an iterator/const_iterator to the node just ***after*** the last node in the linked list.

### Iterator/const_iterator classes

The const_iterator and iterators must support the following operations:
***
```c++
bool operator==(const_iterator rhs); - function returns true if rhs and current object refer to the same node
bool operator!=(const_iterator rhs); - function returns true if rhs and current object does not refer to the same node
```

***
```c++
iterator operator++();           //prefix ++
iterator operator++(int);        //postfix ++
const_iterator operator++();     //prefix ++
const_iterator operator++(int);  //postfix ++
```
iterator advances to next node in list if iterator is not currently at end().  The iterator returned depends if it is prefix or postfix.  prefix operator returns iterator to current node.  postfix operator returns iterator to node before the increment.  

***
```c++
iterator operator--();           //prefix --
iterator operator--(int);        //postfix --
const_iterator operator--();     //prefix --
const_iterator operator--(int);  //postfix --

```
iterator refer to the node "previous" to the linked list.  The iterator returned depends if it is prefix or postfix.  prefix operator returns iterator to current node.  postfix operator returns iterator to node before the decrement.

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

## Submitting your lab

In order to get a mark for this lab, you must submit:
* a successful pull request (or push) of your lab4.h file into main branch with a successful build step
* your code via github in the main branch of your repo (in the lab4 folder)


Please make sure you follow the steps listed below fully

### A successful pull request or push of your lab4.h file into the main branch

This step is similar to what you did in lab1, just with lab4 files instead.


### Submitting your code on github

* submit lab4.h
* Do not alter the structure of the files in your lab repositories in any way.
* Do not add extra folders.
* Do not add extra files.  
* Do not upload an entire VS solution.

  
All branches should be pushed to your private btp500 github repos (These were provided by completing lab 0).  **DO NOT** put it in your own public repo as  **that would violate academic policy (cheating)**

## Lab Rubric:

| Criteria | Poor - 0 mark | Fair - 0.5 marks | Good - 1 marks| 
|---|---|---|---|
| Lab Completion | Successful PR with successful build not submitted or code submitted but analysis and reflection component is missing | Successful PR but Reflection/analysis is incomplete or lacks detiails | A good attempt at completing all parts of the lab, may have some small flaws | 
