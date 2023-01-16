#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    // 긴 숫자가 올 수 있으므로 long long으로 변수 선언
    long long num;
    char num_string[30];
    bool isPalindrone = true;

    printf("정수를 입력하세요 : ");
    // lld 서식지정자
    scanf("%lld", &num);

    sprintf(num_string, "%lld", num);
    // sprintf(text, "%lld", num1);
    // begin++;
    // end--;

    int length = strlen(num_string);

    for (int i = 0; i < length / 2; i++)
    {
        if (num_string[i] != num_string[length - 1 - i])
        {
            isPalindrone = false;
            break;
        }
    }

    // while로도 구현 가능

    // int start = 0;
    // int end = length - 1;
    // while (start < end)
    // {
    //     if (num_string[start] != num_string[end])
    //     {
    //         isPalindrone = false;
    //         break;
    //     }
    //     start++;
    //     end--;
    // }

    printf("%d\n", isPalindrone);

    return 0;
}