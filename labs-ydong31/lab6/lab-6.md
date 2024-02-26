# Due: March 19

## Objective:

- Learn how to deep watching a video.  When you watch technical videos, there will be terminology and ideas that are difficult to understand.  This lab will have you slowly watch a video and understand what is being said.
- Reproduce results of a talk

## Tasks:

You may work in a group of up to 3 people if you want.  If you choose to do this, ensure that you put the name of all 3 team members into your lab6.md file as well as into a comment in your lab6.cpp file.  **Each member must submit their own copy of the work but the answers can be the same.**

1) Watch the following video: [Sorting Algorithms: Speed Is Found In The Minds of People - Andrei Alexandrescu - CppCon 2019](https://www.youtube.com/watch?v=FJJTYQYB1JQ)

2) Answer the questions in the next section,  You can use the Internet to help you learn about ideas that you are unfamiliar with, but you will need to link and cite your sources of information.  A link is provided that may be useful for you at bottom of this lab.

3) Replicate the experiment

4) Answer some questions about what you did

## Part A: Questions about video

Create a file called lab6.md and add that file to your lab repository in the lab6 folder.  Place all your non-coding components into this lab.  Do not forget to add names (and email addresses) of all group members to top of file if you are working in a group.  Suggestion, read questions first... then start watching video a few mintues at a time.  Pause and write down your answers.  Do this as a group at the same time.  Discuss what you are watching.

1. What sorting algorithm was the speaker trying to improve?
2. At what partition size does VS perform a simpler sort algorithm instead of continuing to partition?
3. At what partition size does GNU perform a simpler sort algorithm instead of continuing to partition?
4. Regular insertion sort does a linear search backwards from end of array for correct spot to insert.  According to the speaker, why does switching to a binary search not improve performance?
5. Describe what is meant by branch prediction? (this may require further research)
6. What is meant by the informational entropy?
7. If size == 15, what is size & 1?  if size == 16, what is size & 1?  Explain how right = first + 1 + (size & 1) avoids a conditional check. (hint, & is the bitwise AND operator in C/C++.  It takes the bit representation of the two operands and perform an AND operation on each of the corresponding bits to form a final value)
8. Speaker suggests the following algorithm:
	* make_heap()
	* unguarded_insertion_sort()
	
	He suggests that by doing make_heap() first, you can do something called unguarded_insertion_sort().  Explain what is unguarded_insertion_sort() and why it is faster than regular insertion sort.  How does performing make_heap() allow you to do this?
10. The speaker talks about incoperating your conditionals into your arithmetic.  What does this mean?  Provide an example of this from the video and explain how the conditional is avoided.
11.  The speaker talks about a bug in gnu's implementation.  Describe the circumstances of this bug.
12.  The speaker shows several graphs about what happens as threshold increases using his new algorithm.  The metric of comparison is increased, the metric of moves are increased but time drops... What metric does the author think is missing?  Describe the missing metric he speaks about in the video.  What is it measuring?
13.  What does the speaker mean by fast code is left leaning?
14.  What does the speaker mean by not mixing hot and cold code?

## Part B: Replication

In this part of the lab, you will replicate a part of the experiment in the video.  In particular you will replicate the modification to the insertion sort algorithm. In the file lab6.cpp you will find two copies of the insertion sort function.  The code is unmodified.  Modify the version called insertionSortModified.  Do this by implementing a make_heap() function and modifying the insertionsort code to an unguarded insertionSort that starts by inserting starting with 3rd element.  You may base your implementation of make_heap() from the code shown in the video.  Please cite.  You are not allowed to use STL functions/classes

For each data shape, time the two insertionsort algorithms (modified and unmodified) at array sizes 8, 16, 32, 64, 128, 256, 512 and 1024.  Record these times and create a graph for each data shape.  Each data shape must be graphed separately.  Each graph should show the results for both modified and unmodified insertion sorts.  Use an appropriate graph type to plot your results.

Note: if you are working in a group, make sure that you don't use different hardware when comparing the unmodified/modified sort routines (in otherwords, break the work up by data shape, not by modified vs unmodified)

## Part C: Reflection

1. Did you/your team do all the micro optimizations described?  If not, which did you do?  Which did you not do?
2. What did you/your team find most difficult to understand in the video?


### References:

You may find these articles on branching and cache useful:

https://en.algorithmica.org/hpc/


## Submitting your lab

In order to get a mark for this lab, you must submit:
* answers to all questions in Part A in lab6.md

**Each member of team must submit their own copy of the lab into their lab repos.  The write up can be the same but each person must submit a copy of it.  You must put down name of every member of team into your  file**



## Lab Rubric:

| Criteria       | Poor - 0 mark     | Fair - 0.5 marks                                                                                                                     | Good - 1 marks                                                              |
| -------------- | ----------------- | ------------------------------------------------------------------------------------------------------------------------------------ | --------------------------------------------------------------------------- |
| Lab Completion | No part completed | Answers in part A are completed but with either no graphs or severe errors in graph/experiment OR, answers in part A are vague and unclear but experiment and graphs were well done | Both part A was well answered and graphs were created correctly to spec|
