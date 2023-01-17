#define _CRT_SECURE_NO_WARNINGS    // strcpy 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>    // strcpy 함수가 선언된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

struct Person {    // 구조체 정의
    char name[20];        // 구조체 멤버 1
    int age;              // 구조체 멤버 2
    char address[100];    // 구조체 멤버 3
};

typedef struct _Person {
    char name[20];        // 구조체 멤버 1
    int age;              // 구조체 멤버 2
    char address[100];    // 구조체 멤버 3
} Person;


int main()
{
    // 1. 구조체 포인터를 선언하고 메모리 할당하기
    struct Person *p1 = malloc(sizeof(struct Person));  // 구조체 포인터 선언, 메모리 할당

    // 화살표 연산자로 구조체 멤버에 접근하여 값 할당
    strcpy(p1->name, "고준보");
    // strcpy(*p1.name, "고준보");
    p1->age = 30;
    // *p1.age = 30;
    strcpy(p1->address, "서울시 강동구 성내동");

    // 화살표 연산자로 구조체 멤버에 접근하여 값 출력
    printf("이름: %s\n", p1->name);       // 
    printf("나이: %d\n", p1->age);        // 
    printf("주소: %s\n", p1->address);    //

    free(p1);    // 동적 메모리 해제


    // 2. 구조체 별칭으로 포인터 선언하고 메모리 할당하기
    Person *pPtr1 = malloc(sizeof(Person));  // 구조체 별칭으로 포인터 선언, 메모리 할당
    // 메모리 크기도 구조체 별칭으로 입력;
    /*
    아래 코드 모두 동일
    */
    free(pPtr1);


    // 3. 구조체 포인터에 구조체 변수의 주소 할당하기
    // 동적 메모리 할당하지 않고 구조체 포인터 사용하는 방법
    // 구조체 변수에 &를 사용!
    struct Person person1;
    struct Person *ptr;

    // 구조체 포인터 = &구조체 변수;
    ptr = &person1;  // person1의 메모리 주소를 ptr에 할당

    strcpy(ptr->name, "홍은진");
    ptr->age = 29;
    strcpy(ptr->address, "서울시 성동구 행당동");

    printf("%d\n", person1.age);
    printf("%d\n", ptr->age);

    return 0;
}