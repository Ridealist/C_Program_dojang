#include <stdio.h>

int string()
{
    // 1. ���ڿ� ���ڿ� ������
    char c1 = 'a';
    char* s1 = "Hello";  // ���ڿ��� ������ ���� �������� �ʰ� �����͸� �̿��ؼ� ������.
    // ���ڿ� ���ͷ��� �ִ� �޸� �ּҴ� '�б� ����' -> �ٸ� ���ڿ��� ��� ���� ����.
    // printf("%c\n", s1[0]); -> 'H'
    // s1[0] = 'X';  -> ������ ����
    // printf("%c\n", s1[0]);

    // ���ڿ� ���ͷ��� ����Ǵ� ��Ҵ� �����Ϸ��� �˾Ƽ� ����.

    printf("%p\n", s1);
    printf("%p\n", &s1[0]);
    printf("\n");

    // *(s1 + 2) = 'e';  // ���� ������ ����

    printf("%c\n", c1);
    printf("���ڿ��� %s\n", s1);
    printf("���ڿ� �ּҴ� %p\n", s1);

    s1 = "Hola";
    printf("�ٲ� ���ڿ��� %s\n", s1);


    // 2. ���ڿ� �����Ϳ��� �ε����� ���ڿ� ����
    char* str1 = "Hello";

    printf("%c\n", str1[0]);
    printf("%c\n", str1[4]);
    printf("%c\n", str1[5]);  // ���ڿ� �� �� NULL(\0) ���. NULL�� ȭ�鿡 ǥ�õ��� ����.
    printf("%c\n", str1[6]);  // ���ڿ� �� �ε��� �Ѿ�� NULL���...?
    printf("%c\n", str1[1]);

    // str1[0] = 'X'; -> ���� ������ ����.  ���� ���ͷ��� ����Ű�� �޸� �ּҴ� �б� ����.


    // 3. �迭 ���·� ���ڿ� ����
    char string[10] = "Hello";

    printf("%s\n", string);

    printf("%c\n", string[0]);
    printf("%c\n", string[4]);
    printf("%c\n", string[8]);   // �Ҵ���� ���� �ε��� NUL(\0) ���. NULL�� ȭ�鿡 ǥ�õ��� ����.
    printf("%c\n", string[15]);  // �����Ⱚ ���.
    printf("%c\n", string[0]);

    string[0] = 'X';

    printf("%s\n", string);  // �ε����� ������ �� �Ҵ� ����
    // char string[10] = "Hello"; �迭�� ���ڿ��� ��� ����Ǳ� ����

    return 0;
}