#include <stdio.h>
#include <stdlib.h> // malloc, free �Լ��� ����� ��� ����
#include <string.h> // meset �Լ� ����

int memory()
{
    // 1. �޸� �Ҵ�
    int num1 = 20;
    int* numPtr1;

    numPtr1 = &num1;

    int* numPtr2;

    numPtr2 = malloc(sizeof(int));  // int�� ũ�� 4����Ʈ��ŭ ���� �޸� �Ҵ�

    printf("%p\n", numPtr1);
    printf("%p\n", numPtr2); // ���� �Ҵ�� �޸� �ּ� ���
    
    free(numPtr2);  // �������� �Ҵ�� �޸� ����

    // 2. �޸𸮿� �� ����
    int* ranNumPtr;

    ranNumPtr = malloc(sizeof(int));

    *ranNumPtr = 10;  // �����͸� ������ �� �� �� �Ҵ�

    printf("%d\n", *ranNumPtr); // �����͸� ������ �Ͽ� �޸𸮿� ����� �� ���

    free(ranNumPtr);

    // 3. �޸� ���� �Ѳ����� ����
    long long* longPtr = malloc(sizeof(long long));

    memset(longPtr, 0x27, 8);  // �޸𸮸� 8����Ʈ��ŭ 0x27�� ����

    printf("0x%llx\n", *longPtr);  // 0x27272727....27 : 27�� 8�� �� ����

    free(longPtr);

    // 4. null ������ ���
    int* nullPtr = NULL;
    
    printf("%p\n", nullPtr);

    return 0;
}