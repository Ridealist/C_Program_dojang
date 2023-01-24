#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    char address[100];
} Person;

void printPerson(Person p) {
    printf("이름 : %s\n", p.name);
    printf("나이 : %d\n", p.age);
    printf("주소 : %s\n", p.address);
}

void setPerson(Person p) {
    // 매개변수로 받은 구조체 멤버의 값 변경
    strcpy(p.name, "강태종");
    p.age = 30;
    strcpy(p.address, "경기도 남양주시 수내동");
}

void setPersonPtr(Person *p) {
    // 매개변수로 받은 포인터에서 구조체 멤버의 값 변경
    strcpy(p->name, "강태종");
    p->age = 30;
    strcpy(p->address, "경기도 남양주시 수내동");
}

int main() {
    // 1. 구조체 매개변수 사용
    Person p;

    strcpy(p.name, "고준보");
    p.age = 30;
    strcpy(p.address, "서울시 강동구 성내동");

    // printPerson((Person) { .name = "고준보", .age = 30, .address = "서울시 강동구 성내동" });
    // printPerson((Person) { "고준보", 30, "서울시 강동구 성내동" });
    // 복합 리터럴로 매개변수 활용 가능.

    // printPerson(p);   // 함수를 호출할 때 구조체 변수 전달. 구조체 모든 멤버가 매개변수 p에 복사됨.

    setPerson(p);

    // setPerson에서 변경한 값이 영향을 미치지 않음.
    printf("이름 : %s\n", p.name);
    printf("나이 : %d\n", p.age);
    printf("주소 : %s\n", p.address);
    printf("\n");

    // 2. 구조체 포인터 매개변수 사용

    // 구조체 포인터 넘겨줄 때 리터럴 사용하고 싶으면, 리터럴 앞에 "&" 주소 연산자 붙여주면 됨.
    // printPerson(&(Person) { .name = "고준보", .age = 30, .address = "서울시 강동구 성내동" });
    // printPerson(&(Person) { "고준보", 30, "서울시 강동구 성내동" });

    setPersonPtr(&p);

    // setPersonPtr에서 변경한 값이 출력됨
    printf("이름 : %s\n", p.name);
    printf("나이 : %d\n", p.age);
    printf("주소 : %s\n", p.address);


    return 0;
}
