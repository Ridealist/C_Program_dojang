#include <stdio.h>
#include <stdlib.h>

int pointerTwo()
{
    // ����� Ȱ���غ���
    /*
    int* numPtr;
    int num1 = 10;

    numPtr = &num1;

    *numPtr = 20;

    printf("%d\n", *numPtr);
    printf("%d\n", num1);

    */

    // �پ��� �ڷ����� ������ �����ϱ�
    long long* numPtr1;
    float* numPtr2;
    char* cPtr1;

    long long num1 = 10;
    float num2 = 3.5f;
    char c1 = 'a';

    numPtr1 = &num1;
    numPtr2 = &num2;
    cPtr1 = &c1;

    printf("%lld\n", *numPtr1);
    printf("%f\n", *numPtr2);
    printf("%c\n", *cPtr1);

    // ��� ������
    // 1. pointer to constant
    const int num3 = 30;
    const int* numPtr;  // ����� ���ؼ� �����͵� const�� ��������� ��

    numPtr = &num3;
    // *numPtr = 20; -> ������ ����, �޸� �ּҿ� ����� ���� ������ �� ����

    // 2. constant pointer
    int num5 = 10;
    int num6 = 20;
    int* const numPtr10 = &num6;

    // numPtr10 = &num6; -> ������ ����, �ٸ� ������(�޸� �ּ�)�� �Ҵ��� �� ����

    // 3. constant pointer to constant
    const int num10 = 10;
    const int num20 = 20;
    const int* const numPtr20 = &num1;

    // *numPtr20 = 30;  �޸� �ּҿ� ����� �� ���� �Ұ�
    // numPtr20 = &num20;  �޸� �ּ� ���� �Ұ�. �� �� �Ұ�

    // void ������
    int numten = 10;
    char a1 = 'a';
    int* numtenPtr = &num1;
    char* aPtr = &a1;

    void* ptr;

    // ������ �ڷ����� �޶� ������ ��� �߻����� ����
    ptr = numtenPtr;  // void �����Ϳ� int ������ ����
    ptr = aPtr;

    numtenPtr = ptr;
    aPtr = ptr;


    // ���� ������
    int* singlePtr;
    int** doublePtr;
    int randomNum = 10;

    singlePtr = &randomNum; // randomNum �޸� �ּ� ����

    doublePtr = &singlePtr; // singlePtr�� �޸� �ּ� ����

    printf("%d\n", **doublePtr);


    // �߸��� ������ ���
    // �����ʹ� �޸� �ּҸ� �����ϴ� ��. ���� ���� �����ϸ� �� ��.
    int* wrongPtr = 0x100;

    printf("%d\n", *wrongPtr);

    return 0;
}