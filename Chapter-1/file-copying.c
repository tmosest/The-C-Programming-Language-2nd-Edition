/**
* Program to copy input and print it back out
*/
#include <stdio.h>

int main()
{
    int c; // we normally store characters in a char but we need something big enough for EOF
    
    c = getchar();
    while(c != EOF) {
        putchar(c);
        c = getchar();
    }
    return 0;
}