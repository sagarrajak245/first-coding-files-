#include <stdio.h>
#include <string.h>

int main()
{
    int mat1[50][50];
    int row1, col1, i, j;

    printf("enter the row1 and col1\n");
    scanf("%d%d", &row1, &col1);

    printf("enter the mat1\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {

            scanf("%d", &mat1[i][j]);
        }
    }

    printf(" the upperdiagonal is is\n");
    for (i = 0; i < row1; i++)
    {
        for (j = i + 1; j < col1; j++)
        {

            printf("%d\t", mat1[i][j], i + 1);
        }
        printf("\n");
    }

    printf(" the lowerdiagonal is is\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < i; j++)
        {

            printf("%d\t", mat1[i][j], j + 1);
        }
        printf("\n");
    }

    return 0;
}