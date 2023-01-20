#include <stdio.h>

void helloNumber(int num1) {
    printf("Hello, %d\n", num1);
}

int add(int a, int b) {
    return a + b;
}


int main()
{
    // 1. 매개변수 사용하기
    helloNumber(0);
    helloNumber(1);


    // 2. 덧셈 함수 만들기
    int num1;

    num1 = add(10, 20);

    printf("%d\n", num1);

    return 0;
}