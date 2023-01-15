#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // 1. 문자열 복사하기
    // 1-1. 배열로 선언된 문자열 복사하기
    //char s1[10] = "Hello";
    //char s2[10];

    //// strcpy(대상문자열, 원본문자열);
    //strcpy(s2, s1); // 복사된 결과가 저장될 배열의 크기는 반드시 NULL까지 들어갈 수 있어야 함

    //printf("%s\n", s2);

    // 1-2. 문자열 포인터에 문자열 복사하기
    char* s1 = "Hello";
    // char* s2 = "";  -> 자동 할당된 문자열 리터럴 메모리는 읽기 전용이라 복사(원본을 덮어'쓰기') 불가능!
    char* s2 = malloc(sizeof(char) * 10);  // s2 포인터에 동적 메모리 할당

    strcpy(s2, s1);  // s1 문자열을 s2로 복사

    printf("%s\n", s2);
    printf("\n");

    free(s2);


    // 2. 문자열 붙이기
    // 2-1. 배열 선언된 문자열 붙이기
    //char str1[10] = "world";
    //char str2[20] = "hello";  // str2 뒤에 붙일 것으로 배역 크기 크게 만듦

    //// strcat(최종 문자열, 붙일 문자열)
    //strcat(str2, str1);  // str2 뒤에 str1을 붙임

    //printf("%s\n", str2);

    // 2-2. 포인터로 할당된 문자열 붙이기
    char* str1 = "world";
    // 1. 쓰기가 가능하도록 malloc으로 동적 메모리 할당
    // 2. 문자열 붙일 수 있도록('\0'까지 고려) 충분한 크기 할당
    char* str2 = malloc(sizeof(char) * 20);

    // 메모리가 할당된 문자열에는 문자열을 = 연산자로 할당 불가능
    // strcpy로 메모리에 문자열 복사!
    strcpy(str2, "Hello");  // 3. str2에 Hello 문자열 복사

    strcat(str2, str1);  // 4. 문자열 붙이기

    printf("%s\n", str2);

    free(str2);


    // 3. 배열 형태 문자열 -> 문자열 포인터에 복사하기
    //char char_array[20] = "Hello world!";
    //char* ptr = malloc(sizeof(char) * 25);

    //strcpy(ptr, char_array);

    //printf("%s\n", ptr);

    //free(ptr);


    // 4. 배열 형태 문자열을 포인터에 붙이기
    char char_array[20] = "Hello world!";
    char* ptr = malloc(sizeof(char) * 25);

    strcpy(ptr, "Wow, ");

    strcat(ptr, char_array);

    printf("%s\n", ptr);

    free(ptr);

    return 0;
}