#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int inputToString()
{
    // 1. �Է� ���� �迭 ������ ���ڿ��� �����ϱ�
    // char s1[30];

    // printf("���ڿ��� �Է��ϼ���: ");

    // scanf("%s", &s1); -> �迭�� ������ó�� �̹� �ּҸ� ��� ����. &(empersand) ������ ���ʿ�
    // scanf("%s", s1);
    // scanf("%[^\n]s", s1);  // ������� �����Ͽ� ���ڿ� �Է¹ޱ�

    // printf("%s\n", s1);


    // 2. �Է� ���� ���ڿ� �����Ϳ� �����ϱ�
    // ���ڿ��� �� ������ ���� �����ؾ� ��!
    //char* strPtr = malloc(sizeof(char) * 20);

    //scanf("%[^\n]s", strPtr);  // �������̹Ƿ� &�� ������ �ʰ� �״�� ����

    //printf("%s\n", strPtr);

    //free(strPtr);


    // 3. ���ڿ� ���� �� �Է¹ޱ�
    char str1[10];
    char str2[10];

    printf("���ڿ� �� �� �Է��ϼ���: ");
    scanf("%s %s", str1, str2);

    printf("%s\n", str1);
    printf("%s\n", str2);


    return 0;
}