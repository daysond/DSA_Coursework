/**************************************************/
/*                                                */
/*  Lab 1 Starter file                            */
/*                                                */
/*  Name: Yiyuan Dong                             */
/*  Student number: 065-182-131                   */
/*                                                */
/**************************************************/

/* remember to code these in an iterative only manner*/

unsigned long long factorial(unsigned int n)
{
    unsigned long long ret = 1;
    for (; n > 1; n--)
    {
        ret *= n;
    }
    return ret;
}

unsigned long long power(unsigned int base, unsigned int n)
{
    unsigned long long ret = 1;
    for (; n > 0; n--)
    {
        ret *= base;
    }
    return ret;
}

unsigned long long fibonacci(unsigned int n)
{
    if (n <= 1)
        return n;

    unsigned long long ret = 1, previous = 1, current = 1;

    while (n > 2)
    {
        ret = previous + current;
        previous = current;
        current = ret;
        n--;
    }

    return ret;
}