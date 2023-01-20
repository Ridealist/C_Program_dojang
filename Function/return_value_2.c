#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* allocMemory()
{
    void* ptr = malloc(100);
    return ptr;

    // return malloc(100); 도 가능
    // 이렇게 하면 malloc 함수에서 반환된 값을 다시 반환
}

struct Person {
    char name[20];
    int age;
    char address[100];
};

struct Person getPerson()
{
    struct Person p;

    strcpy(p.name, "고준보");
    p.age = 32;
    strcpy(p.address, "서울시 강동구 성내동");

    printf("함수 내 지역변수 주소 : %p\n", &p);
    return p;
}

struct Person * allocPerson()
{
    struct Person * ptr = malloc(sizeof(struct Person));

    strcpy(ptr->name, "홍은진");
    ptr->age = 29;
    strcpy(ptr->address, "서울시 성동구 행당동");

    return ptr;
}


int main()
{
    // 3. void 포인터
    char* s1 = allocMemory();    // void 포인터를 char 포인터에 넣어서 문자열처럼 사용
    strcpy(s1, "Hello, world!");
    printf("%s\n", s1);
    free(s1);  // 동적 메모리 해제

    int* numPtr1 = allocMemory();  // void 포인터를 int 포인터에 넣어서 정수 배열처럼 사용
    // 단 100byte크기 한도 내에서! -> (최대 정수 25개)
    numPtr1[0] = 10;
    numPtr1[1] = 20;
    printf("%d %d\n", numPtr1[0], numPtr1[1]);
    free(numPtr1);  // 동적 메모리 해제


    // 4. 구조체와 구조체 포인터
    struct Person p1;

    p1 = getPerson();    // 반환된 구조체 변수의 내용이 p1로 모두 복사됨
    printf("main 함수 내 변수 주소: %p\n", &p1);

    // getPerson에서 저장한 값이 출력됨
    printf("이름: %s\n", p1.name);       // 홍길동
    printf("나이: %d\n", p1.age);        // 30
    printf("주소: %s\n", p1.address);    // 서울시 용산구 한남동
    printf("\n");

    struct Person * ptr1;    // 포인터를 반환하여 ptr1에 메모리 주소 저장
    // 구조체 내용을 모두 복사하지 않고 포인터로 주소 연결만 해주었으므로 훨씬 효율적

    ptr1 = allocPerson();
    // allocPerson에서 저장한 값들이 출력됨
    printf("이름: %s\n", ptr1->name);       // 홍길동
    printf("나이: %d\n", ptr1->age);        // 30
    printf("주소: %s\n", ptr1->address);    // 서울시 용산구 한남동

    free(ptr1);  // 동적 메모리 해제 항상!

    return 0;
}