#include <stdio.h>

// 함수 선언 부분
// 반환값자료형 함수이름(); -> 함수 원형(function prototype)
void hello();
void printHostname();

int main()
{
    // 1. 함수 정의
    hello();


    // 2. 함수 선언과 정의 분리
    printHostname();

    return 0;
}

// 함수 정의 부분
void hello()  // 함수 헤더(header)
// 함수 본체(function body)
{
    printf("Hello, world!\n");
}

void printHostname()
{
    printf("Saturn\n");
}

void printIPAddress()
{
    printf("192.168.10.6\n");
}