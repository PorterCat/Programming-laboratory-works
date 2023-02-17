#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int task1();
int task2();
int task3();
void swap(float* , float*);

int main()
{
    int task;
    scanf("%d", &task);
    switch(task)
    {
        case 1:
            task1(); break;
        case 2:
            task2(); break;
        case 3:
            task3(); break;
    }
}

int task1()
{
    int j, n, m = 0, k = 0;
    int *b, *c, *d;

    printf("Enter the massive size: "); scanf("%d", &n);

    b = (int*) malloc(n * sizeof(int)); 

    for (int i = 0; i < n; i++)
    {
        b[i] = -50 + rand() % (50 + 50 + 1);
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

int task2()
{
    int n;
    printf("Enter the massive size: "); scanf("%d", &n);
    float *a;
    float **b;

    a = new float [n]; 
    b = new float* [n];
    
    for (int i = 0; i < n; i++ ) 
    { 
        a[i] = 0.01 * (-1000 + rand() % (1000 + 1000 + 1));
        b[i] = &a[i];
    }

    for (int i = 0; i < n; i++ ) 
    { 
        printf("%.2f ", a[i]);
    }

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(*b[i] > *b[j])
            {
                swap(b[i], b[j]);
            }
        }
    }

    printf("\n");
    for (int i = 0; i < n; i++ ) 
    { 
        printf("%.2f ", a[i]);
    }

    a = NULL;
    b = NULL;
    return 0;
    
}

int task3()
{
    int n;
    int *arr, *b;

    printf("Enter the massive size: "); scanf("%d", &n);

    arr = new int [n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    arr[1] = 0;
    
    int i = 2, j;
    while(i < n)
    {
        if (arr[i] != 0)
        {
            j = i + i;
            while(j <= n)
            {
                arr[j] = 0;
                j = j + i;
            }
        }
        i = i + 1;
    }

    int n_new = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != 0)
        {
            n_new++;
        }
    }

    b = new int[n_new];
    j = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != 0)
        {
            b[j] = arr[i];
            j++;
        }
    }

    for (int i = 0; i < n_new; i++ ) 
    { 
        printf("%d ", b[i]);
    }

    /*int n_new = n - counter;
    b = new int[n_new];

    for(int i = 0, j = 0; i < n; i++)
    {
        if(arr[i] != 0)
        {
            b[j] = arr[i];
            j++;
        }
    }

    printf("\n");
    for (int i = 0; i < n_new; i++ ) 
    { 
        printf("%d ", b[i]);
    }*/

    return 0;

}



void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/*

*/