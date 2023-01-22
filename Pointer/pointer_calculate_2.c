#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
    int num1;
    int num2;
};


int main()
{
    // 3. void 포인터 연산
    // 3-1. void 포인터 type casting 이후 연산
    void *ptr = malloc(100);

    // GCC에서는 void 포인터 연산 컴파일 에러 나지는 않음.
    // void 포인터일 경우 기본 "1 바이트" 크기로 설정되어 있음.
    printf("%p\n", ptr); // 0x1326067d0
    printf("%p\n", ptr + 1); // 0x1326067d1

    printf("%p\n", (int *)ptr + 1); // 0x1326067d4
    printf("%p\n", (int *)ptr - 1); // 0x1326067cc
    printf("\n");

    ptr++; // 가능!

    --ptr; // 가능!

    // ++(int *)ptr;  // 불가능
    // -> 식이 수정할 수 있는 lvalue여야 합니다.C/C++(137)

    // GCC에서는 포인터 형변환을 한 이후에는 증가, 감소 연산자 사용 불가
/*     printf("%p\n", ++(int *)ptr);
    printf("%p\n", --(int *)ptr);

    printf("%p\n", ((int *)ptr)++);
    printf("%p\n", ((int *)ptr)--); */

    int *ptr2 = ptr; // 0x1326067d0
    printf("%p\n", ptr2); // 0x1326067d0

    printf("%p\n", ++ptr2); // 0x1326067d4
    printf("%p\n", --ptr2); // 0x1326067d0


    // 단, 증가, 감소 연산자를 뒤에 붙였으므로 현재 메모리 주소를 출력한 뒤 포인터 연산을 하게 됩니다.
    // 메모리 주소 반환하고 +4 증가된 채로 저장
    printf("%p\n", ptr2++); // 0x1326067d0
    // 메모리 주소 반환하고 -4 감소된 채로 저장
    printf("%p\n", ptr2--); // 0x1326067d4

    printf("%p\n", ptr); // 0x1326067d0  // 감소된 상태

    free(ptr);

    /*
    void *ptr = malloc(100);    // 동적 메모리 할당
    *(++(int *)ptr) = 10;    // 증가 연산자를 사용했으므로 4만큼 증가한 메모리 주소가 ptr에 다시 저장됨
    free(ptr);               // 메모리 주소가 바뀐 포인터로 메모리 해제를 하면 에러 발생

    -> free 함수로 메모리 해제를 할 때는 반드시 처음에 메모리를 할당할 때 받은 주소(포인터)를 넣어주어야 합니다.
    */

    // 3-2. void 포인터를 포인터 연산한 뒤 역참조
    int numArr[5] = { 11, 22, 33, 44, 55 };
    void *Ptr = &numArr[2];    // 세 번째 요소의 메모리 주소

    printf("%d\n", *(int *)Ptr);    // 33: 포인터 연산을 하지 않은 상태에서 역참조

    // void 포인터를 다른 포인터로 변환하여 포인터 연산을 한 뒤 역참조
    printf("%d\n", *((int *)Ptr + 1));    // 44
    printf("%d\n", *((int *)Ptr - 1));    // 22

    // TODO GCC에서는 type casting 이후 ++ -- 증가, 감소 연산자 사용 불가!
    // 포인터를 다른 포인터로 변환한 뒤 ++, -- 연산자를 사용하는 것도 마이크로소프트 전용 언어 확장
/*     printf("%d\n", *(++(int *)Ptr));      // 44
    printf("%d\n", *(--(int *)Ptr));      // 33

    printf("%d\n", *(((int *)Ptr)++));    // 33
    printf("%d\n", *(((int *)Ptr)--));    // 44 */

    // GCC에서 컴파일하려면
    // 1. 포인터를 다른 자료형의 포인터에 할당한 뒤
    // 2. ++, -- 연산자를 사용
    int* Ptr2 = Ptr;
    printf("%p\n", Ptr2);
    printf("%d\n", *(++Ptr2));      // 44
    printf("%d\n", *(--Ptr2));      // 33

    // 증가, 감소 연산자를 뒤에 붙였으므로 현재 메모리의 값을 가져온 뒤 포인터 연산을 하게 됩니다.
    printf("%p\n", Ptr2);
    printf("%d\n", *((Ptr2)++));    // 33
    printf("%p\n", Ptr2);
    printf("%d\n", *((Ptr2)--));    // 44


    // 4. 구조체 포인터 연산
/*     struct Data d[3] = { { 10, 20}, { 30, 40 }, { 50, 60 } };
    struct Data *st_ptr;

    st_ptr = d;

    printf("%p\n", st_ptr);  // 0x16dc3f290
    printf("%d %d\n", (st_ptr + 1)->num1, (st_ptr + 1)->num2);  // = d[1].num1, d[1].num2
    printf("%p\n", st_ptr + 1);  // 0x16dc3f298 -> 구조체 크기 8만큼 메모리 주소 더해짐
    printf("%d %d\n", (st_ptr + 2)->num1, (st_ptr + 2)->num2);
    printf("%p\n", st_ptr + 2); */

    // void 포인터에 동적메모리 할당 후, 포인터 연산
    void *structPtr = malloc(sizeof(struct Data) * 3);
    struct Data d[3];

    ((struct Data *)structPtr)->num1 = 10;        // 포인터 연산으로 메모리에 값 저장
    ((struct Data *)structPtr)->num2 = 20;        // 포인터 연산으로 메모리에 값 저장

    ((struct Data *)structPtr + 1)->num1 = 30;    // 포인터 연산으로 메모리에 값 저장
    ((struct Data *)structPtr + 1)->num2 = 40;    // 포인터 연산으로 메모리에 값 저장

    ((struct Data *)structPtr + 2)->num1 = 50;    // 포인터 연산으로 메모리에 값 저장
    ((struct Data *)structPtr + 2)->num2 = 60;    // 포인터 연산으로 메모리에 값 저장

    memcpy(d, structPtr, sizeof(struct Data) * 3);

    printf("\n");
    printf("%d %d\n", d[1].num1, d[1].num2);
    printf("%d %d\n", ((struct Data *)structPtr + 1)->num1, ((struct Data *)structPtr + 1)->num2);

    return 0;
}