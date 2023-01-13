#include <stdio.h>

int array()
{
    // 1. �迭 �����ϰ� ��� �����ϱ�
    int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

    printf("%d\n", numArr[0]);
    printf("%d\n", numArr[5]);
    printf("%d\n", numArr[9]);
    printf("\n");

    // 2. �迭 �ʱ�ȭ�ϱ�
    int numArr2[10] = { 0, }; // �迭�� ��Ҹ� ��� 0���� �ʱ�ȭ

    printf("%d\n", numArr2[0]);  // : 0
    printf("%d\n", numArr2[5]);
    printf("%d\n", numArr2[9]);

    int numArr3[10] = { 6, 6,  }; // �迭�� 0�� 1 �ε����� 6����, ������ ��Ҹ� 0���� �ʱ�ȭ
    printf("%d\n", numArr3[0]);  // : 6
    printf("%d\n", numArr3[1]);  // : 6
    printf("%d\n", numArr3[5]);
    printf("%d\n", numArr3[9]);
    printf("\n");

    // 3. �迭�� ��ҿ� �� �Ҵ��ϱ�
    int numArrTen[10];

    numArrTen[0] = 11;
    numArrTen[1] = 11;
    numArrTen[2] = 11;

    printf("%d\n", numArrTen[1]);
    // ������ ��� ������ ������ �߻����� ����. But ������ ���� ���.
    // �迭�� ������ ��� �ε����� �����ϸ� �迭�� �ƴ� �ٸ� �޸� ������ �����ϰ� ��.
    printf("%d\n", numArrTen[5]);  // �Ҵ���� ���� ���
    printf("%d\n", numArrTen[-2]);  // �����̹Ƿ� �߸��� �ε���
    printf("%d\n", numArrTen[20]);  // �迭�� ������ ��� �ε���
    printf("\n");

    // 4. �迭�� ũ�� ���ϱ�
    int numArrSize[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

    printf("%d\n", sizeof(numArrSize));  // 40 : 4����Ʈ ũ���� ��Ұ� 10���̹Ƿ�
    printf("%d\n", sizeof(numArrSize) / sizeof(int));  // 10: �迭�� ũ�� -> ��ü ������ �� ����� ũ��� ������
    printf("%d\n", sizeof(numArrSize) / sizeof(numArrSize[0]));  // ��Ҹ� ���� �����͵� ��
    printf("\n");

    // 5. �迭�� ��� ����ϱ�
    int numArrIter[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

    for (int i = 0; i < sizeof(numArrIter) / sizeof(int); i++)
    {
        printf("%d\n", numArrIter[i]);
    }

    // C ���� index ��ȿ�� ���θ� �˻����� �����Ƿ�, �� ����� �ۼ�!
    int numArrIterReverse[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

    for (int i = sizeof(numArrIterReverse) / sizeof(int) - 1; i >= 0; i--)
    {
        printf("%d\n", numArrIterReverse[i]);
    }
    printf("\n");


    // 8. �迭�� �����Ϳ� �ֱ�
    // int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

    int* numPtr = numArr;

    // �迭�� ù ��° ����� �ּڰ��� ��� ����
    printf("%d\n", *numPtr);  // 11 : �迭�� �ּҰ� ����ִ� �����͸� �������ϸ� �迭�� ù ��° ��� ����

    printf("%d\n", *numArr);  // 11 : �迭 ��ü�� �������ص� �迭�� ù ��° ��� ����

    printf("%d\n", numPtr[5]);  // 66 : �迭�� �ּҰ� ����ִ� �����ʹ� �ε����� ���� ����

    printf("%d\n", sizeof(numArr));  // 40 : �迭�� �޸𸮿� �����ϴ� ��ü ����

    printf("%d\n", sizeof(numPtr));  // 8 : �迭�� �ּҰ� ��� �ִ� �������� ũ�� -> �������� ũ��(8����Ʈ)
    printf("\n");

    // 9. �迭�� 10������ 2������ ��ȯ�ϱ�

    int decimal = 13;
    int binary[20] = { 0, };

    int position = 0;
    while (decimal > 0)
    {
        binary[position] = decimal % 2;
        decimal = decimal / 2;
        position++;
    }

    for (int i = position - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    printf("\n");


    return 0;
}