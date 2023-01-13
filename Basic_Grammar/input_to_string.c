#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int inputToString()
{
    // 1. 입력 값을 배열 형태의 문자열에 저장하기
    // char s1[30];

    // printf("문자열을 입력하세요: ");

    // scanf("%s", &s1); -> 배열은 포인터처럼 이미 주소를 담고 있음. &(empersand) 연산자 불필요
    // scanf("%s", s1);
    // scanf("%[^\n]s", s1);  // 공백까지 포함하여 문자열 입력받기

    // printf("%s\n", s1);


    // 2. 입력 값을 문자열 포인터에 저장하기
    // 문자열이 들어갈 공간을 따로 마련해야 함!
    //char* strPtr = malloc(sizeof(char) * 20);

    //scanf("%[^\n]s", strPtr);  // 포인터이므로 &를 붙이지 않고 그대로 넣음

    //printf("%s\n", strPtr);

    //free(strPtr);


    // 3. 문자열 여러 개 입력받기
    char str1[10];
    char str2[10];

    printf("문자열 두 개 입력하세요: ");
    scanf("%s %s", str1, str2);

    printf("%s\n", str1);
    printf("%s\n", str2);


    return 0;
}