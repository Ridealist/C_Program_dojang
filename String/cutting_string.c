#define _CRT_SECURE_NO_WARNINGS    // strtok 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // strtok 함수가 선언된 헤더 파일

int main()
{
    // 1. 문자를 기준으로 문자열 자르기
    char s1[30] = "The Little Prince";  // 크기가 30인 char형 배열을 선언하고 문자열 할당
    printf("원본 문자열 포인터 : %p\n", s1);

    // string + tokenize = str tok
    // strtok(대상문자열, 기준문자)
    // 기준문자를 찾고 그것을 NULL로 채움
    // 자른 문자열 반환, 더 자를 문자열이 없으면 NULL 반환
    char *ptr = strtok(s1, " ");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환

    while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
    {
        printf("%s\n", ptr);          // 자른 문자열 출력
        printf("다음 문자열 포인터 : %p\n", ptr);
        // 직전 strtok 함수에서 처리했던 문자열에서 잘린 만큼 다음 문자로 이동한 뒤 수행
        ptr = strtok(NULL, " ");      // 다음 문자열을 잘라서 포인터를 반환
    }


    // 2. 문자열 포인터 자르기
    // 문자열 포인터에 문자열 리터럴을 할당할 경우 자르기 불가!
    // 원본 문자열 리터럴은 읽기 전용. NULL문자로 변경 불가!
    char* s2 = malloc(sizeof(char) * 30);

    strcpy(s2, "The Little Prince");  // 문자열 복사

    char* str_ptr = strtok(s2, " ");  // 동적 메모리에 들어있는 문자열은 자르기 가능!

    free(s2);


    // 3. 날짜와 시간 값 자르기
    char date[30] = "2015-06-10T15:32:19";

    // 기준 문자 한 번에 여러 개 지정 가능!
    // 기준 문자 여러개 넣어주면 됨
    char* date_ptr = strtok(date, "-T:");  // -, T, : 기준으로 문자열 자름

    while (date_ptr != NULL)
    {
        printf("%s\n", date_ptr);
        date_ptr = strtok(NULL, "-T:");
    }
    

    // 4. 자른 문자열 보관하기
    char string[30] = "The Little Prince"; // s1은 원본 문자열이 변경되었으므로 사용 불가. 다시 새로운 문자열 선언.
    char* sArr[10] = { NULL, };
    // 문자열 포인터 배열 선언, NULL로 초기화
    // NULL 뒤에 (,콤마) 붙이면 모든 요소 NULL로 초기화

    int i = 0;  // 문자열 포인터 배열 인덱스 변수 선언

    
    char* Ptr = strtok(string, " ");
    while (Ptr != NULL)
    {
        sArr[i] = Ptr;
        i++;

        Ptr = strtok(NULL, " ");
    }

    for (int i = 0; i < 10; i++)
    {
        if (sArr[i] != NULL)
            printf("%s\n", sArr[i]);
    }

    return 0;
}