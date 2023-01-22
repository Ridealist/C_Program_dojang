#include <stdio.h>
#include <stdlib.h>

// typedef struct _Data Data;

typedef struct _Data {
    char c1;
    int num1;
} Data, *PData;    // 구조체 별칭, 구조체 포인터 별칭 정의
//      ↑ 앞에 *를 붙여서 구조체 별칭 포인터 정의


int main()
{
    // 1. 기본 자료형 변환
    // int num1 = 32;
    // int num2 = 7;
    // float num3;

    // num3 = num1 / num2;
    // printf("%f\n", num3);

    // num3 = (float)num1 / num2;
    // printf("%f\n", num3);


    // 2. 포인터 변환
    // 2-1. 큰 메모리 공간 -> 작은 메모리 공간 역참조
    int *numPtr = malloc(sizeof(int));  // 포인터에 값을 저장하려면, 메모리 할당 필수
    char *cPtr;

    *numPtr = 0x12345678;

    cPtr = (char *)numPtr;     // int 포인터 numPtr을 char 포인터로 변환. 메모리 주소만 저장됨

    printf("0x%x\n", *cPtr);   // 0x78: 낮은 자릿수 1바이트를 가져오므로 0x78
    // 포인터 주소는 같음. but, 포인터 자료형에 따라 '역참조'시 가져오는 데이터의 크기 결정

    free(numPtr);

    // 2-2. 작은 메모리 공간 -> 큰 메모리 공간 역참조
    short *numPtr2 = malloc(sizeof(short));
    int *numPtr3;

    *numPtr2 = 0x1234;

    numPtr3 = (int *)numPtr2;

    printf("0x%x\n", *numPtr3);     // 0xfdfd1234: 옆의 메모리를 침범하여 값을 가져옴
                                    // 0xfdfd는 상황에 따라서 값이 달라질 수 있음

    free(numPtr2);

    // 2-3. 포인터 다른 자료형 변환 + 역참조
    int *ptr = malloc(sizeof(int));
    
    *ptr = 0x87654321;

    printf("0x%x\n", *(char *)ptr);    // 0x21: numPtr1을 1.char 포인터로 변환한 뒤 2.역참조

    free(ptr);


    // 3. void 포인터 반환
    int num1 = 10;
    float num2 = 3.5f;
    char c1 = 'a';
    void *Ptr;

    Ptr = &num1;  // 메모리 주소를 void 포인터에 저장
    // printf("%d\n", *Ptr);  // 컴파일 에러 발생
    /*
    type_casting.c:62:20: error: argument type 'void' is incomplete
    printf("%d\n", *Ptr);
                   ^
    */
    printf("%d\n", *(int *)Ptr);     // 10: void 포인터를 int 포인터로 변환한 뒤 역참조

    Ptr = &num2;    // num2의 메모리 주소를 void 포인터 Ptr에 저장
    // printf("%f\n", *Ptr);         // 컴파일 에러
    printf("%f\n", *(float *)Ptr);   // 3.500000: void 포인터를 float 포인터로 변환한 뒤 역참조

    Ptr = &c1;      // c1의 메모리 주소를 void 포인터 Ptr에 저장
    // printf("%c\n", *Ptr);         // 컴파일 에러
    printf("%c\n", *(char *)Ptr);    // a: void 포인터를 char 포인터로 변환한 뒤 역참조
    printf("\n");


    // 4. 구조체 포인터 변환

    // typedef를 활용해 "구조체 포인터 별칭"도 정의 가능
    PData d1 = malloc(sizeof(Data));    // 구조체 포인터 별칭으로 포인터 선언
    void *ptr_str;

    d1->c1 = 'a';
    d1->num1 = 10;

    ptr_str = d1;   // void 포인터에 d1 할당. 포인터 자료형이 달라도 컴파일 경고가 발생하지 않음.

    printf("%c\n", ((Data *)ptr_str)->c1);      // 'a' : 구조체 포인터로 변환하여 멤버에 접근
    printf("%d\n", ((PData)ptr_str)->num1);     // 10  : 구조체 포인터 별칭으로 변환

    free(d1);

    return 0;
}

// typedef struct _Data {
//     char c1;
//     int num1;
// } Data;