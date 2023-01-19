#include <stdio.h>

/*
참조 블로그
https://coding-factory.tistory.com/655
*/

struct Flags {
    union {
        struct {
            unsigned short a : 4;                                
            unsigned short b : 2;                                
            unsigned short c : 2;                                
            unsigned short d : 8;                                
        };
        unsigned short e;
    };
};

int main()
{
    // struct Flags f1 = { 0, };

    // f1.a = 8;   // 0000 1000
    // f1.b = 2;   // 0000 0010
    // f1.c = 2;   // 0000 0010
    // f1.d = 128; // 1000 0000

    // printf("%u\n", f1.e);  // 32936 : 1000 0000 1010 1000

    unsigned int num = 32936;

    for (int i = 15; i >= 0; i--)
    {
        int result = num >> i & 1;
        printf("%d", result);
    }
    printf("\n");

    return 0;
}