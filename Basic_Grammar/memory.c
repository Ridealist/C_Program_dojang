#include <stdio.h>
#include <stdlib.h> // malloc, free 함수가 선언된 헤더 파일
#include <string.h> // meset 함수 선언

int memory()
{
    // 1. 메모리 할당
    int num1 = 20;
    int* numPtr1;

    numPtr1 = &num1;

    int* numPtr2;

    numPtr2 = malloc(sizeof(int));  // int의 크기 4바이트만큼 동적 메모리 할당

    printf("%p\n", numPtr1);
    printf("%p\n", numPtr2); // 새로 할당된 메모리 주소 출력
    
    free(numPtr2);  // 동적으로 할당된 메모리 해제

    // 2. 메모리에 값 저장
    int* ranNumPtr;

    ranNumPtr = malloc(sizeof(int));

    *ranNumPtr = 10;  // 포인터를 역참조 한 뒤 값 할당

    printf("%d\n", *ranNumPtr); // 포인터를 역참조 하여 메모리에 저장된 값 출력

    free(ranNumPtr);

    // 3. 메모리 내용 한꺼번에 설정
    long long* longPtr = malloc(sizeof(long long));

    memset(longPtr, 0x27, 8);  // 메모리를 8바이트만큼 0x27로 설정

    printf("0x%llx\n", *longPtr);  // 0x27272727....27 : 27이 8개 들어가 있음

    free(longPtr);

    // 4. null 포인터 사용
    int* nullPtr = NULL;
    
    printf("%p\n", nullPtr);

    return 0;
}