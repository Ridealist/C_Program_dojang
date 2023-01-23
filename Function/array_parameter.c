#include <stdio.h>

void printArray(int arr[], int count) {  // 배열의 포인터와 요소의 개수 받음
    // arr는 배열의 메모리 주소를 담고 있는 포인터. 배열의 크기는 알 수 없으므로 별도의 변수로 크기를 받아야 함.
    for (int i = 0; i< count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printArrayPointer(int *arr, int count) {  // 매개변수를 포인터로 지정해 배열을 받아도 동일.
    for (int i = 0; i< count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
배열 매개변수 요소의 최소 개수 지정 가능

반환값자료형 함수이름(자료형 매개변수[static 최소개수]) {

}
*/
void printArrayLimit(int arr[static 5], int count) {  // 매개변수를 포인터로 지정해 배열을 받아도 동일.
    for (int i = 0; i< count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void setElement(int arr[]) {
    arr[4] = 1000;  // 배열의 포인터에 접근해 값을 수정함 -> 메모리에서 값 수정이 일어남
}

void swap_element(int arr[], int first, int second) {
    int temp;

    temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

/*
함수이름(자료형 매개변수[][가로크기])

함수이름(자료형 (*매개변수)[가로크기])  -> 두 경우 모두 가로크기를 선언해야 함
*/

// void print2DArray(int (*arr)[5], int row, int col) -> 동일!
// 매개변수를 포인터로 만든 뒤 가로 크기 지정
void print2DArray(int arr[][5], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


int main() {
    // 1. 배열 매개변수 사용
    int numArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int numArrThree[3] = { 1, 2, 3 };

    // setElement(numArr);  ->   // 1 2 3 4 1000 6 7 8 9 10

    swap_element(numArr, 0, 9);  // ->  10 2 3 4 5 6 7 8 9 1

    printArrayPointer(numArr, sizeof(numArr) / sizeof(int));

    // printArrayLimit(numArrThree, sizeof(numArrThree) / sizeof(int));
    /*
    array_parameter.c:49:5: warning: array argument is too small;
    contains 3 elements, callee requires at least 5 [-Warray-bounds]
    */

    printArrayLimit(numArr, sizeof(numArr) / sizeof(int)); // -> OK!
    printf("\n");

    // 2. 2차원 배열 매개변수 사용
    int numArr2D[2][5] = {
        { 1, 2, 3, 4, 5},
        { 6, 7, 8, 9, 10}
    };

    int row = sizeof(numArr2D) / sizeof(numArr2D[0]);
    int col = sizeof(numArr2D[0]) / sizeof(int);

    print2DArray(numArr2D, row, col);

    return 0;
}