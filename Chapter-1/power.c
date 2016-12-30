/**
* Program to write a function that computes a**b
*/
#include <stdio.h>

// Declaring the function but not defining it yet. This is a fucntion prototype
int power(int a, int b);

// Test the power function
int main()
{
    int i;
    for(i = 0; i < 10; i++)
        printf("%d %d %d\n", i, power(2,i), power(-3, i));
}

// Define our functions
int power(int base, int n)
{
    int i, p;
    p = 1;
    for(i = 1; i <= n; i++)
        p = p * base;
    return p;
}

/**
 In the old days power would have been:
 which is interesting.

int power(base, n)
int base, n;
{
    int i, p;
    p = 1;
    for(i = 1; i <= n; i++)
        p = p * base;
    return p;
}
*/