#include<stdio.h>

int main() { 
    int n, i, pos, value;


    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n + 1];

    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter position (0 to %d) and value to insert: ", n);
    scanf("%d %d", &pos, &value);

    if (pos < 0 || pos > n) {
        printf("Invalid position\n");
        return 1;
    }

    for (i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    n++;

    printf("Array after insertion: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
