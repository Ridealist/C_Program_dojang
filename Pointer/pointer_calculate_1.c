#include <stdio.h>

int main()
{
    // 1. 포인터 연산으로 메모리 주소 조작하기
    // 1-1. 포인터 덧셈
    int numArr[5] = { 11, 22, 33, 44, 55 };
    int *numPtrA;
    int *numPtrB;
    int *numPtrC;

    numPtrA = numArr;

    numPtrB = numPtrA + 1;
    numPtrC = numPtrA + 2;

    printf("%p\n", numPtrA);    // 00A3FC00: 메모리 주소. 컴퓨터마다, 실행할 때마다 달라짐
    printf("%p\n", numPtrB);    // 00A3FC04: sizeof(int) * 1이므로 numPtrA에서 4가 증가함
    printf("%p\n", numPtrC);    // 00A3FC08: sizeof(int) * 2이므로 numPtrA에서 8이 증가함

    printf("%d\n", *numPtrB);   // numArr[1] : 22
    printf("%d\n", *numPtrC);   // numArr[2] : 33
    printf("\n");


    // 1-2. 포인터 뺄셈
    numPtrA = &numArr[2];

    numPtrB = numPtrA - 1;
    numPtrC = numPtrA - 2;

    printf("%p\n", numPtrA);    // 00A3FC08: 메모리 주소. 컴퓨터마다, 실행할 때마다 달라짐
    printf("%p\n", numPtrB);    // 00A3FC04: sizeof(int) * -1이므로 numPtrA에서 4가 감소함
    printf("%p\n", numPtrC);    // 00A3FC00: sizeof(int) * -2이므로 numPtrA에서 8이 감소함

    printf("%d\n", *numPtrB);   // numArr[1] : 22
    printf("%d\n", *numPtrC);   // numArr[0] : 11
    printf("\n");

    // 1-3. 증가, 감소 연산자
    numPtrA = &numArr[2];

    numPtrB = numPtrA;
    numPtrC = numPtrA;
    numPtrB++;
    numPtrC--;

    printf("%p\n", numPtrA);    // 00A3FC08: 메모리 주소. 컴퓨터마다, 실행할 때마다 달라짐
    printf("%p\n", numPtrB);    // 00A3FC0C: sizeof(int) * 1이므로 numPtrA에서 4가 증가함
    printf("%p\n", numPtrC);    // 00A3FC04: sizeof(int) * -1이므로 numPtrA에서 4가 감소함

    printf("%d\n", *numPtrB);   // numArr[3] : 44
    printf("%d\n", *numPtrC);   // numArr[1] : 22 
    printf("\n");


    // 2. 포인터 연산과 역참조 사용하기
    numPtrA = numArr;

    printf("%d\n", *(numPtrA + 1));  // numArr[1] : 22

    // printf("%d\n", *numPtrA + 1));  // numArr[0] + 1 : 12
    // 괄호로 묶지 않으면 역참조 연산자가 우선 실행됨

    printf("%d\n", *(numPtrA + 2));  // numArr[2] : 33

    numPtrA = &numArr[2];

    numPtrB = numPtrA;
    numPtrC = numPtrA;

    printf("%d\n", *(++numPtrB));    // 44: numPtrA에서 순방향으로 4바이트만큼 떨어진
                                    // 메모리 주소에 접근
    printf("%d\n", *(--numPtrC));    // 22: numPtrA에서 역방향으로 4바이트만큼 떨어진
                                    // 메모리 주소에 접근

    // 전위 증감 연산자와 역참조 연산자는 우선 순위 동일
    // 결합방향이 오른쪽에서 왼쪽
    printf("%p\n", numPtrB);
    printf("%d\n", *++numPtrB);    // 55
    printf("%d\n", *--numPtrC);    // 11

    // 전위 <-> 후위 연산자 순서 고려!

    // 후위 증감 연산자는 1. 메모리 주소에 접근해 값을 가져온 뒤 2. 포인터 연산
    printf("%p\n", numPtrB);
    printf("%d\n", *(numPtrB++));    // 55: numPtrA의 메모리에 접근하여 값을 가져온 뒤 포인터 연산
    printf("%p\n", numPtrB);
    printf("%d\n", *(numPtrC--));    // 11: numPtrA의 메모리에 접근하여 값을 가져온 뒤 포인터 연산


    return 0;
}