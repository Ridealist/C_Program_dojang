#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int input()
{
    // ���� �Է¹ޱ�
    int num1;

    printf("������ �Է��ϼ���: ");
    scanf("%d", &num1);  // ǥ�� �Է��� �޾� ������ ����

    printf("%d\n", num1);

    // ���� 2�� �Է¹ޱ�
    int num2, num3;
    printf("���� �� ���� �Է��ϼ���: ");
    scanf("%d %d", &num2, &num3);

    printf("%d %d\n", num2, num3);

    float num4;

    // ���� �ƴ� �ڷ��� �Է¹ޱ�
    printf("�Ǽ��� �Է��ϼ���: ");
    scanf("%f", &num4);  // �Ǽ� �ڷ��� %f

    printf("%f\n", num4);

/*
    double num5;
    scanf("%lf", &num5); // double %lf

    long double num6;
    scanf("%Lf", &num2); // long double %Lf
*/

    // ���� �Է¹ޱ�
    char c1;

    printf("���ڸ� �Է��ϼ���: ");
    scanf("%c", &c1); // %c�� ���� �� ���� �Է� ����. ���� ������ �Է��� ��� ù��° ���ڸ� ����ǰ� �������� ���õ�.

    printf("%c\n", c1);

    return 0;
}