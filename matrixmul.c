#include <stdio.h>

void matrixProduct(int mat1[][100], int mat2[][100], int res[][100], int row1, int col1, int row2, int col2)
{
    int i, j, k;

    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            res[i][j] = 0;

            for (k = 0; k < col1; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main()
{
    int row1, col1, row2, col2;
    int mat1[100][100], mat2[100][100], res[100][100];
    int i, j;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &row1, &col1);

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &row2, &col2);

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Check for compatibility of matrices
    if (col1 != row2)
    {
        printf("The matrices are not compatible for multiplication.\n");
        return 0;
    }

    // Perform matrix multiplication
    matrixProduct(mat1, mat2, res, row1, col1, row2, col2);

    // Print the product matrix
    printf("Product Matrix:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
