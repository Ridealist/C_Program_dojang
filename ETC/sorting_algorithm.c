#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int size) {
    
    for (int i = 0; i < size; i++)      // 요소의 개수만큼 반복
    {
        for (int j = 0; j < size - 1 - i; j++)  // 한번 looping 돌 때마다 마지막 원소는 정렬됨
        {                                       // 현재 순회에서 가장 큰 원소를 찾아서 제일 오른쪽에 배치하는 것이므로
            if (arr[j] > arr[j + 1])            // 다음 순회에서는 앞에서 정렬된 것을 빼고 나머지까지만 정렬하면 됨
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}


int compare_ascend(const void *a, const void *b) {     // 오름차순 비교 함수 구현

    int num1 = *(int *)a;   // void 포인터를 int 포인터로 변환한 뒤 역참조해서 값 가져옴
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;

    else 
        return 0;
}


int compare_descend(const void *a, const void *b) {     // 내림차순 비교 함수 구현

    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return 1;
    
    if (num1 > num2)
        return -1;

    else 
        return 0;
}

// 반드시! 1. int형 반환값  2. const void * 매개변수 2개
int compare_compress(const void *a, const void *b) {

    // return *(int *)a - *(int*)b;  // 오름차순       값이 1,-1 필요 없이, 양수 음수이기만 하면 됨.
    
    return *(int *)b - *(int*)a;  // 내림차순
}


int main() {
    // 1. 거품 정렬
    int numArr[] = { 8, 4, 2, 5, 3, 7, 10, 1, 6, 9, 1, 2, 3, 12, 213, 2, 231, 1, 321, 2, 31 };   // 정렬되지 않은 배열
 
    // bubble_sort(numArr, sizeof(numArr) / sizeof(int));    // 거품 정렬 함수 호출

    // 정렬할 배열/정렬할 배열 메모리주소, 요소 개수, 요소 크기, 비교 함수
    qsort(numArr, sizeof(numArr) / sizeof(int), sizeof(int), compare_compress);  // 함수 포인터(메모리 주소)를 넣어주는 것


    for (int i = 0; i < sizeof(numArr) / sizeof(int); i++)
    {
        printf("%d ", numArr[i]);    // 1 2 3 4 5 6 7 8 9 10
    }

    printf("\n");


    // 2. 퀵 정렬 함수 사용하기



    return 0;
}