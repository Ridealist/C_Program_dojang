#include <stdio.h>

void hello(int count) {

    if (count == 0)  // 반드시 종료조건 설정!
        return;

    printf("Hello, world! %d\n", count);

    hello(--count);  // count를 감소시킨 후 다시 hello에 넣기
}

int factorial(int n) {
    if (n == 1)     // n이 1일 때, 1을 반환하고 재귀호출 끝냄.
        return 1;

    return n * factorial(n - 1);
}

int main() {
      
    // 1. 재귀호출 사용하기
    // hello(); -> 종료 조건이 없는 재귀함수는 stack overflow 발생

    hello(5);


    // 2. 재귀호출로 팩토리얼 구하기
    printf("%d\n", factorial(5));

    return 0;
}