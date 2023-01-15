#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // strtok 함수가 선언된 헤더 파일

// TODO 한 번 더 풀어보기!
int main()
{
    char text[1001];
    int cnt = 0;

    scanf("%[^\n]s", text);

    char* tok = strtok(text, ",. ");

    while (tok != NULL)
    {
/*      여기서 주의할 점이 있는데
        strtok 함수에서 반환된 잘린 문자열의 포인터 ptr은 NULL일 수도 있으므로
        ptr이 NULL이 아닐 때만 strcmp 함수로 비교해야 합니다.
        만약 strcmp 함수에 NULL이 들어가면 에러가 발생합니다. */
        int ret = strcmp(tok, "the");
        if (tok != NULL && ret == 0)
            cnt++;
        
        tok = strtok(NULL, ",. ");
    }

    printf("%d\n", cnt);


    return 0;
}