#include <stdio.h>
#include <stdlib.h>

void insertat(int arr[], int size, int pos, int element)
{

    for (int i = 0; i < size; i++)
    {
        if (i == pos)
        {
            arr[i] = element;
            arr[i + 1] = arr[i];
        }
    }

    return;
}

void delat(int *arr[], int *size, int *pos)
{

    int i;
    for (i = 1 + pos; i < size; i++)
    {

        arr[i - 1] = arr[i];
    }
    return;
}

int main()
{

    int arr[10];
    int pos = 0;

    printf("enter the element you want to insert\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("entered  elements are\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }

    insertat(arr, 10, 3, 12);

    printf(" elements  after insertion\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }

    delat(arr, 4, 3);

    printf(" elements  after deletion\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}