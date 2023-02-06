#include <stdio.h>

#define ARRAY_SIZE 10   // 10을 ARRAY_SIZE로 정의
// define은 컴파일 직전에 처리 -> 전처리기 과정을 거쳐 ARRAY_SIZE -> 10으로 바뀌게 됨

#define COUNT 10

int main()
{
    // 1. 메크로 정의하기
    char s1[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        s1[i] = 97 + i;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%c ", s1[i]);
    }
    printf("\n");

    printf("%d\n", COUNT);

#undef COUNT
#define COUNT 20

    printf("%d\n", COUNT);


    // 2. 함수 모양의 매크로 정의하기
    return 0;
}