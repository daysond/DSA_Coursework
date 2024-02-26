## Exam Review Questions

**1.** Given a relatively balanced binary search tree, why is the search() function O(log n)

```
A balanced binary search tree has the property that the height of the tree is logarithmic to the number of nodes in the tree. Specifically, for a binary search tree with n nodes, its height h is O(log n) in the worst case.

When performing a search operation in a binary search tree, we start at the root node and compare the value we are searching for with the value of the current node. If the value is smaller, we move to the left child node; if the value is larger, we move to the right child node. We repeat this process until we find the node containing the value we are searching for or we reach a leaf node, indicating that the value is not in the tree.

Since a balanced binary search tree has a logarithmic height, the number of comparisons we need to make to find a node is proportional to the height of the tree, which is O(log n) in the worst case. Therefore, the search() function in a balanced binary search tree has a time complexity of O(log n) in the worst case.
```

**2.** Explain why you need a max_heap (biggest is at root, parent > children) for heap sort that sorts an array in ascending order(small to big)

```
In a max-heap, the largest element is always stored at the root of the heap, and each parent node is greater than its children. This ensures that the maximum element is always accessible in constant time (i.e., O(1)) at the root of the heap. During the heapify procedure, the largest element is repeatedly swapped with the last element in the heap, which is then removed from consideration. By repeatedly performing this operation, the largest remaining element is always placed at the end of the array, resulting in a sorted array.

Using a max-heap for heap sort allows for efficient sorting of an array in ascending order because it reduces the number of comparisons required to sort the array. By always placing the largest element at the root of the heap, only one comparison is needed to determine the correct position of each element in the sorted array. This reduces the total number of comparisons required to O(n log n), which is the same as the worst-case time complexity of the algorithm.

In summary, a max-heap is used for heap sort that sorts an array in ascending order because it provides efficient insertion and removal of elements while maintaining the heap property, and reduces the number of comparisons required to sort the array, resulting in a time complexity of O(n log n).
```


**3.** Explain how quick sort works

```
pivot, smaller goes to left of pivot, larger goes to right.
For left, pivot, do the same. For right, pivot, do the same

Here's how Quick sort works:

Choose a pivot: Select a pivot element from the input array. There are several ways to choose a pivot element, such as selecting the first or last element, or choosing a random element. The choice of pivot element can affect the performance of the algorithm.
Partition the array: Reorder the elements in the array so that all elements less than the pivot are moved to the left of the pivot, and all elements greater than or equal to the pivot are moved to the right of the pivot. This process is called partitioning.
Recursively apply steps 1 and 2: Apply steps 1 and 2 recursively on the two sub-arrays created by the partitioning step. That is, choose a pivot element for each sub-array and partition the sub-array around the pivot.
Combine the results: Combine the sorted sub-arrays to obtain the final sorted array.

```

**4.** Why is Mergesort O(nlogn)

```
Mergesort is an efficient sorting algorithm that has a time complexity of O(nlogn) because it divides the input array into two halves, sorts them recursively, and then merges the two sorted halves back into a single sorted array.

The time complexity of Mergesort can be understood as follows:

Divide: In the first step, the input array is divided into two halves, each containing n/2 elements. This step takes O(1) time.
Conquer: The two sub-arrays are sorted recursively using the same mergesort algorithm. This involves dividing the sub-arrays again into halves and sorting them until each sub-array contains only one element, which is already sorted. This step takes O(logn) time, since the number of levels in the recursion tree is logn, where n is the number of elements in the input array.
Merge: The two sorted sub-arrays are merged into a single sorted array. The merge operation takes O(n) time because each element in the sub-arrays is visited exactly once during the merge.
Thus, the total time complexity of Mergesort can be expressed as T(n) = 2T(n/2) + O(n), where the first term represents the time complexity of sorting the two sub-arrays recursively, and the second term represents the time complexity of merging the two sorted sub-arrays.

Using the Master Theorem, we can solve this recurrence relation and obtain the time complexity of Mergesort as O(nlogn).
```

**5.**  If you were to implement a reverse phone directory (You enter a phone number to find a person), what data structure would you use for the table.

    hash table

**6.** Explain why search through a balanced Binary Search tree is O(log n)


**7.** Can you binary search a sorted linked list? Explain why or why not?

