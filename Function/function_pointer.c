#include <stdio.h>

void hello() {
    printf("Hello, world!\n");
}

void bonjour() {
    printf("bonjour le monde!\n");
}

int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

int main() {

    // 0. 작동 원리
    printf("%p\n", hello); // 0x102e7be1c(64비트): 함수 이름도 포인터이므로 메모리 주소가 출력됨
    // 함수 이름도 결국 포인터!
    // 함수 포인터에 함수 이름을 할당 가능


    // 1. 함수 포인터 만들기
    // 반환값자료형 (*함수포인터이름)()
    void (*fp)();  // 반환값과 매개변수가 없는 함수 포인터 fp 선언

    fp = hello;   // hello 함수의 메모리 주소를 함수 포인터 fp에 저장
    fp();         // Hello,world! : 함수 포인터로 함수 호출

    fp = bonjour; // bonjour 함수의 메모리 주소를 함수 포인터 fp에 저장
    fp();         // bonjour le monde! : 함수 포인터로 bonjour 함수 호출


    // 2. 반환값과 매개변수가 있는 함수 포인터 만들기

    int (*fp2)(int, int);  // int형 반환값, int형 매개변수 2개가 있는 함수 포인터 fp2 선언

    fp2 = add;  // add함수 메모리 주소를 fp2에 할당
    printf("%d\n", fp2(10, 20));

    fp2 = mul;  // mul함수 메모리 주소를 fp2에 할당
    printf("%d\n", fp2(10, 20));

    return 0;
}