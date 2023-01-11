#include <stdio.h>

int main()
{
    /*
    역참조 연산자 "*"
    주소 연산자 "&"

    포인터 = 메모리 주소

    pointer to int = address of int
    */


    // 1. 메모리 주소 구하기
    int num2 = 10;

    printf("%p\n", &num2);
    printf("\n");

    // 2. 포인터
    int *numPtr;  // 포인터 변수 선언
    int num1 = 10;
    char char1 = 'c';

    numPtr = &num1;  // num1의 메모리 주소를 포인터 변수에 저장

    printf("%p\n", numPtr); // 포인터 변수 numPtr의 값 출력

    printf("%p\n", &num1); // 변수 num1의 메모리 주소 출력

    printf("%lu\n", sizeof(numPtr)); // 64비트 int 포인터는 8바이트
    printf("%lu\n", sizeof(char *)); // 64비트 char 포인터는 8바이트
    printf("%lu\n", sizeof(num1)); // 32비트 int 변수값은 4바이트
    printf("%lu\n", sizeof(char1)); // 8비트 char 변수값은 1바이트
    printf("\n");

    // 3. 역참조
    int *numPtr2;
    int num3 = 10;

    numPtr2 = &num3;

    *numPtr2 = 20; // 역참조 연산자로 메모리 주소에 접근하여 20을 저장

    printf("%d\n", *numPtr2); // 역참조 연산자로 num3 메모리 주소로 접근하여 값을 가져옴
    printf("%d\n", num3);

    return 0;
}