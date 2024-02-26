/*******************************************************************/
/*                                                                 */
/*  A1 Part 4: starter file                                        */
/*                                                                 */
/*  Author Name: Yiyuan Dong                                       */
/*                                                                 */
/*******************************************************************/
#include <cmath>
#include <map>
#include <cstring>

int* fibArray(int n);
int* IntegerToBinary(int n);
//  helpers
int fib_efficient(int n, std::map<int, int> &lookup, int* arr);
void IntegerToBinary(int n, size_t size, int* arr);
/*
Fibonacci sequence Problem:
Implement method fibArray returns an array storing the first n numbers in a Fibonacci sequence. 
The Fibonacci starts with the first two numbers being 1 and 1, then starting from the 3rd number, 
it is the sum of the previous two numbers. You can assume that n is positive. 
e.g., fibArray(5) returns an array {1, 1, 2, 3, 5}.
*/
int* fibArray(int n) {
    int *ret = new int[n];
    std::map<int, int> lookup = {{1,1} , {2, 1}};
    ret[0] = 1;
    ret[1] = 1;
    int a = fib_efficient(n, lookup, ret); 
    return ret;
}

int fib_efficient(int n, std::map<int, int> &lookup, int* arr) {
    
    if(lookup[n]) 
        return lookup[n];
    else {
        int res = fib_efficient(n-1, lookup, arr) + fib_efficient(n-2, lookup, arr);
        lookup[n] = res;
        arr[n-1] = res;
        return res;
    }
}


/*
Write a recursive function IntegerToBinary convert any decimal number n > 0 and n <= 65535 into a binary number, 
return an array represent the binary number. You can assume that n is positive. a binary (base-2) number. 
A binary number is made up of one or more binary digits called bits.
 A bit has a value that is equal to either 0 or 1.
Example:
IntegerToBinary (4)  return [0, 0, 1], where (0*1)+(0*2)+(1*4) = 4 
IntegerToBinary (9)  return [1, 0, 0, 1], where (1*1)+(0*2)+(0*4)+(1*8) = 9
IntegerToBinary (31)  return [1, 1, 1, 1, 1], where (1*1)+(1*2)+(1*4)+(1*8)+(1*16) =31
*/
int* IntegerToBinary(int n) {
    size_t size = log2(n) + 1;
    int * ret = new int[size];
    IntegerToBinary(n, size-1, ret);
    return ret;
}

void IntegerToBinary(int n, size_t size, int* arr) {
    short index = size - floor(log2(n));
    if(n == 1) {
        arr[index] = 1;
        return;
    }
    arr[index] = n%2;
    IntegerToBinary(n/2, size, arr);
}


// keeping the original function signature

// int* fibArray(int n) {
//     int *ret = new int[n];
//     if(n==1) {
//         ret[0] = 1;
//         return ret;
//     }

//     if (n == 2) {
//         ret[0] = 1;
//         ret[1] = 1;
//         return ret;
//     }
    
//     int* prevRes = fibArray(n-1);
//     memcpy(ret, prevRes, (n-1)*sizeof(int));
//     delete [] prevRes;
//     ret[n-1] = ret[n-2] + ret[n-3];
//     return ret;
// }


// int* IntegerToBinary(int n) {
//     size_t size = log2(n) + 1;
//     int * ret = new int[size];
//     if(n == 1) {
//         ret[0] = 1;
//         return ret;
//     }
//     int next = n / 2;
//     int bit = n % 2;
//     int* nextRes = IntegerToBinary(next);
//     memcpy(ret+1, nextRes, (size-1)*sizeof(int));
//     delete [] nextRes;
//     ret[0] = bit;
//     return ret;
// }







