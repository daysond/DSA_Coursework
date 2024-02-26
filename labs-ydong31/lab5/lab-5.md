# Lab 5

# Due: February 19

## Objectives:

- Learn how sorting works

## Setup

* get the file [lab5.md](lab5.md) and add it to your lab repository.  You will fill it in as you go.


* The active part of the lab is done in person in lab.  You must be there in order to do the lab to get the marks for the rest of the lab as it is based on observations of what you did in the lab class.


## Learning to sort:

### Setup

* Your professors will give you a piece of paper with 16 numbers separated by lines.  

* Form teams of 3 students that all have different coloured papers.
	* If the class does not evenly divide, it is OK to have teams of two.  There should be no more than 2 teams of two in the class.

* Fold and tear apart the paper along the lines, forming 16 numbered papers
* each team should get their own work area that will allow them the ability to spread out the little pieces of paper in a linear fashion.  
* clear the table of computers as much as possible.

### The Simple Sorts

* As a group review the algorithms for bubble sort, insertion sort and selection sort
https://catherine-leung.gitbook.io/data-strutures-and-algorithms/sorting/simple-sorts

* Assign one of these sort to each team member. (for teams of two work together on the last one)
* Each team member will demonstrate how their assigned sort works using their 16 pieces of numbered paper.
	* lay out all 16 pieces of paper on table in front of you in a row
	* perform the sorting algorithm on the paper to sort them ascendingly
* Help each other out on this, correct misconceptions as you go through the sorts.
* As a group discuss the following and note it in your lab5.md file
	* which algorithm did you find easiest to understand?
	* which algorithm seemed to fastest for completing the sort?


### Merging lists

For teams of two pick up an extra set of numbers from your prof.  Make sure its different coloured than the ones you have.

#### Merging unsorted lists

* have each member of the group lay out their papers in a row but keep them unsorted... that is you should have 3 rows of 16 number each.  All easily visible but not sorted
* have one member start a timer on one of their devices (phone, computer.. doesn't matter)
* create one new merged list by picking out the smallest values.
* Note the following in your lab5.md file
	* how long did this take
	* did you make any mistakes along the way (chose the wrong number)? How many times? 

#### Merging sorted lists

* repeat the above but instead of laying out the papers in 3 unsorted rows, **sort each row first**.  That is you should have 3 rows of 16 numbers, in sorted order
* repeat this merging and time how long it took.
* Note the following in your 
	* how long did this take
	* did you make any mistakes along the way (chose the wrong number)? How many times? 

### Lists Partitioning

For teams of two, use all 3 sets of numbers.

#### Sorting many numbers

* Take all the number papers for your team and mix it up forming a pile of numbered papers
* Have each team member then tries to sort all the papers however they like and time the result (mix up the numbers after each round so that everyone starts with randomly ordered values)
* Record how long it took each team member to get them sorted
	* Record the fastest time
	* Describe how the team member sorted them


### Partitioning

* Take all the numbers for your team and mix it up again
* partition the pile:
	* Time how long this process takes
	* have someone pick a random paper to serve as the "pivot" put that paper on table clearly away from pile
	* go through pile and place all numbered papers that are smaller to the left of the pivot, and all bigger to the right of the pivot.  These can still be piled up.
	* repeat one more time with these two smaller piles (unless there were 5 or few papers in the pile, in which case apply a patition only the bigger half, then out of the two new piles apply the partitioning one more time to the bigger one (if they are about the same pick any one and do it)
* If this was correctly done, you should end up with 4 piles of numbers separated by 3 pivots  It is possilbe that to have empty piles.  This is fine..it means you have one less pile to deal with in the next step.
* Record how long did the partitioning took


### Sorting small piles

* At this point, have the fastest sorter in your team separately sort each of the little piles. 
* By doing this, you should have a fully sorted set of numbers
* Record how long it took to do this


## Come up with the fastest way to sort

* As a team discuss things that helped soft the papers... what was useful? what was fast to do?  What was slow?
* As a team come up with a description of how best to sort a set of numbers on paper.
* Mix up all your numbers and have each member of the team perform the sort you did.  How long did it take?


## Submitting your lab

In order to get a mark for this lab, you must submit:

* lab5.md
* this file should list all your group members
* all the timings
* all observations and discussions


## Lab Rubric:

| Criteria       | Poor - 0 mark     | Fair - 0.5 marks                                                                                                                     | Good - 1 marks                                                              |
| -------------- | ----------------- | ------------------------------------------------------------------------------------------------------------------------------------ | --------------------------------------------------------------------------- |
| Lab Completion | Not completed | Missing timings or discussions | All timings recorded, all discussions recorded |
