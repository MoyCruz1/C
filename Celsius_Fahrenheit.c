#include <stdio.h>

main()

{
    int lower, upper, step;
    float celsius, fahr;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    while (celsius <= upper){
        fahr = ((9.0/5.0) * celsius) + 32.0;
        printf ("%6.1f\t %3.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
