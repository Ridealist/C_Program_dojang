#include <stdio.h>
#include <stdlib.h>

void allocMemoryFalse(void* ptr, int size) {
    ptr = malloc(size);
}

void allocMemory(void** ptr, int size)
{
    *ptr = malloc(size);  // void **ptr을 역참조하여 void *ptr에 메모리 할당
}

// 문자열 매개변수는 문자열 포인터로 지정
void helloString(char* s1) {  // char 포인터 매개변수 한 개 지정
    printf("Hello, %s\n", s1);
}

void helloStringArray(char s1[]) {    // 반환값 없음, char 배열을 매개변수로 지정, 크기 생략
    printf("Hello, %s\n", s1);
}

int main()
{
    // 3. 이중 포인터 매개변수 사용하기
    long long* numPtr = NULL;

    // allocMemoryFalse(numPtr, sizeof(long long));

    // *numPtr = 10;  // 메모리가 할당되지 않았으므로 실행 에러

    // 단일 포인터 long long *numPtr의 메모리 주소는 long long **와 같음, 할당할 크기도 넣음
    allocMemory((void**)&numPtr, sizeof(long long));

    *numPtr = 10;
    printf("%lld\n", *numPtr);

    free(numPtr);


    // 4. 문자열 매개변수 사용하기
    helloString("June");  // 함수를 호출할 때 문자열의 주소가 매개변수에 전달됨.

    char str[20] = "world!";   // 배열 형태의 문자열
    helloString(str);

    return 0;
}