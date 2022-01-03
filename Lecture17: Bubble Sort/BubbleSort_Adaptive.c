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

void BubbleSortSort(int *A, int n)
{
    int i, j, temp;
    int isSorted = 0;
    for (i = 0; i < n - 1; i++)
    {
        printf("Working on pass Number:%d\n", i + 1);
        isSorted = 1;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}
int main()
{
    int A[] = {1, 9, 6, 3, 78, 56};
    int n = 6;
    PrintArray(A, n);
    BubbleSortSort(A, n);
    PrintArray(A, n);
    return 0;
}