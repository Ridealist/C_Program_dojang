#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
������ ������(dereference w/ offset) []
� '�ּ�'���� ���� ������ ������ '������'��Ų ���¿��� '������'�ϴ� �������̴�.

��,  arr[ i ]  ��   * ( arr + i ) �� ���� ���� �ȴ�.
*/


int pointerAndArray()
{
    // 0. ���� ���� �迭(���ϴ� ũ�⸸ŭ �迭�� �����ϴ� ���)
    //int size;
    //
    //scanf("%d", &size);  // �迭�� ũ�� �Է� �ޱ�

    //int numArr[size];  // �Է¹��� ũ��� �迭 ����
    // -> ���� ���� �迭�� �������� �ʾ� ������ ���� �߻�


    // 1. �����Ϳ� �Ҵ�� �޸𸮸� �迭ó�� ���
    int* numPtr = malloc(sizeof(int) * 10);  // int 10�� ũ�⸸ŭ ���� �޸� �Ҵ�

    // numPtr[0] = 10;  // �迭ó�� �ε����� �����Ͽ� �� �Ҵ�
    numPtr[0] = 10;
    numPtr[9] = 20;
    // numPtr[10] = 30;
     
    printf("%p\n", numPtr);
    printf("%p\n", numPtr + 1);
    printf("%d\n", numPtr[0]);  // �迭ó�� �ε����� �����Ͽ� �� ���
    //printf("%d\n", *numPtr[0]);  // �迭ó�� �ε����� �����Ͽ� �� ���
    printf("%d\n", numPtr[9]);

    free(numPtr);  // �������� �Ҵ��� �޸� ����


    // 2. �Է��� ũ�⸸ŭ �޸� �Ҵ��� �迭 ����
    //int size;

    //printf("\n�迭�� ũ�⸦ �Է��ϼ��� : ");
    //scanf("%d", &size);

    //int* ptr = malloc(sizeof(int) * size);

    //for (int i = 0; i < size; i++)
    //{
    //    ptr[i] = i;
    //}

    //printf("\n��� ���\n");
    //for (int i = 0; i < size; i++)
    //{
    //    printf("%d\n", ptr[i]);
    //}

    //free(ptr);


    // 3. �����Ϳ� �Ҵ�� �޸𸮸� 2���� �迭ó�� ���
    //int** m = malloc(sizeof(int*) * 3); // ���� �����Ϳ� "(int ������ ũ��)" * (���� ũ��)��ŭ ���� �޸� �Ҵ�.

    //for (int i = 0; i < 3; i++)
    //{
    //    m[i] = malloc(sizeof(int) * 4);  // int �����Ϳ� (int ũ��) * (���� ũ��)��ŭ ���� �޸� �Ҵ�
    //}

    //m[0][0] = 1;
    //m[1][2] = 5;
    //m[2][3] = 14;

    //printf("%d\n", m[0][0]);
    //printf("%d\n", m[1][2]);
    //printf("%d\n", m[2][3]);

    //for (int i = 0; i < 3; i++)
    //{
    //    free(m[i]);  // ���� ���� �޸� ����
    //}

    //free(m);  // ���� ���� �޸� ����


    // 4. �Է��� ũ�⸸ŭ �޸𸮸� �Ҵ��Ͽ� 2���� �迭 ����

    int row, col;

    printf("����� �� ���̿� �� ���̸� �Է����ּ��� : ");
    scanf("%d %d", &row, &col);
    printf("\n");

    int** m = malloc(sizeof(int*) * row);

    for (int i = 0; i < row; i++)
    {
        m[i] = malloc(sizeof(int) * col);
    }

    for (int j = 0; j < row; j++)
    {
        for (int k = 0; k < col; k++)
        {
            m[j][k] = j + k;
        }
    }

    for (int j = 0; j < row; j++)
    {
        for (int k = 0; k < col; k++)
        {
            printf("%d ", m[j][k]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++) {
        free(m[i]);
    }

    free(m);

    return 0;
}