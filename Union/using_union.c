#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // strcpy 함수가 선언된 헤더 파일

union Box {  // 공용체 정의
    short candy;   // 2바이트
    float snack;   // 4바이트
    char doll[8];  // 8바이트
};

union Data {
    char c1;
    short num1;
    int num2;
};


int main()
{
    // 1. 공용체 만들기
    union Box b1;

    printf("%zd\n", sizeof(b1));  // 8: 공용체의 전체 크기는 가장 큰 자료형의 크기

    b1.candy = 10;
    printf("%d\n", b1.candy);    // 10: 사용(출력)

    b1.snack = 60000.0f;
    printf("%f\n", b1.snack);    // 60000.00000000: 사용(출력)

    strcpy(b1.doll, "bear");
    printf("%s\n", b1.doll);     // bear: 사용(출력)

    printf("\n");
    printf("%d\n", b1.candy);    // 25954
    printf("%f\n", b1.snack);    // 4464428256607938511036928229376.000000
    printf("%s\n", b1.doll);     // bear


    // 2. 공용체와 엔디언
    union Data d1;

    d1.num2 = 0x12345678;    // 리틀 엔디언에서는 메모리에 저장될 때 78 56 34 12로 저장됨

    printf("0x%x\n", d1.num2);    // 0x12345678: 4바이트 전체 값 출력
    printf("0x%x\n", d1.num1);    // 0x5678: 앞의 2바이트 값만 출력
    printf("0x%x\n", d1.c1);      // 0x78: 앞의 1바이트 값만 출력

    printf("%zd\n", sizeof(d1));   // 4: 공용체의 전체 크기는 가장 큰 자료형의 크기
    printf("\n");
 
     
    // 3. 공용체 포인터 선언, 메모리 할당
    union Box *ptr = malloc(sizeof(union Box));

    printf("%zd\n", sizeof(union Box));  // 8: 공용체의 전체 크기는 가장 큰 자료형의 크기

    strcpy(ptr->doll, "bear");

    printf("%d\n", ptr->candy);    // 25954
    printf("%f\n", ptr->snack);    // 4464428256607938511036928229376.000000
    printf("%s\n", ptr->doll);     // bear

    free(ptr);

    return 0;
}