/**
* Program to count the characters in an input.
*/
#include <stdio.h>

int main()
{
    long nc;
    nc = 0;
    while(getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
    return 0;
}