#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int add(int *a, int *b) {
    return *a + *b;
}

int sub(int *a, int *b)
{
    return *a - *b;
} 

int mul(int *a, int *b)
{
    return *a * *b;
} 

int div(int *a, int *b)
{
    return *a / *b;
}


int main()
{
    char funcName[10];
    int num1, num2;

    scanf("%s %d %d", funcName, &num1, &num2);

    int (*fp)(int*, int*);

    // TODO 함수 포인터 주의사항
    /*
    incompatible pointer types assigning to 'int (*)(int *, int *)' from 'char[10]' [-Wincompatible-pointer-types]
    
    fp = funcName 이렇게 할당하면 절대 안됨.
    lvalue type : 'int (*)(int *, int *)'
    rvalue type : 'char[10]'
    문자열을 함수 포인터에 할당하는 것 자체가 불가능
    */

    // TODO switch-case 분기문 활용 주의사항
    /*
    switch (값을 판단할 변수) -> 변수는 "식에 정수 계열 형식이 있어야 함"
    {
    case (상수): -> "식은 정수 계열 상수 식이어야 함"
    }

    즉, char * 문자열 변수에 대한 switch-case 조건 분기문은 불가!
    */

    if (strcmp(funcName, "add") == 0)
        fp = add;
    else if(strcmp(funcName, "sub") == 0)
        fp = sub;
    else if(strcmp(funcName, "mul") == 0)
        fp = mul;
    else if(strcmp(funcName, "div") == 0)
        fp = div;
  
    printf("%d\n", fp(&num1, &num2));

    return 0;
}