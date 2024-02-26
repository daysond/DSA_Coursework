## Q1:

What is the run time of the following functions:

```c
int f1(int n){
    int rc=1;
    for(int i=0;i<5;i++){
        rc+=1;
    }
    return rc;
}
```


## Q2:

What is the run time of the following functions:

```c
int f1(int n){
    int rc=1;
    for(int i=0;i<n;i+=2){
        rc+=1;
    }
    return rc;
}
```
## Q3:

Suppose that the function function1(n) has a run time of O(n) and function2(n) has a run time of O(n^2)  What is the run time of f1(n)?

```c
int f1(int n){
    function1(n);
    function2(n);
}
```

## Q4:

Write the following function recursively:

```
bool isPalindrome(const char* s)
```
s is a null terminated character string.  This function returns true if s is a palindrome.  A palindrome is a string that reads the same forwards and backwards.  Thus:   noon, mom, dad are all palindromes.   table, texture, glass are not palindromes.

the above function can be a wrapper to a function that actually does the work

Try to write the function to O(n) run time where n is the length of s.

```cpp

bool isPalindrome(const char* s) {
    
    size_t len = strlen(s);
    
    return isPalindrome(s, 0, len-1);
    
}
bool isPalindrome(const char* s, int l, int r) {
    
    if (s == nullptr)
        return false;
    
    if (l >= r) return true;
    
    if(s[l] == s[r]){
        return isPalindrome(s, l+1, r-1);
    }
    
    return false;
}



```

## Q5
Given the following:

```c
class Stack{
   ...
public:
   void push(int v);      
   void pop();           
   int top();            
   bool isEmpty();        
};
```
 and
```c
class Queue{
   ...
 public:
   void enqueue(int v);
   void dequeue();
   int front();
   bool isEmpty();   

};
```
Write the function:
```c 
void ReOrder(int newarr[], int arr[],int size);
```

```cpp

void ReOrder(vector<int> &newarr, vector<int> &arr,int size){
    
    stack<int> s;
    queue<int> q;
    
    for(int i = 0; i<size; i++) {
        int e = arr[i];
        if (e < 0) q.push(e);
        if (e > 0) s.push(e);
        if(e == 0 || i == (size - 1)) {
            while (!q.empty()) {
                newarr.push_back(q.front());
                q.pop();
            }
            while (!s.empty()) {
                newarr.push_back(s.top());
                s.pop();
            }
        }
    }
}

```


This function creates newarr from the values in arr using the following rules:

```
size is length of arr
The value 0 separates arr into "chunks"
Each "chunk" can hold both positive and negative values in any order
```

When creating newarr, each chunk must satisfy the following rules

```
All negative values go before all positive values
All negative values are added in the same order as their original order.
All positive values are added opposite to their original order
The 0 that was used to separate each chunk is not added to newarr.
```

Example:
 
```
Suppose arr={-3,2,-1,5,1,-4,0,11,12,13,-11,-12};
then when you create newarr, newarr should have the following:
{-3,-1,-4,1,5,2,-11,-12,13,12,11}
```


## Q6:

When using a singly linked list to implement a stack, is it better for insertions to occur at the front or back of the list (or does it matter)?  Why?

```
Insert at the front. Stack is first in last out. So, we if insert the element in the front, the elements that were added to the list earlier will be pushed to the back.
And when we pop the stack, we just return the front of the list and then delete it from the singly linked list.

If the insertion happened at the back, whenever we pop the stack, we would have to traverse the list to the back and then return and delete the element.


```

## Q7:

Describe what you will need to implement a queue using an array such that you have O(1) runtimes for enqueue() and dequeue() operations.  Do this WITHOUT using code (ie what do you need, why do you need it, but don't just code dump)

## Q8:

A self adjusting linked list is a linked list where a successful search causes the list to adjust so that the found item is moved to the front (and thus allowing successive search for same item to be more readily found).
 
Given the following class declarations for a singly linked self adjusting linked list:
 
```cpp
template <class T>
clsss SelfAdjustingList{
    struct Node{
        T value_;
        Node* next_;
        Node(const T& data=T{},Node* next=nullptr){...}
    };
    Node* front_;
    Node* back_;
 
public:
    class const_iterator{
       friend class SelfAdjustingList;
       Node* curr_;
       const_iterator(Node* n){...}
    public:
        const_iterator(){...}
	const_iterator operator++(){...}
	const_iterator operator++(int){...}
	const_iterator operator--(){...}
	const_iterator operator--(int){...}
	bool operator==(const_iterator rhs){...}
	bool operator!=(const_iterator rhs){...}
	const T& operator*()const{...}
    };
    class iterator:public const_iterator{
        friend class SelfAdjustingList;
        iterator(Node* n):const_iterator(n){...}
    public:
	iterator();
	iterator operator++(){...}
	iterator operator++(int){...}
	iterator operator--(){...}
	iterator operator--(int){...}
	T& operator*(){...}
	const T& operator*()const{...}
    };
    iterator begin(){...}
    iterator end(){...}
    const_iterator begin() const{...}
    const_iterator end() const{...}
};
```

Write the following member function:
```cpp 
iterator SelfAdjustingList::search(const T& v);
```
* This function searches for v within the list and returns an iterator to the node where v is found.  If not found, function returns end()
* The list will be adjusted so that the found node is moved so that it becomes the first data node in the list
* You can make use of any function you see in the declaration above.  Any other function you wish to use must be written
* Function must have run time of O(n)

Answer:

```cpp
if(!front_) return iterator(nullptr, this);

bool found = false;
Node *temp = front_;
//  finding the node
while (temp && !found) {
    if (temp->data_ == v)
        found = true;
    else
        temp = temp->next_;
}
//  swaping node: move node to the front.
if(found) {
    iterator it = iterator(temp, this);
    it--;
    Node *prev = it.curr_;      //  the node before temp (the node that is found)
    prev->next_ = temp->next_;  

    temp->next_ = front_;       //  move the found node to front.
    front_ = temp;
} 

return iterator(temp, this);
    

```

## Q19: Recursive Analysis:

Perform an analysis on this function with respect to the length of the string str
```c++
int doSomething(const char* str){
    if(str[0]=='\0'){
        return 0;
    }
    else{
        return doSomething(str+1) + 1;
    }
}
```

## Q10: Sorting:


**This is not a writing question... not really a question.  It is instructions on reviewing sorting.  The only writing is to make the the number paper.. after that its just moving them around with your hands by following the algorithm**


Get 10 small pieces of paper and put the numbers 1 through 10 on them.  
For each of the 5 sorting algorithms studied so far (bubble, insertion, quick, merge, selection)
   * Mix them up.
   * Place the 10 pieces of paper in a row.
   * Perform the sort for these papers.