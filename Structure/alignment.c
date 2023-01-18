#include <stdio.h>
#include <stddef.h>

struct PacketHeader {
    char flags;
    int seq;
};

#pragma pack(push, 1)  // 1 바이트 크기로 정렬
struct PacketHeaderPack {
    char flags;
    int seq;
};
#pragma pack(pop)  // 정렬 설정을 이전 상태로 되돌림

#pragma pack(push, 2)  // 2 바이트 크기로 정렬
struct PacketHeaderPackTwo {
    char flags;
    int seq;
};
#pragma pack(pop)  // 정렬 설정을 이전 상태로 되돌림

int main()
{
    // 1. 구조체 크기
    struct PacketHeader header;

    printf("%lu\n", sizeof(header.flags));          // 1
    printf("%lu\n", sizeof(header.seq));            // 4
    // sizeof(구조체 변수, 구조체 별칭, struct '')
    printf("%lu\n", sizeof(header));                // 8
    printf("%lu\n", sizeof(struct PacketHeader));   // 8
    // 구조체를 정렬할 때 멤버 중 가장 큰 자료형 크기의 배수로 정렬

    // offsetof(struct 구조체, 멤버)
    // offsetof(구조체 별칭, 멤버) -> 구조체 멤버의 위치(offset) 구할 때
    // stddef.h 헤더 파일에 정의되어 있음
    printf("%lu\n", offsetof(struct PacketHeader, flags));  // 0
    printf("%lu\n", offsetof(struct PacketHeader, seq));    // 4
    // int 4바이트 단위로 정렬
    printf("\n");


    // 2. 구조체 정렬 크기 조절
    struct PacketHeaderPack headerPack;

    printf("%lu\n", sizeof(headerPack.flags));  // 1
    printf("%lu\n", sizeof(headerPack.seq));    // 4
    printf("%lu\n", sizeof(headerPack));        // 5

    printf("%lu\n", offsetof(struct PacketHeaderPack, flags));  // 0
    printf("%lu\n", offsetof(struct PacketHeaderPack, seq));    // 1
    printf("\n");


    struct PacketHeaderPackTwo headerPackTwo;

    printf("%lu\n", sizeof(headerPackTwo.flags));  // 1
    printf("%lu\n", sizeof(headerPackTwo.seq));    // 4
    printf("%lu\n", sizeof(headerPackTwo));        // 6

    printf("%lu\n", offsetof(struct PacketHeaderPackTwo, flags));  // 0
    printf("%lu\n", offsetof(struct PacketHeaderPackTwo, seq));    // 2


    return 0;
}