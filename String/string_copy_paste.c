#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // 1. ���ڿ� �����ϱ�
    // 1-1. �迭�� ����� ���ڿ� �����ϱ�
    //char s1[10] = "Hello";
    //char s2[10];

    //// strcpy(����ڿ�, �������ڿ�);
    //strcpy(s2, s1); // ����� ����� ����� �迭�� ũ��� �ݵ�� NULL���� �� �� �־�� ��

    //printf("%s\n", s2);

    // 1-2. ���ڿ� �����Ϳ� ���ڿ� �����ϱ�
    char* s1 = "Hello";
    // char* s2 = "";  -> �ڵ� �Ҵ�� ���ڿ� ���ͷ� �޸𸮴� �б� �����̶� ����(������ ����'����') �Ұ���!
    char* s2 = malloc(sizeof(char) * 10);  // s2 �����Ϳ� ���� �޸� �Ҵ�

    strcpy(s2, s1);  // s1 ���ڿ��� s2�� ����

    printf("%s\n", s2);
    printf("\n");

    free(s2);


    // 2. ���ڿ� ���̱�
    // 2-1. �迭 ����� ���ڿ� ���̱�
    //char str1[10] = "world";
    //char str2[20] = "hello";  // str2 �ڿ� ���� ������ �迪 ũ�� ũ�� ����

    //// strcat(���� ���ڿ�, ���� ���ڿ�)
    //strcat(str2, str1);  // str2 �ڿ� str1�� ����

    //printf("%s\n", str2);

    // 2-2. �����ͷ� �Ҵ�� ���ڿ� ���̱�
    char* str1 = "world";
    // 1. ���Ⱑ �����ϵ��� malloc���� ���� �޸� �Ҵ�
    // 2. ���ڿ� ���� �� �ֵ���('\0'���� ���) ����� ũ�� �Ҵ�
    char* str2 = malloc(sizeof(char) * 20);

    // �޸𸮰� �Ҵ�� ���ڿ����� ���ڿ��� = �����ڷ� �Ҵ� �Ұ���
    // strcpy�� �޸𸮿� ���ڿ� ����!
    strcpy(str2, "Hello");  // 3. str2�� Hello ���ڿ� ����

    strcat(str2, str1);  // 4. ���ڿ� ���̱�

    printf("%s\n", str2);

    free(str2);


    // 3. �迭 ���� ���ڿ� -> ���ڿ� �����Ϳ� �����ϱ�
    //char char_array[20] = "Hello world!";
    //char* ptr = malloc(sizeof(char) * 25);

    //strcpy(ptr, char_array);

    //printf("%s\n", ptr);

    //free(ptr);


    // 4. �迭 ���� ���ڿ��� �����Ϳ� ���̱�
    char char_array[20] = "Hello world!";
    char* ptr = malloc(sizeof(char) * 25);

    strcpy(ptr, "Wow, ");

    strcat(ptr, char_array);

    printf("%s\n", ptr);

    free(ptr);

    return 0;
}