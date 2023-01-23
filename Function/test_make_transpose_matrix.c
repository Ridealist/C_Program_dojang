#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void transpose(int (*matrix)[4], int n) {
    int temp;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main()
{
    int matrix[4][4];

    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        &matrix[0][0], &matrix[0][1], &matrix[0][2], &matrix[0][3],
        &matrix[1][0], &matrix[1][1], &matrix[1][2], &matrix[1][3],
        &matrix[2][0], &matrix[2][1], &matrix[2][2], &matrix[2][3],
        &matrix[3][0], &matrix[3][1], &matrix[3][2], &matrix[3][3]
    );

    int n = sizeof(matrix[0]) / sizeof(int);

    transpose(matrix, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)

        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }

    return 0;
}