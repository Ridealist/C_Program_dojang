#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int count;
    char buffer[5] = { 0, };

    FILE *src = fopen("hello.txt", "r");
    FILE *dest = fopen("hello2.txt", "w");

    while (feof(src) == 0)
    {
        count = fread(buffer, sizeof(char), 4, src);
        printf("%s", buffer);

        // TODO 다양한 형식의 파일 읽기 가능!
        // printf(dest, "%s", buffer);
        // fputs(buffer, dest);
        // fwrite(buffer, strlen(buffer), 1, dest);
        fwrite(buffer, sizeof(char), count, dest);

        // 4가 아닌 count 횟수만큼 저장하는 이유는
        // 파일이 4바이트 단위로 딱 끊어지지 않고 약간 남는 경우가 있기 때문
        // 즉, 파일 끝부분에서 3바이트만큼 읽었다면 복사되는 파일의 끝에도 3바이트를 써줄 수 있습니다.
        memset(buffer, 0, 5);
    }

    fclose(dest);
    fclose(src);

    return 0;
}