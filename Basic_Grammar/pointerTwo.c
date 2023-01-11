#include <stdio.h>
#include <stdlib.h>

int pointerTwo()
{
    // 디버거 활용해보기
    /*
    int* numPtr;
    int num1 = 10;

    numPtr = &num1;

    *numPtr = 20;

    printf("%d\n", *numPtr);
    printf("%d\n", num1);

    */

    // 다양한 자료형의 포인터 선언하기
    long long* numPtr1;
    float* numPtr2;
    char* cPtr1;

    long long num1 = 10;
    float num2 = 3.5f;
    char c1 = 'a';

    numPtr1 = &num1;
    numPtr2 = &num2;
    cPtr1 = &c1;

    printf("%lld\n", *numPtr1);
    printf("%f\n", *numPtr2);
    printf("%c\n", *cPtr1);

    // 상수 포인터
    // 1. pointer to constant
    const int num3 = 30;
    const int* numPtr;  // 상수에 대해서 포인터도 const로 선언해줘야 함

    numPtr = &num3;
    // *numPtr = 20; -> 컴파일 에러, 메모리 주소에 저장된 값을 변경할 수 없다

    // 2. constant pointer
    int num5 = 10;
    int num6 = 20;
    int* const numPtr10 = &num6;

    // numPtr10 = &num6; -> 컴파일 에러, 다른 포인터(메모리 주소)를 할당할 수 없다

    // 3. constant pointer to constant
    const int num10 = 10;
    const int num20 = 20;
    const int* const numPtr20 = &num1;

    // *numPtr20 = 30;  메모리 주소에 저장된 값 변경 불가
    // numPtr20 = &num20;  메모리 주소 변경 불가. 둘 다 불가

    // void 포인터
    int numten = 10;
    char a1 = 'a';
    int* numtenPtr = &num1;
    char* aPtr = &a1;

    void* ptr;

    // 포인터 자료형이 달라도 컴파일 경고 발생하지 않음
    ptr = numtenPtr;  // void 포인터에 int 포인터 저장
    ptr = aPtr;

    numtenPtr = ptr;
    aPtr = ptr;


    // 이중 포인터
    int* singlePtr;
    int** doublePtr;
    int randomNum = 10;

    singlePtr = &randomNum; // randomNum 메모리 주소 저장

    doublePtr = &singlePtr; // singlePtr의 메모리 주소 저장

    printf("%d\n", **doublePtr);


    // 잘못된 포인터 사용
    // 포인터는 메모리 주소를 저장하는 것. 값을 직접 저장하면 안 됨.
    int* wrongPtr = 0x100;

    printf("%d\n", *wrongPtr);

    return 0;
}