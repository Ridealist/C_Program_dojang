#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[30];
    int n = 4;

    scanf("%s", string);

    int l = strlen(string);

    if (l < n)
    {
        printf("wrong\n");
        return 0;
    }

    for (int i = 0; i < l - (n - 1); i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c", string[i + j]);
        printf("\n");
    }

    return 0;
}