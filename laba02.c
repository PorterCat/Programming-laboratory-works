#include <stdio.h>
#include <math.h>
#define PI 3.1415926535

int factorial(int);

int main()
{
    float esp = 0.0001;
    float res = 0;
    int n = 12;
    float x = 45;

    for(int i = 1; i < n; i++)
    {
        if(i % 2 == 1)
        {
            res = res - ((pow(x, 2*i))/(factorial(2*i)));
        }
        else
        {
            res = res + (pow(x, 2*i)/factorial(2*i));
        }
    }

    printf("%f", res);


    return 0;
}

int factorial(int n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

