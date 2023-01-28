#include <stdio.h>
#include <string.h>

#pragma pack(push, 1)   // 1바이트로 크기 정렬
struct Data {
    short num1; // 2바이트
    short num2;
    short num3;
    short num4;
};
#pragma pack(pop)

#pragma pack(push, 1)   // 1바이트로 크기 정렬
struct DataTwo {
    char c1;
    short num1;
    int num2;
    char str[20];
};
#pragma pack(pop)

int main() {
    // 1. 파일에 구조체 쓰기
    // 1-1. 일정한 멤버 크기 구조체
    struct Data d1;

    d1.num1 = 100;
    d1.num2 = 200;
    d1.num3 = 300;
    d1.num4 = 400;

    FILE *fp = fopen("data.bin", "wb");     // 파일을 쓰기/바이너리 모드 열기

    // "구조체 포인터 주소"이므로 & 연산자 필요
    fwrite(&d1, sizeof(d1), 1, fp);     // 구조체 내용 파일에 저장

    fclose(fp);

    // 1-2. 다양한 멤버 크기 구조체
    struct DataTwo D1;
    memset(&D1, 0, sizeof(D1));

    D1.c1 = '0';
    D1.num1 = 24370;
    D1.num2 = -1658379460;
    strcpy(D1.str, "Hello, world!");

    fp = fopen("data2.bin", "wb");

    fwrite(&D1, sizeof(D1), 1, fp);

    fclose(fp);


    // 2. 파일에서 구조체 읽기
    struct DataTwo D2;

    fp = fopen("data2.bin", "rb");   // 파일을 읽기+바이너리 모드로 열기

    fread(&D2, sizeof(struct DataTwo), 1, fp);    

    printf("%c %d %d %s\n", D2.c1, D2.num1, D2.num2, D2.str);

    fclose(fp);

    return 0;
}