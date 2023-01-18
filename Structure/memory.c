#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // memset 함수가 선언된 헤더 파일
// #include <memory.h> 헤더 파일도 가능

typedef struct _Point2D {
    int x;
    int y;
} Point2D;

int main()
{
    // 1. 메모리 설정
    // struct Point2D p1;
    // struct Point2D *ptr1 = malloc(sizeof(struct Point2D));  // 구조체의 크기만큼 메모리 할당

    // memset(구조체포인터, 설정할 값, sizeof(sturct 구조체))
    // & 주소 연산자로 변수의 '메모리 주소'를 넣어줌
    // memset(&p1, 0, sizeof(struct Point2D));  // p1을 구조체 크기만큼 0으로 설정

    // memset(ptr1, 0, sizeof(struct Point2D));

    // printf("%d %d\n", p1.x, p1.y);
    // printf("%d %d\n", ptr1->x, ptr1->y);

    // free(ptr1);


    // 2. 메모리 복사
    Point2D p1;
    Point2D p2;

    p1.x = 10;
    p1.y = 20;

    // void memcpy(목적지 포인터, 원본 포인터, 크기) -> 목적지 포인터 반환
    memcpy(&p2, &p1, sizeof(Point2D));  // Point2D 크기만큼 p1의 내용을 p2로 복사
    // 앞쪽이 목적지! 뒤쪽이 원본!

    printf("%d %d\n", p1.x, p2.x);
    printf("\n");

    Point2D *ptr1 = malloc(sizeof(Point2D));
    // Point2D *ptr2 = malloc(sizeof(Point2D));

    // ptr1->x = 10;
    // ptr1->y = 20;

    // memcpy(ptr2, ptr1, sizeof(Point2D));

    // printf("%d %d\n", ptr1->y, ptr2->y);

    // free(ptr1);
    // free(ptr2);

    // 구조체 변수 -> 동적 메모리, 동적 메모리 -> 구조체 변수로 내용 복사 가능

    memcpy(ptr1, &p1, sizeof(Point2D));
    printf("%d %d\n", p1.x, p1.y);
    printf("%d %d\n", ptr1->x, ptr1->y);

    free(ptr1);

    return 0;
}
