#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n1. 서식을 지정하여 배열 형태로 문자열 만들기\n");
    char s1[20]; // 문자열을 저장할 빈 배열을 '버퍼(buffer)'라고 부름

    // sprintf(배열, 서식, 값1, 값2, ...)
    sprintf(s1, "Hello, %s", "world!");  // "Hello, %s"로 서식을 지정하여 s1에 저장

    printf("%s\n", s1);

    char s2[30];

    // 서식지정자를 이용해 다양한 자료형도 문자열로 만들기 가능
    // 문자, 정수, 실수, 지수를 문자열로 만듦
    sprintf(s2, "%c %d %.2f %e", 'a', 10, 3.2f, 1.12345e-21f);

    printf("%s\n", s2);


    printf("\n2. 서식을 지정하여 문자열 포인터에 문자열 만들기\n");
    char* ptr1 = malloc(sizeof(char) * 20); // 동적 메모리 할당 -> 문자열 생성할 메모리 공간 : '버퍼'
    char* ptr2 = malloc(sizeof(char) * 30); // 동적 메모리 할당 -> 문자열 생성할 메모리 공간 : '버퍼'

    // sprintf(문자열포인터, 서식지정자, 값1, 값2, ...)
    sprintf(ptr1, "Hello, %s", "world!");
    sprintf(ptr2, "%c %d %.2f %e", 'a', 10, 3.2f, 1.12345e-21f);

    printf("%s\n", ptr1);
    printf("%s\n", ptr2);

    free(ptr1);
    free(ptr2);

    return 0;
}