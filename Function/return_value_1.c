#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int one()
{
    return 1;
}

float realNumber()
{
    return 1.2345f;
}

bool truth()
{
    return true;
}

/*
반환값자료형 *함수이름()
{
    return 반환값;
}
*/
// int * ten()  // int 포인터를 반환하는 함수
// {
//     int num1 = 10;  // num1은 지역변수 -> 함수 종료와 함께 소멸
//     return &num1;   // 함수에서 지역 변수 주소를 반환하면 안됨! 
// }

int * correctten()
{
    int num1 = 10;
    // int * ptr = malloc(sizeof(int *));
    // ptr = &num1;  // num1의 주소를 저장하는 것도 잘못된 방법! num1 자체가 소멸되기 때문.
    
    int * ptr = malloc(sizeof(int));  // int 크기만큼 동적 메모리 할당
    *ptr = num1;  // 역참조로 10 저장
    
    return ptr; // 포인터 반환
}

char * helloDynamicMemory()
{
    char * s1 = malloc(sizeof(char) * 6);
    strcpy(s1, "hello");
    return s1;
}

char * helloLiteral()
{
    char * s1 = "hello";    // 문자열 hello는 메모리에 저장되어 있으므로 사라지지 않음
    return s1;
}


int main()
{
    // 1-1. 정수 반환값
    int num1;

    num1 = one();
    // 1. one() 함수 호출
    // 2. 반환값이 num1 변수에 할당(저장)됨

    printf("%d\n", num1);

    // 1-2. 실수, 불리언 반환값
    float num2;
    bool b1;

    num2 = realNumber();
    b1 = truth();

    printf("%f %d\n", num2, b1);


    // 2. 포인터 반환
    int *numPtr;

    // numPtr = ten();
    numPtr = correctten();

    // 10: 값이 나오긴 하지만 이미 사라진 변수를 출력하고 있음
    printf("%d\n", *numPtr);  // 10: 메모리를 해제하기 전까지 안전함

    free(numPtr);    // 다른 함수에서 할당한 메모리라도 반드시 해제해야 함

    // 문자열 반환
    char *charPtr1;
    char *charPtr2;

    charPtr1 = helloDynamicMemory();
    charPtr2 = helloLiteral();
/*
리터럴 (literal)
리터럴이란 "문자그대로" 라는 뜻이다.

In computer science, a literal is a notation for representing a fixed value in source code.
컴퓨터 사이언스에서, 리터럴은 "원시코드에 있는 어떠한 고정된 값"을 나타내기 위해 사용되는 용어이다.

원시 프로그램에서 어떠한 숫자 또는 기호로서 다른 데이터를 가리키는 역할을 하지 않고 "그 자신이 바로 데이터로서 사용되는 것"을 이른다.

---

컴파일러는 문자열 상수 (또는 리터럴) 를 보면, 메모리 어딘가에 해당 문자열을 위한 공간을 마련하여 저장한다.
이것은 리터럴이므로 별도의 이름을 갖지 않는다. 대신 어딘가에 저장되어있으므로, 주소는 갖는다.

문자열 상수의 평가값이 바로 문자열의 시작주소이다. 즉, 평가값은 const char* 형이고, 따라서, char* 형 변수에 배정할수 있다.
pinrtf() 함수의 프로토타입에서 문자열 상수를 인자로 받을때, const char* 를 썼던것을 기억하자.

ex.

#include<stdio.h>

int main(void)
{
    char *p;

     p = "Hello!\n";            // 메모리 어딘가에 문자열을 저장하고, 그 시작주소를 p가 포인팅하도록 한다.

     printf(p);                    //  p가 포인팅 하는 곳에서 시작하여 NULL문자를 만날때까지 문자를 인쇄한다.

     return 0;
}

출처 : https://sciphy.tistory.com/868
*/


    printf("%s\n", charPtr1);
    printf("%s\n", charPtr2);

    free(charPtr1);    // 동적 메모리 해제 반드시!!!

    return 0;
}