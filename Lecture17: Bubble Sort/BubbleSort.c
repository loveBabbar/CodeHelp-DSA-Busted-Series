#include <stdio.h>

void PrintArray(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void BubbleSort(int *A, int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        printf("Working on pass Number:%d\n", i + 1);
        for (j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int A[] = {1, 9, 6, 3, 78, 56};
    int n = 6;
    PrintArray(A, n);
    BubbleSort(A, n);
    PrintArray(A, n);
    return 0;
}