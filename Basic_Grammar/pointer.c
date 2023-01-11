#include <stdio.h>

int main()
{
    /*
    ������ ������ "*"
    �ּ� ������ "&"

    ������ = �޸� �ּ�

    pointer to int = address of int
    */


    // 1. �޸� �ּ� ���ϱ�
    int num2 = 10;

    printf("%p\n", &num2);
    printf("\n");

    // 2. ������
    int *numPtr;  // ������ ���� ����
    int num1 = 10;
    char char1 = 'c';

    numPtr = &num1;  // num1�� �޸� �ּҸ� ������ ������ ����

    printf("%p\n", numPtr); // ������ ���� numPtr�� �� ���

    printf("%p\n", &num1); // ���� num1�� �޸� �ּ� ���

    printf("%lu\n", sizeof(numPtr)); // 64��Ʈ int �����ʹ� 8����Ʈ
    printf("%lu\n", sizeof(char *)); // 64��Ʈ char �����ʹ� 8����Ʈ
    printf("%lu\n", sizeof(num1)); // 32��Ʈ int �������� 4����Ʈ
    printf("%lu\n", sizeof(char1)); // 8��Ʈ char �������� 1����Ʈ
    printf("\n");

    // 3. ������
    int *numPtr2;
    int num3 = 10;

    numPtr2 = &num3;

    *numPtr2 = 20; // ������ �����ڷ� �޸� �ּҿ� �����Ͽ� 20�� ����

    printf("%d\n", *numPtr2); // ������ �����ڷ� num3 �޸� �ּҷ� �����Ͽ� ���� ������
    printf("%d\n", num3);

    return 0;
}