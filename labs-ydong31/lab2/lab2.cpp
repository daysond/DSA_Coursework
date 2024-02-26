/**************************************************/
/*                                                */
/*  Lab 2 Starter file                            */
/*                                                */
/*  Name: Yiyuan Dong                             */
/*  Student number: 065-182-131                   */
/*                                                */
/**************************************************/

/* remember to code these in a RECURSIVE only manner*/
#include <map>

unsigned long long factorial (unsigned int n){
    return (n == 0) ? 1 : n * factorial(n-1);
}

unsigned long long power (unsigned int base, unsigned int n){
   return (n==0) ? 1 : base * power(base, n-1);
}

unsigned long long fibonacci (unsigned int n){
    if (n <= 1) return n;
    if (n == 2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}


/* lab challenge */
/* efficient power*/
unsigned long long efficient_power (unsigned int base, unsigned int n){
    if (n == 0) return 1;
    if (n % 2) return base * efficient_power(base, n - 1);
    unsigned long long res = efficient_power(base, n/2);
    return  res * res;
}
