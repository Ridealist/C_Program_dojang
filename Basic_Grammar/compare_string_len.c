#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int compareStringLength()
{
    //1. 문자열 길이 구하기
    char* s1 = "Hello";
    char s2[10] = "Hello";

    //strlen(문자열포인터)
    //strlen(문자배열)
    printf("%d\n", strlen(s1)); // 5 : NULL 부분 제외 순수 문자열 길이 반환
    printf("%d\n", strlen(s2));  // 5 : '배열의 크기'와 '문자열의 길이'는 무관!
    printf("\n");


    //2. 문자열 비교하기

    //strcmp(문자열1, 문자열2) -> 두 문자열이 같은지 비교
    // -1 : ASCII 코드 기준으로 뒤 문자열(문자열2)이 클 때
    // 0 : 같을 때
    // 1 : 앞 문자열(문자열1)이 클 때
    // 문자열 첫 번째 문자부터 차례대로 비교. 비교 기준은 ASCII 코드.
    int ret = strcmp(s1, s2);

    printf("%d\n", ret); // 0 : 문자열이 같으면 0 반환

    printf("%d\n", strcmp("aaa", "aaa")); // aaa = 97 97 97, 같으므로 0 반환
    printf("%d\n", strcmp("aab", "aaa")); // aab = 97 97 98, 앞 문자열이 크므로 1 반환
    printf("%d\n", strcmp("aab", "aac")); // aac = 97 97 99 뒤 문자열이 크므로 -1 반환

    // 사용자가 입력한 두 문자열 비교

    char str1[20];
    char str2[20];

    scanf("%s %s", str1, str2);

    int diff = strcmp(str1, str2);

    // 맥에서는 ASCII 코드 차이 반환
    //if (diff < -1)
    //    printf("'%s' 문자열이 더 큽니다.", str2);
    //else if (diff == 0)
    //    printf("두 문자열이 같습니다.");
    //else
    //    printf("'%s' 문자열이 더 큽니다.", str1);

    switch (diff)
    {
    case 0:
        printf("두 문자열이 같습니다.");
        break;
    case -1:
        printf("'%s' 문자열이 더 큽니다.", str2);
        break;
    case 1:
        printf("'%s' 문자열이 더 큽니다.", str1);
        break;
    }


    return 0;
}