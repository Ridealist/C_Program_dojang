#include <stdio.h>
#include <stdlib.h>

struct Phone {
    int areacode;  // 국가번호
    unsigned long long number;  // 휴대전화 번호
};

struct Person {
    char name[20];
    int age;
    // 구조체는 구조체를 멤버로 가질 수 있음
    struct Phone phone;  // 휴대전화, 구조체를 멤버로 가짐
};

struct PersonPointer {
    char name[20];
    int age;
    struct Phone *phone;
};

// 구조체 안에 구조체 정의 가능
struct PersonInner {
    char name[20];
    int age;
    struct PhoneInner {
        int areacode;
        unsigned long long number;
    // 단, 구조체 정의한 뒤 반드시 변수 선언!
    } phone;
};

// 익명 구조체 + 공용체
struct Vector3 {
    union {
        struct {
            float x;
            float y;
            float z;
        };
        // -> 익명일 경우, pos.x / 중간 변수 없이 바로 멤버 호출 가능
        /*   struct Cordinate {
            float x;
            float y;
            float z;
        } cord ; */
        // -> 익명이 아닐 경우, pos.cord.x / 중간에 변수 이름을 거쳐야 함
        float v[3];
    };
};


int main()
{
    // 1. 구조체 안에서 구조체 멤버 사용하기
    struct Person p1;
    // 구조체 변수 선언과 동시에 초기화
    // struct 구조체이름 변수이름 = { .멤버이름1 = 값1, .멤버이름2 = 값2, { .멤버이름3 = 값3, .멤버이름4 = 값4 } };
    // struct 구조체이름 변수이름 = { 값1, 값2, { 값3, 값4 } };
    struct Person p2 = { .name = "Andrew", .age = 25, { .areacode = 82, .number = 3045671234} };
    struct Person pr = { "Maria", 19, { 82, 3087651283 } };

    p1.phone.areacode = 82;
    p1.phone.number = 3045671234;

    printf("%d %llu\n", p1.phone.areacode, p1.phone.number);
    printf("\n");

    // 2. 구조체 안의 구조체 멤버에 메모리 할당
    struct Person *ptr1 = malloc(sizeof(struct Person));

    ptr1->phone.areacode = 82;
    ptr1->phone.number = 23141123;

    free(ptr1);

    struct PersonPointer *perPtr = malloc(sizeof(struct PersonPointer));  // 바깥 구조체 포인터 메모리 할당
    perPtr->phone = malloc(sizeof(struct Phone));   // 멤버 포인터에 메모리 할당

    perPtr->phone->areacode = 82;       // 포인터->포인터->멤버 순으로 접근하여 값 할당
    perPtr->phone->number = 3045671234; // 포인터->포인터->멤버 순으로 접근하여 값 할당

    printf("%d %llu\n", perPtr->phone->areacode, perPtr->phone->number);

    free(perPtr->phone);  // 구조체 멤버의 메모리 먼저 해제
    free(perPtr);         // 구조체 메모리 해제


    // 3. 익명 구조체와 익명 공용체 활용
    /*
    struct Vector3 {
        union {
            struct {
                float x;
                float y;
                float z;
            };
            float v[3];  // 좌표를 배열로 저장
        };
    };
    */

    // 위 구조체는 '익명 구조체'와 'float 배열'이 같은 공간을 차지( 자료형과 자료의 갯수가 모두 같으므로 )
    // 공용체로 묶어주면 같은 공간을 공유
    struct Vector3 pos;

    for (int i = 0; i < 3; i++)
    {
        pos.v[i] = 1.0f;  // v는 배열이므로 인덱스로 접근 가능
    }

    // 공용체에 값을 넣었으므로 같은 공간 공유
    // 구조체 x, y, z 멤버로도 접근 가능
    printf("%f %f %f\n", pos.x, pos.y, pos.z);    // 1.000000 1.000000 1.000000: x, y, z로 접근

    // 익명 구조체와 익명 공용체를 사용하면 같은 값이지만 이름과 형태를 달리하여 접근할 수 있음!

    return 0;
}