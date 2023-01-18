#include <stdio.h>
#include <stdlib.h>

typedef struct _Point2D{
    int x;
    int y;
} Point2D;

int main()
{
    // 1. 구조체 배열 선언
    // struct 구조체 변수이름[크기]
    Point2D p[3];

    p[0].x = 10;
    p[0].y = 20;

    p[1].x = 30;
    p[1].y = 40;

    p[2].x = 50;
    p[2].y = 60;

    printf("%d %d\n", p[0].x, p[0].y);    // 10 20
    printf("%d %d\n", p[1].x, p[1].y);    // 30 40
    printf("%d %d\n", p[2].x, p[2].y);    // 50 60
    printf("\n");

    // 배열 선언하는 동시에 초기화
    /*
    struct 구조체이름 변수이름[크기] = { { .멤버이름1 = 값1, .멤버이름2 = 값2 }, { .멤버이름1 = 값3, .멤버이름2 = 값4 } };
    struct 구조체이름 변수이름[크기] = { { 값1, 값2 }, { 값3, 값4 } };
    */
    struct _Point2D p2[3] = { { .x = 10, .y = 20 }, { .x = 30, .y = 40 }, { .x = 50, .y = 60} };
    struct _Point2D p3[3] = { { 10, 20 }, { 30, 40 }, { 50, 60 } };

    // 모든 멤버의 요소 초기화
    struct _Point2D p4[3] = { 0, };  // 구조체 배열을 선언하면서 0으로 초기화


    // 2. 구조체 포인터 배열 선언
    // 요소마다 메모리 할당 시
    // 포인터 배열 -> 각 요소에 메모리 할당
    Point2D *ptr[3];  // 크기가 3인 구조체 포인터 배열 선언

    // 구조체 포인터 배열 크기 / "구조체 포인터"의 크기(요소의 크기) -> 요소의 개수
    // 포인터 배열에는 '포인터'가 들어 있음. 구조체가 아님...!
    for (int i = 0; i < sizeof(ptr) / sizeof(Point2D *); i++)
    {
        ptr[i] = malloc(sizeof(Point2D));  // 각 요소에 구조체 크기만큼 메모리 할당
    }

    ptr[0]->x = 10;
    ptr[0]->y = 20;
    ptr[1]->x = 30;
    ptr[1]->y = 40;
    ptr[2]->x = 50;
    ptr[2]->y = 60;

    printf("%d %d\n", ptr[0]->x, ptr[0]->y);    // 10 20
    printf("%d %d\n", ptr[1]->x, ptr[1]->y);    // 30 40
    printf("%d %d\n", ptr[2]->x, ptr[2]->y);    // 50 60

    for (int i = 0; i < sizeof(ptr) / sizeof(Point2D *); i++)
    {
        free(ptr[i]);
    }
    
    return 0;
}