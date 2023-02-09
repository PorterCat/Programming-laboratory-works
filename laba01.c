#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void easter(int);
float power(float, int);
float cosinus(int x);

int main()
{
    int x = 5, n = 3;
    int year = 2002;
    easter(year);
    printf("%f\n", power(x, n));
    printf("%f\n", power(x, -n));
    printf("cos: %f %f\n ", cosinus(x), cos(x));
}


void easter(int y)
{
    int a = y % 19;
    int b = y % 4;
    int c = y % 7;
    int d = (19 * a + 15) % 30;
    int e = (2*b + 4*c + 6*d + 6) % 7;
    int f = d + e;
    if(f <= 26)
    {
        a = 4 + f;
        if (a / 10 > 0) 
        {
            printf("%d.%s.%d\n", a, "04", y);
        }
        else 
        {
            printf("0%d.%s.%d\n", a, "04", y);
        }
    }
    else 
    {
        a = f - 26;
        if (a / 10 > 0) 
        {
            printf("%d.%s.%d\n", a, "05", y);
        }
        else 
        {
            printf("0%d.%s.%d\n", a, "05", y);
        }
    }
}

float power(float x, int n)
{

    float sum = 1;

    if (n > 0) 
    {
        for(n; n > 0 ; n--)
        {
            sum = sum * x;
        }
    } 
    else if (n < 0)
    {
        for(n; n < 0 ; n++)
        {
            sum = sum * x;
        }
        sum = 1/sum;
    } 
    else 
    {
        sum = 1;
    }
    
    return sum;
}

float fact(int n)
{
    if(n <= 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}

float cosinus(int x)
{
    float eps = 0.0001; 
    int n = 0;
    float step = ((power(-1,n))*(power(x,2*n)))/(fact(2*n));
    float result = step;
    while(fabs(step) >= eps)
    {
        n++;
        step = (power(-1, n))*((power(x,2*n))/(fact(2*n)));
        result += step; 
    }
    return result;
}

