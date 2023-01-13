#include <stdio.h>

void swap(int* ptr_a, int* ptr_b) {
    int temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
}

int mainSwap() {

    int a = 5;
    int b = 10;

    printf("a�� ��: %d", a);
    printf("\nb�� ��: %d", b);

    swap(&a, &b);

    printf("\n\nafter swap\n\n");

    printf("a�� ��: %d", a);
    printf("\nb�� ��: %d", b);

    return 0;
}