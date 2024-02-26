Group Members
| Names | email |
|---|---|
| Yiyuan Dong | ydong31@myseneca.ca |
| Kannav Sethi | kannav.sethi@senecacollege.ca |
| Dennis Audu | daudu@myseneca.ca |

# Part A
What sorting algorithm was the speaker trying to improve?
- Insertion sort

At what partition size does VS perform a simpler sort algorithm instead of continuing to partition?
- 32

At what partition size does GNU perform a simpler sort algorithm instead of continuing to partition?
- 16

Regular insertion sort does a linear search backwards from end of array for correct spot to insert. According to the speaker, why does switching to a binary search not improve performance?
- Binary increases the pessimization of the run time by 13% 

Describe what is meant by branch prediction? (this may require further research)
- Branch prediction is a way used to improve a processor by reducing number of stalls caused by branch instruction, 
    it entails predicting the outcome of a conditional branch. It analyzes the pattern of previous instructions and uses that to predict whether a branch will be taken or not.

What is meant by the informational entropy?
- Informational Entropy measures the randomness of an OS or signal. 

If size == 15, what is size & 1? if size == 16, what is size & 1? Explain how right = first + 1 + (size & 1) avoids a conditional check. (hint, & is the bitwise AND operator in C/C++. It takes the bit representation of the two operands and perform an AND operation on each of the corresponding bits to form a final value)
- `size & 1` is conditonal,  
    - if size == 15, size & 1 -> 1
    - if size == 16, size & 1 -> 0
    ```cpp
    auto right = first + 1 + (size & 1)
    ```
    `right` is supposed to be at the middle of an array. Such array can be even or odd, hence, `(size & 1)` ensures that the algorithm grows the right way in any array without having duplicates.

Speaker suggests the following algorithm: make_heap(), unguarded_insertion_sort(). He suggests that by doing make_heap() first, you can do something called unguarded_insertion_sort(). Explain what is unguarded_insertion_sort() and why it is faster than regular insertion sort. How does performing make_heap() allow you to do this?
- `unguarded_insertion_sort()` is type of insertion sort that avoids bound checking. `make_heap()` rearranges the     elememts in the array to form a binary heap having the smallest at the top of the heap. Hence this improves the performance of the unguared insertion sort.

The speaker talks about incoperating your conditionals into your arithmetic. What does this mean? Provide an example of this from the video and explain how the conditional is avoided.
- In Heap Insertion Sort: `void insertion_sort_heap()`
    ```cpp
    void insertion_sort_heap(It first, It last){
        //.....
        sort2(first[0], first[size == 2]); //4th line of the function
    }
    ```
    The conditional `size == 2` is used to compare without a join, avoiding the need for an If statement to check if the size is 1 or 2.
     
The speaker talks about a bug in gnu's implementation. Describe the circumstances of this bug.
- GNU makes Insertion sort on rotated data fall back to heapsort causing the algorithm to be in quadratic time complexity.

The speaker shows several graphs about what happens as threshold increases using his new algorithm. The metric of comparison is increased, the metric of moves are increased but time drops... What metric does the author think is missing? Describe the missing metric he speaks about in the video. What is it measuring?
- D(n): This is the average distance between two subsequent array accesses. At different positions of the array, D(n)
    is computed. This gives an idea of how good is the algorithm according to the accesses it does in an array.

What does the speaker mean by fast code is left leaning?
-  This means that a piece of code must get rid of excessive cold codes (if, switch...) in order to be fast.

What does the speaker mean by not mixing hot and cold code?
- In a situation like a function, Fast operations must be carrried out together, then slower operations such as if-else is carried out together away from the fast operations. This is because Informational Entropy of comparison radically affects performance

# Part B: Replication
Array size 
| 8 | 16 | 32 | 
|---|---|---|
| ![myimage-alt-tag](img\8.png) | ![myimage-alt-tag](img\16.png) | ![myimage-alt-tag](img\32.png) |

| 64 | 128 | 256 | 
|---|---|---|
| ![myimage-alt-tag](img\64.png) | ![myimage-alt-tag](img\128.png) | ![myimage-alt-tag](img\256.png) |

| 1024 |  |  | 
|---|---|---|
| ![myimage-alt-tag](img\1024.png) |  |  |





# Part C: Reflection
Did you/your team do all the micro optimizations described? If not, which did you do? Which did you not do?
- Yes, We did. The speaker primarily spoke about Heapify.

What did you/your team find most difficult to understand in the video?
- The concept of Threshold was a bit tricky to understand.
