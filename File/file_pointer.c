#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // 1. 파일 크기 구하기
    int size;

    FILE *fp = fopen("hello.txt", "r");

    // int fseek(파일포인터, 이동할 크기, 기준점)   -> return 성공: 0, 실패: -1 반환
    // 기준점에서 이동할 크기(거리) 만큼 파일 포인터 이동시킴
    fseek(fp, 0, SEEK_END); // 파일 포인터를 파일의 끝으로 이동 시킴

    // long ftell(파일포인터)   -> return 파일 포인터의 현재 위치 반환, 실패하면 -1 반환
    size = ftell(fp);   // 파일 포인터의 현재 위치를 얻음

    printf("%d\n", size);


    // 2. 파일 크기만큼 파일 읽기
    char *buffer;
    int count;

    buffer = malloc(sizeof(char) * size + 1);   // 파일 크기 + 1바이트(문자열 마지막 NULL)만큼 동적 메모리 할당

    memset(buffer, 0, sizeof(char) * size + 1); // 메모리 초기화

    // buffer = calloc(0, sizeof(char));

    // rewind(fp); -> 파일 포인터를 앞으로 이동시키는 또 다른 함수
    fseek(fp, 0, SEEK_SET);     // 다시 파일 포인터를 파일의 가장 앞쪽에 위치 시킴
    // size_t fread(버퍼, 읽기크기, 읽기횟수, 파일포인터) -> return 성공한 읽기 횟수 반환, 실패하면 읽기 횟수보다 작은 값 반환
    count = fread(buffer, size, 1, fp);
    
    printf("%s: %d, count : %d\n", buffer, size, count);

    fclose(fp);
    free(buffer);


    // 3. 파일을 부분적으로 읽고 쓰기
    // 3-1. 부분 읽기
    char buf[20] = { 0, };

    fp = fopen("hello.txt", "r");

    fseek(fp, 2, SEEK_SET);     // he'l' -> fp[2]를 가리키고 있음
    fread(buf, 3, 1, fp);    // 읽기 크기 3만큼 : fp[2] ~ fp[4], llo 까지

    printf("\n");
    printf("%s\n", buf);

    memset(buf, 0, 10);

    fseek(fp, 3, SEEK_CUR);     // hello',' world! -> fp[5] 가 아님!
                                // fread() 함수로 읽으면서 fp도 이동함. 즉 fp[2 + 3] = fp[5]에서 시작
                                // fp[5 + 3] = fp[8]

    fread(buf, 4, 1, fp);    // fp[8] ~ fp[11],  : orld 

    printf("%s\n", buf);

    fclose(fp);

    // 3-2. 부분 쓰기
    char *str1 = "abcd";

    fp = fopen("hello.txt", "r+");   // 읽기+쓰기 모드

    fseek(fp, 3, SEEK_SET);
    // fwrite(버퍼, 쓰기크기, 쓰기횟수, 파일포인터) : return 성공한 쓰기 횟수, 실패하면 지정된 쓰기 횟수보다 작은 값
    // 문자열 길이만큼 문자열을 파일에 저장
    fwrite(str1, strlen(str1), 1, fp);  // Hel'l'o, world!
                                        // Helabcdworld!
    rewind(fp);
    fread(buffer, 20, 1, fp);

    printf("%s\n", buffer);

    fclose(fp);


    // 4. 제한된 버퍼로 파일 전체 읽기
    // 파일 크기가 아주 클 때(GB), 제한된 버퍼(MB)로 파일 전체를 읽는 방법

    char buffer2[5] = { 0, };   // 문자열 데이터 4바이트 + 1('\0')
    int cnt = 0;
    int total = 0;

    fp = fopen("hello.txt", "r");


    // int feof(파일포인터) : 파일의 끝이면 1, 아니면 0을 반환
    while (feof(fp) == 0)   // 파일포인터가 끝이 아닐때까지 계속 반복
    {
        cnt = fread(buffer2, sizeof(char), 20, fp);  // 1바이트씩 4번 읽기
        printf("%s", buffer2);
        memset(buffer2, 0, 5);
        total += cnt;   // 읽은 횟수 누적
    }

    printf("\ntotal: %d\n", total);

    fclose(fp);
    

    return 0;
}