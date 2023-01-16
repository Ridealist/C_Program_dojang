#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char input[31];
    // char word[31];
    int len;
    bool ispal = true;
    
    scanf("%[^\n]s", input);
    
    // char* ptr = strtok(input, " ");

    // while (ptr != NULL)
    // {
    //     strcat(word, ptr);
    //     ptr = strtok(NULL, " ");
    // }

    len = strlen(input);
    
    int start = 0;
    int end = len - 1;

    while (start < end)
    {
        if (input[start] == ' ')
        {
            start++;
            continue;
        }
        if (input[end] == ' ')
        {
            end--;
            continue;
        }
        if (input[start] != input[end])
        {
            ispal = false;
            break;
        }

        start++;
        end--;
    }

    // for (int i = 0; i < strlen(word) - 1; i++)
    // {
    //     if (word[i] != word[strlen(word) - 1 - i])
    //     {
    //         ispal = false;
    //         break;
    //     }
    // }

    printf("%d\n", ispal);

    return 0;
}