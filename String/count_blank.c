#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char str[1001];
    int cnt = 0;

    scanf("%[^\n]s", str);

    char* ptr = strchr(str, ' ');
    
    while (ptr != NULL)
    {
        cnt++;
        ptr = strchr(ptr + 1, ' ');
    }

    printf("%d\n", cnt);

    return 0;
}