```
Binary search reduces the number of elements to be searched by filtering out almost half the number of elements at each iteration. For the best implementation of Binary search we need two prerequisites:

The list must be in sorted order.
Any random element can be accessed in constant time.
With linked list the second prerequisite is not satisfied as any random element in linked list cannot be accessed in constant time, but it must be traversed completely.
```

**8.** Write the member function for a Binary Search tree:

```cpp
void printBetween(int min, int max) {
 // This function prints every value in the tree that is between min and max inclusive. 
 // Function only visits a subtree where the values may be valid.
    printBetween(root, min, max);

}

void printBetween(Node *root, int min, int max) {

    if(root == nullptr) return;
    
    printBetween(root->leftChild, min, max);
   
    if(root->data >= min || root->data <= max) {
        print(root->data);
    }

    printBetween(root->rightChild, min, max);
}
    
```

**9.** Write a member function  for a Binary Search Tree that will return the height of the Binary Search Tree.

```cpp
int BST::height() const {
    return findHeight(root_);
}

int BST::findHeight(Node *node) const {
    if(node == nullptr) return -1;

    int leftHeight = findHeight(node->leftChild);
    int rightHeight = findHeight(node->rightChild);

    return 1 + (leftHeight > rightHeight ? leftHeight : righthHeight)
}

```

**10a.** Draw 7 circles and label them A, B , C ,D, E, F, G.  From draw random arrows between these circles.  This will form a graph.

  * draw out the adjacency matrix and the adjacency list that corresponds to the graph

  Adjacency Matrix: column is out going  row is incoming 

**10b.** Add some weights to your graph.  Using Dijkstra's algorithm, find the shortest path from A to every other node.



**11.** Draw a binary tree with at least 20 nodes and put in some random labels (numbers, letters, doesn't really matter as long as they are unique)

  * list the leaf nodes
  * list the root node
  * list the nodes in a preorder, postorder, inorder, breadthfirst manner

**12a .**  DONE

Create an BST tree by adding the following numbers to these trees in order given:

80,70,60,50,40,30,20,10, 35, 45, 43

Draw the result of each tree after an insertion


**12b.** 

remove these numbers from the tree formed in 12a in the order given: 

10, 70, 40 

Draw the result of each tree after a value is removed


**12 c.**

Create a min heap  (smaller value, higher priority) by inserting these values in order given: 

40, 30, 10, 60,50,70,20 35, 65,5, 7, 22, 15
Draw the result of each the tree after each insertion

**12 d.** 

perform remove() 3 times from your heap in 12 c and draw the results.

**12 e.** DONE

Create an AVL tree by adding the following numbers to these trees in order given:

80,70,60,50,40,30,20,10, 35, 45, 43

Draw the result of each the tree after each insertion

**12 f.** GOOD

Create a Red-Black tree by adding the following numbers to these trees in order given:

10,20,30,40,50,60,70,80, 46, 56, 44, 48, 49

Draw the result of each the tree after each insertion


**12 g.** DONE

Create a 2-3 tree by adding the following numbers to these trees in order given:

80, 70, 60, 50, 40, 30, 20,  65, 62, 10, 25, 21, 22

Draw the result of each the tree after each insertion
 
**13a.**

Suppose you are given the array {15, 12, 14, 11, 10, 9, 7, 5, 2, 1}.  
If the array represents a tree, draw the tree associated with the array. 

**13b.**

Make heap in place using the heapify algorithm to form a **min-heap**.  Draw the final heap and state the final array created from the heapify routine.  

**14.**

Is it possible to write a program that can check for infinite loops.



**15.**
The following show a table of keys and the hash index of these keys within a table of size 10

| key | hashIdx |
|---|---|
| alpha | 8|
| beta | 9|
| gamma | 8|
| apple | 4 |
| orange | 4 | 
| cherry | 5 |

**15 a.**

Draw an empty array of size 10 that represents a linear probing table.

**15 b.**
Insert the keys in the following order and show the final array:

* beta
* alpha
* gamma
* apple
* cherry
* orange


**15 c.**

remove apple from table in part b, what does final array look like

**15 d.**

remove beta from table in part c, what does final array look like

**15 e.**

If you used tombstones in the previous parts, redo this question (parts A to D) without tombstones.  If you did it without tombstones, redo this question (parts A to D)  with tombstones 
