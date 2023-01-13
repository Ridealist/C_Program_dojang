#include <stdio.h>

int main()
{
    int arr[3] = { 5, 10, 15 };  // arr = 00000063E40FFB48

    printf("arr = %p\n", arr);
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf("arr[i] = %d\n", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf("&arr[i] = %p\n", &arr[i]);
    }
    /*
    &arr[i] = 00000063E40FFB48  -> int�� �迭 ��Ұ��� �ּ� ���� ���̴� 4����Ʈ
    &arr[i] = 00000063E40FFB4C
    &arr[i] = 00000063E40FFB50
    */


    char arr_char[3] = { 5, 10, 15 };

    printf("arr_char = %p\n", arr_char);  // arr_char = 000000A7C6CFF5A4
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf("arr_char[i] = %d\n", arr_char[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf("&arr_char[i] = %p\n", &arr_char[i]);
    }
    /*
&arr_char[i] = 000000A7C6CFF5A4
&arr_char[i] = 000000A7C6CFF5A5
&arr_char[i] = 000000A7C6CFF5A6
    */

    /*
    arr/arr_char �迭�� '�ּ�'�� �����ϰ� �־, ������ ������ ����
    �迭�� �ٸ� ������ �ٲ� �� ����
    -> "��� ������ ������", "������ ���" ��� ����
    */


    int arr1[3] = { 5, 10, 15 };
    double arr2[3] = { 5.5, 10.5, 15.5 };

    printf("arr1 = %d\n", arr1);  // 4�� ����
    printf("(arr1 + 1) = %d\n", (arr1 + 1));
    printf("(arr1 + 2) = %d\n", (arr1 + 2));
    printf("*(arr1 + 1) = %d\n\n", *(arr1 + 1));  // *(arr1 + 1) = 10
    // (arr + 1) ���� 1 �� arr[1] �̶�� �� �� �ִ�.


    printf("arr2 = %d\n", arr2);  // 8�� ����
    printf("(arr2+ 1) = %d\n", (arr2 + 1));
    printf("(arr2 + 2) = %d\n", (arr2 + 2));
    printf("*(arr2 + 1) = %.2f\n", *(arr2 + 1));  // *(arr2 + 1) = 10.50


    return 0;
}