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

void insertionSort(int *A, int n)
{
    int key, i, j;
    // Loop for passes
    for (i = 0; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        // Loop for each pass
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    PrintArray(A, n);
    insertionSort(A, n);
    PrintArray(A, n);
    return 0;
}