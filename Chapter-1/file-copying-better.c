/**
* Program to copy input and print it back out.
* This one is better
*/
#include <stdio.h>

int main()
{
    int c; // we normally store characters in a char but we need something big enough for EOF
    while((c = getchar()) != EOF) 
        putchar(c);
    return 0;
}