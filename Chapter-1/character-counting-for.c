/**
* Program to count the characters in an input.
* We use a double for larger possible number of characters
*/
#include <stdio.h>

int main()
{
    double nc;
    for(nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f", nc);
    return 0;
}