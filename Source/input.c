#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int input()
{
    // 정수 입력받기
    int num1;

    printf("정수를 입력하세요: ");
    scanf("%d", &num1);  // 표준 입력을 받아 변수에 저장

    printf("%d\n", num1);

    // 정수 2개 입력받기
    int num2, num3;
    printf("정수 두 개를 입력하세요: ");
    scanf("%d %d", &num2, &num3);

    printf("%d %d\n", num2, num3);

    float num4;

    // 정수 아닌 자료형 입력받기
    printf("실수를 입력하세요: ");
    scanf("%f", &num4);  // 실수 자료형 %f

    printf("%f\n", num4);

/*
    double num5;
    scanf("%lf", &num5); // double %lf

    long double num6;
    scanf("%Lf", &num2); // long double %Lf
*/

    // 문자 입력받기
    char c1;

    printf("문자를 입력하세요: ");
    scanf("%c", &c1); // %c는 문자 한 개만 입력 가능. 문자 여러개 입력할 경우 첫번째 문자만 저장되고 나머지는 무시됨.

    printf("%c\n", c1);

    return 0;
}