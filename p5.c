#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} matrix;

int main()
{
    int size;
    printf("Enter the number of non zero elements: ");
    scanf("%d", &size);

    matrix m[size + 1];
    m[0].value = size;

    printf("Enter the number of rows and coloumns: ");
    scanf("%d %d", &m[0].row, &m[0].col);

    printf("Enter the sparse matrix representation: ");
    for (int i = 1; i <= size; i++)
        scanf("%d %d %d", &m[i].row, &m[i].col, &m[i].value);

    printf("Sparse matrix representation\n");
    for (int i = 0; i <= size; i++)
        printf("%d %d %d\n", m[i].row, m[i].col, m[i].value);

    for (int i = 1; i <= size; i++)
    {
        int temp = m[i].row;
        m[i].row = m[i].col;
        m[i].col = temp;
    }

    printf("Sparse matrix representation\n");
    for (int i = 0; i <= size; i++)
        printf("%d %d %d\n", m[i].row, m[i].col, m[i].value);
}