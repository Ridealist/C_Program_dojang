#define _CRT_SECURE_NO_WARNIGNS
#include <stdio.h>
#include <string.h>
#include <stdbool.h> // bool 자료형이 선언된 헤더 파일

int main()
{
    // 1. 회문 판별
    // char word[30];
    // int length;
    // bool isPalindrome = true;

    // printf("단어를 입력해주세요 : ");
    // scanf("%s", word);

    // length = strlen(word);

    // for (int i = 0; i < length / 2; i++)
    // {
    //     if (word[i] != word[length - 1 - i])
    //     {
    //         isPalindrome = false;
    //         break;
    //         // printf("입력된 단어는 회문이 아닙니다.\n");
    //         // return 0;
    //     }
    // }

    // printf("%d\n", isPalindrome); // boolean값은 true = 1, false = 0 정수값 반환
    // printf("입력된 단어는 회문입니다.\n");
    // printf("단어의 크기: %lu\n", strlen(word));


    // 2. N-gram 만들기
    // char word[30];
    // int length;

    // printf("단어를 입력해주세요 : ");
    // scanf("%s", word);

    // length = strlen(word);

    // // 2-gram : 문자열 끝에서 한 글자 앞까지만 반복함
    // for (int i = 0; i < length - 1; i++)
    // {
    //     printf("%c%c\n", word[i], word[i + 1]);
    // }

    // 단어 단위 N-gram
    char text[100];  // = "this is c language";
    char *tokens[30] = { NULL, };  // 자른 문자열 포인터를 보관할 배열, NULL로 초기화
    int idx = 0;
    char* ptr;

    printf("문장을 입력해주세요 : ");
    scanf("%[^\n]s", text);

    ptr = strtok(text, " ");  // 공백 기준 문자열 자르기, 포인터 반환

    while (ptr != NULL)
    {
        tokens[idx] = ptr;
        idx++;

        ptr = strtok(NULL, " ");  // 다음 문자열 잘라서 포인터 반환
    }

    for (int i = 0; i < idx - 1; i++)
    {
        printf("%s %s\n", tokens[i], tokens[i + 1]);
    }

    return 0;
}