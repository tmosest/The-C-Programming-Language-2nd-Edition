/**
* Program to count the number of times a digit appears.
*/
#include <stdio.h>

int main()
{
    int c, i, nwhite, nother;
    int ndigit [10];

    nwhite = nother = 0;
    for(i = 0; i < 10; i++)
        ndigit[i] = 0;

    while( (c = getchar()) != EOF) 
        if( c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if(c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits:\n");
    for(i = 0; i < 10; i++)
        printf("digit: %d count: %d\n", i, ndigit[i]);

    printf("white space: %d\nother: %d\n", nwhite, nother); 

    return 0;
}