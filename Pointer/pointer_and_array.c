#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
오프셋 역참조(dereference w/ offset) []
어떤 '주소'에서 부터 지정된 스텝을 '오프셋'시킨 상태에서 '역참조'하는 연산자이다.

즉,  arr[ i ]  와   * ( arr + i ) 가 같은 뜻이 된다.
*/


int pointerAndArray()
{
    // 0. 가변 길이 배열(원하는 크기만큼 배열을 생성하는 기능)
    //int size;
    //
    //scanf("%d", &size);  // 배열의 크기 입력 받기

    //int numArr[size];  // 입력받은 크기로 배열 생성
    // -> 가변 길이 배열을 지원하지 않아 컴파일 에러 발생


    // 1. 포인터에 할당된 메모리를 배열처럼 사용
    int* numPtr = malloc(sizeof(int) * 10);  // int 10개 크기만큼 동적 메모리 할당

    // numPtr[0] = 10;  // 배열처럼 인덱스로 접근하여 값 할당
    numPtr[0] = 10;
    numPtr[9] = 20;
    // numPtr[10] = 30;
     
    printf("%p\n", numPtr);
    printf("%p\n", numPtr + 1);
    printf("%d\n", numPtr[0]);  // 배열처럼 인덱스로 접근하여 값 출력
    //printf("%d\n", *numPtr[0]);  // 배열처럼 인덱스로 접근하여 값 출력
    printf("%d\n", numPtr[9]);

    free(numPtr);  // 동적으로 할당한 메모리 해제


    // 2. 입력한 크기만큼 메모리 할당해 배열 생성
    //int size;

    //printf("\n배열의 크기를 입력하세요 : ");
    //scanf("%d", &size);

    //int* ptr = malloc(sizeof(int) * size);

    //for (int i = 0; i < size; i++)
    //{
    //    ptr[i] = i;
    //}

    //printf("\n결과 출력\n");
    //for (int i = 0; i < size; i++)
    //{
    //    printf("%d\n", ptr[i]);
    //}

    //free(ptr);


    // 3. 포인터에 할당된 메모리를 2차원 배열처럼 사용
    //int** m = malloc(sizeof(int*) * 3); // 이중 포인터에 "(int 포인터 크기)" * (세로 크기)만큼 동적 메모리 할당.

    //for (int i = 0; i < 3; i++)
    //{
    //    m[i] = malloc(sizeof(int) * 4);  // int 포인터에 (int 크기) * (가로 크기)만큼 동적 메모리 할당
    //}

    //m[0][0] = 1;
    //m[1][2] = 5;
    //m[2][3] = 14;

    //printf("%d\n", m[0][0]);
    //printf("%d\n", m[1][2]);
    //printf("%d\n", m[2][3]);

    //for (int i = 0; i < 3; i++)
    //{
    //    free(m[i]);  // 가로 공간 메모리 해제
    //}

    //free(m);  // 세로 공간 메모리 해제


    // 4. 입력한 크기만큼 메모리를 할당하여 2차원 배열 생성

    int row, col;

    printf("행렬의 행 길이와 열 길이를 입력해주세요 : ");
    scanf("%d %d", &row, &col);
    printf("\n");

    int** m = malloc(sizeof(int*) * row);

    for (int i = 0; i < row; i++)
    {
        m[i] = malloc(sizeof(int) * col);
    }

    for (int j = 0; j < row; j++)
    {
        for (int k = 0; k < col; k++)
        {
            m[j][k] = j + k;
        }
    }

    for (int j = 0; j < row; j++)
    {
        for (int k = 0; k < col; k++)
        {
            printf("%d ", m[j][k]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++) {
        free(m[i]);
    }

    free(m);

    return 0;
}