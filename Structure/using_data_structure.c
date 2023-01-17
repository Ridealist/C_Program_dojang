#define _CRT_SECURE_NO_WARNINGS  // strcpy 보안 경고 에러 방지
#include <stdio.h>
#include <string.h>

struct Person {  // 구조체
    char name[20];  // 구조체 멤버
    int age;
    char address[100];
};
// 닫는 중괄호 뒤에 세미콜론(;) 필수!

// Person -> 구조체 태그
struct Person {  // 구조체
    char name[20];  // 구조체 멤버
    int age;
    char address[100];
} p1;

// typedef로 구조체를 정의하면서 별칭(alias) 지정하기
typedef struct _Person {
    char name[20];
    int age;
    char address[100];
} Person;  // 구조체 별칭 정의

// 익명 구조체
// 반드시 구조체 별칭을 지정해주어야 함
typedef struct {
    char name[20];
    int age;
    char address[100];
} Person;  // 구조체 별칭 정의


int main()
{
    // 구조체별칭 변수이름
    Person p1;
    // struct _Person p1;
    // struct Person p1;  // 구조체 변수 선언

    // 점으로 구조체 멤버에 접근하여 값 할당
    strcpy(p1.name, "홍길동");
    p1.age = 30;
    strcpy(p1.address, "서울시 용산구 한남동");

    printf("이름: %s\n", p1.name);
    printf("나이: %d\n", p1.age);
    printf("주소: %s\n", p1.address);

    return 0;
}

