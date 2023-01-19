#include <stdio.h>

/*
struct 구조체이름 {
    정수자료형 멤버 이름 : 비트수;
}
*/
struct Flags {
    unsigned int a : 1;  // a는 1비트 크기
    unsigned int b : 3;  // b는 3비트 크기
    unsigned int c : 7;  // c는 7비트 크기
};

int main()
{
    // 1. 구조체 비트 필드
    // struct Flags f1;

    // f1.a = 1;   // 1   : 0000 0001, 비트 1개
    // f1.b = 15;  // 15  : 0000 1111, 비트 4개 
    // f1.c = 255; // 255 : 1111 1111, 비트 8개

    // printf("%u\n", f1.a);    //   1:        1, 비트 1개만 저장됨
    // printf("%u\n", f1.b);    //   7:      111, 비트 3개만 저장됨
    // printf("%u\n", f1.c);    // 127: 111 1111, 비트 7개만 저장됨

    // printf("%zd\n", sizeof(struct Flags));    // 4: 멤버를 unsigned int로 선언했으므로 4


    // 2. 비트 필드와 공용체 함께 사용
    struct Flags {
        union {
            struct {
                unsigned short a : 3;
                unsigned short b : 2;
                unsigned short c : 7;
                unsigned short d : 4;
            };
            unsigned short e;
        };
    };

    struct Flags f1 = { 0, };

    f1.a = 4;  //  4 : 0000 0100
    f1.b = 2;  //  2 : 0000 0010
    f1.c = 80; // 80 : 0101 0000
    f1.d = 15; // 15 : 0000 1111

    printf("%u\n", f1.e);  //  1111 1010 0001 0100 : 64020 


    return 0;
}