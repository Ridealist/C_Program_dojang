#include <stdio.h>

struct Flags {
    unsigned int a : 2;
    unsigned int b : 1;
    unsigned int c : 6;
};

int main()
{
    struct Flags f1;

    f1.a = 0xffffffff;
    // f(16) = 15(10) = 1111(2) -> 0x ff ff ff ff(1111 1111) -> 16진수 2칸이 1바이트. 즉 전체 4바이트.
    // 따라서, a는 기본적으로 int 자료형, (short나 long 불가)
    f1.b = 0xffffffff;
    // 1이 32개이므로 모든 비트가 1로 채워짐.
    f1.c = 0xffffffff;

    printf("%u %u %u\n", f1.a, f1.b, f1.c);

    unsigned int a = 0xffffffff; // UINT_MAX : 4,294,967,295
    printf("%u\n",a);

    return 0;
}