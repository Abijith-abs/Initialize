#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} matrix;

int main()
{
    int m1, n1, m2, n2;

    printf("Enter the number of rows and coloumns present in the first matrix: ");
    scanf("%d %d", &m1, &n1);
    int matrix_1[m1][n1];
    printf("Enter the elements in the first matrix: ");
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n1; j++)
            scanf("%d", &matrix_1[i][j]);
    printf("Enter the number of rows and coloumns present in the second matrix: ");
    scanf("%d %d", &m2, &n2);
    int matrix_2[m2][n2];
    printf("Enter the elements in the second matrix: ");
    for (int i = 0; i < m2; i++)
        for (int j = 0; j < n2; j++)
            scanf("%d", &matrix_2[i][j]);

    for (int i = 0; i < m1; i++)
     {
         for (int j = 0; j < n1; j++)
            printf("%d ", matrix_1[i][j]);
         printf("\n");
     }
     for (int i = 0; i < m2; i++)
     {
         for (int j = 0; j < n2; j++)
             printf("%d ", matrix_2[i][j]);
         printf("\n");
     }

    matrix s_matrix_1[100];
    int number_of_non_zero_elements = 0;
    s_matrix_1[0].row = m1;
    s_matrix_1[0].col = n2;
    for (int i = 0, z = 1; i < m1; i++)
        for (int j = 0; j < n1; j++)
        {
            if (matrix_1[i][j] != 0)
            {
                number_of_non_zero_elements++;
                s_matrix_1[z].row = i;
                s_matrix_1[z].col = j;
                s_matrix_1[z].value = matrix_1[i][j];
                z++;
            }
        }
    s_matrix_1[0].value = number_of_non_zero_elements;

    matrix s_matrix_2[100];
    number_of_non_zero_elements = 0;
    s_matrix_2[0].row = m1;
    s_matrix_2[0].col = n2;
    for (int i = 0, z = 1; i < m2; i++)
        for (int j = 0; j < n2; j++)
        {
            if (matrix_2[i][j] != 0)
            {
                number_of_non_zero_elements++;
                s_matrix_2[z].row = i;
                s_matrix_2[z].col = j;
                s_matrix_2[z].value = matrix_2[i][j];
                z++;
            }
        }
    s_matrix_2[0].value = number_of_non_zero_elements;

    printf("Mat 1\n");
    for (int i = 0; i <= s_matrix_1[0].value; i++)
         printf("%d %d %d\n", s_matrix_1[i].row, s_matrix_1[i].col, s_matrix_1[i].value);
     printf("Mat 2\n");
     for (int i = 0; i <= s_matrix_2[0].value; i++)
         printf("%d %d %d\n", s_matrix_2[i].row, s_matrix_2[i].col, s_matrix_2[i].value);

    if (s_matrix_1[0].row != s_matrix_2[0].row && s_matrix_1[0].col != s_matrix_2[0].col)
    {
        printf("Matrix cannot be added due to incompatible dimension\n");
        return 0;
    }

    matrix s_matrix_sum[s_matrix_1[0].value + s_matrix_2[0].value];

    s_matrix_sum[0].row = s_matrix_1[0].row;
    s_matrix_sum[0].col = s_matrix_1[0].col;

    int z = 1, x = 1, y = 1;

    for (int i = 0; i < s_matrix_1[0].row; i++)
        for (int j = 0; j < s_matrix_1[0].col; j++)
        {
            if (s_matrix_1[x].row == i && s_matrix_1[x].col == j && s_matrix_2[y].row == i && s_matrix_2[y].col == j)
            {
                s_matrix_sum[z].row = i;
                s_matrix_sum[z].col = j;
                s_matrix_sum[z].value = s_matrix_1[x].value + s_matrix_2[y].value;
                x++;
                y++;
                z++;
            }
            else if (s_matrix_1[x].row == i && s_matrix_1[x].col == j)
            {
                s_matrix_sum[z].row = i;
                s_matrix_sum[z].col = j;
                s_matrix_sum[z].value = s_matrix_1[x].value;
                x++;
                z++;
            }
            else if (s_matrix_2[y].row == i && s_matrix_2[y].col == j)
            {
                s_matrix_sum[z].row = i;
                s_matrix_sum[z].col = j;
                s_matrix_sum[z].value = s_matrix_2[y].value;
                y++;
                z++;
            }
        }
    s_matrix_sum[0].value = --z;

    printf("Sum\n");
    for (int i = 0; i <= s_matrix_sum[0].value; i++)
        printf("%d %d %d\n", s_matrix_sum[i].row, s_matrix_sum[i].col, s_matrix_sum[i].value);

    return 0;
}