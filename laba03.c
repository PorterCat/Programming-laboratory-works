#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int j, n, m = 0, k = 0;
    int *b, *c, *d;

    printf("Enter the massive size: "); scanf("%d", &n);

    b = (int*) malloc(n * sizeof(int)); 

    for (int i = 0; i < n; i++)
    {
        j = 1 + rand()%2;
        if (j == 1)
        {
           b[i] = rand() % 50; 
           if (b[i] != 0)
           {
                m++;
           }
        }
        else 
        {
            b[i] = -(rand() % 50);
            if (b[i] != 0)
           {
                k++;
           }
        }
    }

    c = (int*) malloc(m * sizeof(int)); 
    d = (int*) malloc(k * sizeof(int)); 

    for (int i = 0, t_m = 0, t_k = 0; i < n; i++)
    {
        if(b[i] > 0)
        {
            c[t_m] = b[i]; 
            t_m++;
        }
        if(b[i] < 0)
        {
            d[t_k] = b[i]; 
            t_k++;
        }
    }

    printf("[ ");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d, ", b[i]);
    }
    printf("%d ", b[n-1]);
    printf("]\n");

    printf("Possitive massive [ ");
    for (int i = 0; i < m-1; i++)
    {
        printf("%d, ", c[i]);
    }
    printf("%d ", c[m-1]);
    printf("]\n");
    
    printf("Negative massive [ ");
    for (int i = 0; i < k-1; i++)
    {
        printf("%d, ", d[i]);
    }
    printf("%d ", d[k-1]);
    printf("]\n");


    return 0;
}