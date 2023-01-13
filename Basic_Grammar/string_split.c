#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringSplit()
{
    //char* str = malloc(sizeof(char) * 100);

    //scanf("%[^\n]s", str);

    //char* str_split = strtok(str, " ");

    //while (str_split != NULL)
    //{
    //    printf("%s\n", str_split);
    //    str_split = strtok(NULL, " ");
    //}

    //free(str);

    char str1[15];
    char str2[15];
    char str3[15];
    char str4[15];

    scanf("%s %s %s %s", str1, str2, str3, str4);

    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);
    printf("%s\n", str4);

    return 0;
}