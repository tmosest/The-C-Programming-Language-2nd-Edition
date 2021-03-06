/**
* Program to print out a farenheit to celsius table with floating points.
*/
#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(fahr <= upper) {
        celsius = 5.0 / 9.0 * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, celsius); // print 3 digits . 0 digits for fahr and 3d.1d for celsius.
        fahr += step; 
    }

    return 0;
}