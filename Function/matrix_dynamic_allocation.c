#include <stdio.h>
#include <stdlib.h>

void allocMatrix(short*** ptr, int m, int n, int type_size) {
    *ptr = malloc(sizeof(void*) * m);  // ptr을 역참조한 뒤 메모리 할당
    for (int i = 0; i < m; i++) {
        (*ptr)[i] = malloc(type_size * n);  // ptr을 먼저 역참조한 뒤 인덱스로 접근
    }
}

void freeMatrix(short*** ptr, int m) {
    for (int i = 0; i < m; i++) {
        free((*ptr)[i]);
    }
    free(*ptr);
}

int main()
{
    short **matrix;

    // m: 3, n: 3, 요소의 자료형 short
    allocMatrix(&matrix, 3, 3, sizeof(short));

    matrix[0][2] = 10;
    matrix[1][1] = 20;
    printf("%d %d\n", matrix[0][2], matrix[1][1]);

    freeMatrix(&matrix, 3);

    return 0;
}