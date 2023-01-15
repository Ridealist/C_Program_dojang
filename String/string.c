#include <stdio.h>

int string()
{
    // 1. 문자와 문자열 포인터
    char c1 = 'a';
    char* s1 = "Hello";  // 문자열은 변수에 직접 저장하지 않고 포인터를 이용해서 저장함.
    // 문자열 리터럴이 있는 메모리 주소는 '읽기 전용' -> 다른 문자열을 덮어쓸 수는 없다.
    // printf("%c\n", s1[0]); -> 'H'
    // s1[0] = 'X';  -> 컴파일 에러
    // printf("%c\n", s1[0]);

    // 문자열 리터럴이 저장되는 장소는 컴파일러가 알아서 결정.

    printf("%p\n", s1);
    printf("%p\n", &s1[0]);
    printf("\n");

    // *(s1 + 2) = 'e';  // 쓰기 엑세스 위반

    printf("%c\n", c1);
    printf("문자열은 %s\n", s1);
    printf("문자열 주소는 %p\n", s1);

    s1 = "Hola";
    printf("바뀐 문자열은 %s\n", s1);


    // 2. 문자열 포인터에서 인덱스로 문자에 접근
    char* str1 = "Hello";

    printf("%c\n", str1[0]);
    printf("%c\n", str1[4]);
    printf("%c\n", str1[5]);  // 문자열 맨 뒤 NULL(\0) 출력. NULL은 화면에 표시되지 않음.
    printf("%c\n", str1[6]);  // 문자열 맨 인덱스 넘어가도 NULL출력...?
    printf("%c\n", str1[1]);

    // str1[0] = 'X'; -> 쓰기 엑세스 위반.  문자 리터럴을 가리키는 메모리 주소는 읽기 전용.


    // 3. 배열 형태로 문자열 선언
    char string[10] = "Hello";

    printf("%s\n", string);

    printf("%c\n", string[0]);
    printf("%c\n", string[4]);
    printf("%c\n", string[8]);   // 할당되지 않은 인덱스 NUL(\0) 출력. NULL은 화면에 표시되지 않음.
    printf("%c\n", string[15]);  // 쓰레기값 출력.
    printf("%c\n", string[0]);

    string[0] = 'X';

    printf("%s\n", string);  // 인덱스로 접근해 값 할당 가능
    // char string[10] = "Hello"; 배열에 문자열이 모두 복사되기 때문

    return 0;
}