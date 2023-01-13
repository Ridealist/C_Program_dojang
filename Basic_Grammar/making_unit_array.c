#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main() {
//    int size;
//
//    scanf("%d", &size);
//
//    int** m = malloc(sizeof(int*) * size);
//
//    for (int row = 0; row < size; row++)
//    {
//        m[row] = malloc(sizeof(int) * size);
//    }
//
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            if (i == j)
//            {
//                m[i][j] = 1;
//                continue;
//            }
//            m[i][j] = 0;
//        }
//    }
//
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            printf("%d ", m[i][j]);
//        }
//        printf("\n");
//    }
//
//    for (int row = 0; row < size; row++)
//    {
//        free(m[row]);
//    }
//
//    free(m);
//
//    return 0;
//}


int making_unit_array() {
    int n;

    scanf("%d", &n);

    int** m = malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++)
    {
        m[i] = malloc(sizeof(int) * n);
        memset(m[i], 0, sizeof(int) * n);
    }

    for (int i = 0; i < n; i++)
    {
        m[i][i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(m[i]);
    }

    free(m);

    return 0;
}