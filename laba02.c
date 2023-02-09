#include <stdio.h>
#include <math.h>

void task1();
void task2(int*, int );
void task3(int);

int main()
{
    int n = 10;
    int A[] = {1, 2, -4, -5, 6, 7, 9, 13, -14, 2};
    task1();
    printf("\n\n");
    task2(A, n);
    printf("\n\n");
    task3(15);
    return 0;
}

void task1()
{
    int x;
    scanf("%d", &x);
    if(x != 0)
    {
        task1();
    }
    if (x > 0)
    {
        printf("%d ", x);
    }
}



void task2(int *A, int n)
{
    if(n != 0)
    {
        if(A[n] < 0)
        {
            printf("%d ", A[n]);
            return task2(A, n-1);
        }
        task2(A, n-1);
        printf("%d ", A[n]);
    }
}

void task3(int n)
{
    if(n != 0)
    {
        task3(n/2);
        printf("%d", n%2);
    }
}


