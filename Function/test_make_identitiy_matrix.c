#include <stdio.h>

void set_identitiy_matrix(float (*matrix)[4], int size) {
    for (int i = 0; i < size; i++) {
        matrix[i][i] = 1.0f;
    }
}

int main() {
    float matrix[4][4] = { 0.0f, };

    int n = sizeof(matrix) / sizeof(matrix[0]);

    set_identitiy_matrix(matrix, 4);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}