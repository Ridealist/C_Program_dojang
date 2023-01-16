#define _CRT_SECURE_NO_WARNINGS    // sprintf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>     // sprintf 함수가 선언된 헤더 파일

int main()
{
    // 1. 정수를 문자열로 변환
    char dec[10];       // 변환한 문자열을 저장할 배열
    char hex[10];
    char Hex[10];
    int num1 = 283;    // 283은 정수

    // sprintf(문자열, "%d", 정수)
    // sprintf(문자열, "%x", 정수)
    // sprintf(문자열, "%X", 정수)
    sprintf(dec, "%d", num1);    // %d를 지정하여 정수를 문자열로 저장
    sprintf(hex, "0x%x", num1);  // %x 지정하여 정수를 16진법 표기 문자열로 저장, 0x로 16진수 표현
    sprintf(Hex, "0x%X", num1);  // %X 지정하여 알파벳 대문자 변환

    // dec, hex 모두 '문자열'이므로 %s 서식지정 해야함.
    printf("%s\n", dec);         // 283
    printf("%s\n", hex);         // 0x11b
    printf("%s\n", Hex);         // 0x11B
    printf("\n");


    // 2. 실수를 문자열로 변환
    char s1[10];
    // e 지수형태로 나타낼때는 메모리 충분히 할당
    char s2[20]; //destination buffer has size 10, but format string expands to at least 12 -> 3.823160e+01
    float fnum1 = 38.2316f;

    // sprintf(문자열, "%f", 실수)
    sprintf(s1, "%f", fnum1);
    sprintf(s2, "%e", fnum1);

    // 모두 '문자열'이므로 %s 서식지정 해야함.
    printf("%s\n", s1);
    printf("%s\n", s2);

    return 0;
}