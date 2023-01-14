#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int compareStringLength()
{
    //1. ���ڿ� ���� ���ϱ�
    char* s1 = "Hello";
    char s2[10] = "Hello";

    //strlen(���ڿ�������)
    //strlen(���ڹ迭)
    printf("%d\n", strlen(s1)); // 5 : NULL �κ� ���� ���� ���ڿ� ���� ��ȯ
    printf("%d\n", strlen(s2));  // 5 : '�迭�� ũ��'�� '���ڿ��� ����'�� ����!
    printf("\n");


    //2. ���ڿ� ���ϱ�

    //strcmp(���ڿ�1, ���ڿ�2) -> �� ���ڿ��� ������ ��
    // -1 : ASCII �ڵ� �������� �� ���ڿ�(���ڿ�2)�� Ŭ ��
    // 0 : ���� ��
    // 1 : �� ���ڿ�(���ڿ�1)�� Ŭ ��
    // ���ڿ� ù ��° ���ں��� ���ʴ�� ��. �� ������ ASCII �ڵ�.
    int ret = strcmp(s1, s2);

    printf("%d\n", ret); // 0 : ���ڿ��� ������ 0 ��ȯ

    printf("%d\n", strcmp("aaa", "aaa")); // aaa = 97 97 97, �����Ƿ� 0 ��ȯ
    printf("%d\n", strcmp("aab", "aaa")); // aab = 97 97 98, �� ���ڿ��� ũ�Ƿ� 1 ��ȯ
    printf("%d\n", strcmp("aab", "aac")); // aac = 97 97 99 �� ���ڿ��� ũ�Ƿ� -1 ��ȯ

    // ����ڰ� �Է��� �� ���ڿ� ��

    char str1[20];
    char str2[20];

    scanf("%s %s", str1, str2);

    int diff = strcmp(str1, str2);

    // �ƿ����� ASCII �ڵ� ���� ��ȯ
    //if (diff < -1)
    //    printf("'%s' ���ڿ��� �� Ů�ϴ�.", str2);
    //else if (diff == 0)
    //    printf("�� ���ڿ��� �����ϴ�.");
    //else
    //    printf("'%s' ���ڿ��� �� Ů�ϴ�.", str1);

    switch (diff)
    {
    case 0:
        printf("�� ���ڿ��� �����ϴ�.");
        break;
    case -1:
        printf("'%s' ���ڿ��� �� Ů�ϴ�.", str2);
        break;
    case 1:
        printf("'%s' ���ڿ��� �� Ů�ϴ�.", str1);
        break;
    }


    return 0;
}