#include <stdio.h>

int bitwise()
{
    // 기본 비트 연산자 &, |, ^
    unsigned char num1 = 1;  // 0000 0001
    unsigned char num2 = 3;  // 0000 0011

    printf("%d\n", num1 & num2);  // 0000 0001
    printf("%d\n", num1 | num2);  // 0000 0011
    printf("%d\n", num1 ^ num2);  // 0000 0010
    printf("\n");

    // 비트 NOT 연산자 ~
    unsigned char num3 = 162;  // 1010 0010
    unsigned char num4;

    num4 = ~num3;  // 0101 1101 -> 93

    printf("%u\n", num4);
    printf("\n");

    // 시프트 연산자 <<, >>

    unsigned char num5 = 3;  // 0000 0011
    unsigned char num6 = 24;  // 0001 1000

    printf("%u\n", num5 << 3);  // 0001 1000 -> 24, 3 * 2^3
    printf("%u\n", num6 >> 2);  // 0000 0110 -> 6, 24 / 2^2
    printf("\n");

    // 비트 연산 후 할당
    unsigned char num10 = 4;  // 0000 0100
    unsigned char num11 = 4;
    unsigned char num12 = 4;
    unsigned char num13 = 4;
    unsigned char num14 = 4;

    num10 &= 5;  // 5(0000 0101) & 연산 후 할당 -> 0000 0100 : 4
    num11 |= 2;  // 2(0000 0010) -> 0000 0110 : 6
    num12 ^= 3;  // 3(0000 0011) -> 0000 0111 : 7
    num13 <<= 2;  // 16
    num14 >>= 2;  // 1

    printf("%u\n", num10);
    printf("%u\n", num11);
    printf("%u\n", num12);
    printf("%u\n", num13);
    printf("%u\n", num14);

    return 0;
}