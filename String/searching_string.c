#include <stdio.h>
#include <string.h>

int main()
{
    // 1. 문자열 안에서 문자로 검색하기\n")
    char s1[30] = "A Garden Diary";

    // strchr(대상문자열, 검색할문자)
    // 문자를 찾으면 문자로 시작하는 문자열 포인터 반환, 문자가 없으면 NULL 반환
    char* ptr = strchr(s1, 'a');  // 'a'로 시작하는 문자열 검색, 포인터 반환
    printf("first poiter : %p\n", ptr);


    while (ptr != NULL) // 검색된 문자열이 없을 때까지 반복
    {
        printf("%s\n", ptr);
        ptr = strchr(ptr + 1, 'a'); // 포인터에 1 더하여 'a' 다음부터 검색
        printf("next poiter : %p\n", ptr);
    }

    // 2. 문자열 오른쪽 끝부터 문자열 검색하기\n")

    // strrch(대상문자열, 검색할문자)
    // 문자열 끝부터 역순으로 검색
    // char* ptr2 = strrchr(s1, 'a');

    // while (ptr2 != NULL)
    // {
    //     printf("%s\n", ptr2);
    //     ptr2 = strrchr(ptr2 - 1, 'a');
    // }
    // TODO 왜 안될까 생각해보기!
    

    // 3. 문자열 안에서 문자열로 검색하기
    
    // strstr(대상문자열, 검색할문자열);
    // 문자열을 찾았으면 문자열로 시작하는 '문자열 포인터' 반환, 없으면 NULL 반환 
    char s2[100] = "A Garden Diary A Garden Diary A Garden Diary";
    
    char* ptr2 = strstr(s2, "den");
    
    while (ptr2 != NULL)
    {
        printf("%s\n", ptr2);
        ptr2 = strstr(ptr2 + 1, "den");
    }

    return 0;
}