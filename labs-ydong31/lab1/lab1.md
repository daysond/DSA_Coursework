# Part 2: Analysis

## factorial()

Let **_n_** represent the value we are finding the **factorial** for.

Let **_T(n)_** represent number of operations needed to find **_n!_** using the code.

```cpp
unsigned long long factorial(unsigned int n){

    unsigned long long ret = 1;     // 2

    for (; n > 1; n--) {            // (n-1) + 2(n-1)
        ret *= n;                   // 2(n-1)
    }

    return ret;                     // 1

}
```

Add up the operation counts:
**_T(n) = 2 + (n-1) + 2(n-1) + 2(n-1) + 1_**

Simplify the equation:
**_T(n) = 5n - 2_**

Therefore: **_T(n)_ is _O(n)_**

## power()

Let **_n_** represent the **power**.

Let **_T(n)_** represent number of operations needed to find **_power of n_** using the code.

```cpp
unsigned long long power(unsigned int base, unsigned int n){

    unsigned long long ret = 1;     // 2

    for (; n > 0; n--) {            // n + 2n
        ret *= base;                // 2n
    }

    return ret;                     // 1

}
```

Add up the operation counts:
**_T(n) = 2 + n + 2n + 2n + 1_**

Simplify the equation:
**_T(n) = 5n + 3_**

Therefore: **_T(n)_ is _O(n)_**

## fibonacci()

Let **_n_** represent the value we are finding the **fibonacci** for.

Let **_T(n)_** represent number of operations needed to find **_n!_** using the code.

```cpp
unsigned long long fibonacci(unsigned int n){

    if (n <= 1) return n;               // 2

    unsigned long long ret = 1, previous = 1, current = 1;         // 6

    while (n > 2){                      // n-2
        ret = previous + current;       // 2(n-2)
        previous = current;             // n-2
        current = ret;                  // n-2
        n--;                            // 2(n-2)
    }

    return ret;                         // 1
}
```

Add up the operation counts:
**_T(n) = 6 + (n-2) + 2(n-2) + (n-2) + (n-2) + 2(n-2) + 1_**

Simplify the equation:
**_T(n) = 7n - 7_**

Therefore: **_T(n)_ is _O(n)_**

## bubbleSort()

Let **_n_** represent the **size** of the array that we are sorting.

Let **_T(n)_** represent number of operations needed to find **_n!_** using the code.

```cpp
void bubbleSort(int arr[],int size){

    int tmp;            // 1

    for (int i=0; i<size-1; i++) {              // 6(n-1)
        for (int j=0; j<size-1-i; j++){         // 7(n-1)(n-1-i)

            if (arr[j+1] < arr[j]) {            // 4(n-1)(n-1-i)
                tmp = arr[j];                   // 2(n-1)(n-1-i)
                arr[j] = arr[j+1];              // 4(n-1)(n-1-i)
                arr[j+1] = tmp;                 // 3(n-1)(n-1-i)
            }
        }
    }
}
```

Add up the operation counts:

$$T(n) = 1 + 6(n-1) + \sum_{i=0}^{n-1} 20(n-1)(n-1-i)$$

Simplify the equation we will get a **quadratic fuction**. 

Therefore: **_T(n)_ is _O(n<sup>2</sup>)._**
