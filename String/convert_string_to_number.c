#include <stdio.h>
#include <stdlib.h>    // atoi 함수가 선언된 헤더 파일

int main()
{
    // 1. 문자열을 정수로 변환
    char *s1 = "283";   // "283"은 문자열
    char *s2 = "28a30";  // 알파벳, 특수문자, 등이 포함되면 해당 문자부터 변환 안함.
    char *s3 = "283!";
    char *s4 = "283!30";
    char *s5 = "a30";
    char *s6 = "!30";
    
    int num1;

    // 'A'SCII string 'to' 'i'nteger -> atoi
    // int atoi(문자열) : 성공하면 변환된 정수를 반환, 실패하면 0 반환 
    printf("%d\n", atoi(s1));   // 283       // 문자열을 정수로 변환하여 num1에 할당
    printf("%d\n", atoi(s2));   // 28
    printf("%d\n", atoi(s3));   // 283
    printf("%d\n", atoi(s4));   // 283
    printf("%d\n", atoi(s5));   // 0
    printf("%d\n", atoi(s6));   // 0


    // 2. 특정 진법 문자열 정수 변환
    char* sl1 = "0xaf10";
    int num2;

    // 'st'ring 'to' 'l'ong : strtol
    // long strtol(문자열, 끝 포인터, 진법) -> 성공하면 정수 반환, 실패하면 0 반환
    // 계산할 수 없는 문자를 발견하면 '끝 포인터'가 가리키는 곳으로 설정함
    num2 = strtol(sl1, NULL, 16);

    printf("%x %d\n", num2, num2);  // af10 44816

    // 여러 개의 정수로 된 문자열
    char* sl2 = "0xaf10 42 0x27c 8521";
    int num3;
    int num4;
    int num5;
    int num6;
    char* end;  // 이전 숫자의 끝부분을 저장하기 위한 포인터

    // sl2 = "0xaf10 42 0x27c 8521"
    // end = " 42 0x27c 8521" -> end[0] 포인터 위치로 설정
    num3 = strtol(sl2, &end, 16);  // 끝 포인터에 end의 메모리 주소 넣어주기
    num4 = strtol(end, &end, 10);  // -> strtol 실행 이후 끝 포인터가 이전 숫자의 끝부분 부터 시작
    num5 = strtol(end, &end, 16);  // end로 숫자의 끝부분부터 변환 시작
    num6 = strtol(end, NULL, 10);  // 더 변환할게 없다면 끝 포인터에 NULL 넣어주기

    printf("%x\n", num3);
    printf("%d\n", num4);
    printf("%x\n", num5);
    printf("%d\n", num6);


    // 3. 문자열을 실수로 변환
    char* sf1 = "35.234621";
    char* sf2 = "3.e5";  // 알파벳 e로 지수 표시된 문자열도 변환 가능
    float fnum1;
    float fnum2;

    // 'A'SCII String 'to' 'F'loat
    // double atof(문자열) : 성공하면 실수, 실패하면 0 반환
    fnum1 = atof(sf1);
    fnum2 = atof(sf2);

    // atoi 마찬가지로 영문자, 특수문자 포함되어 있으면 해당 문자부터 변환 하지 않음
    /*
    35.283672f → 35.283672
    35.2836f72 → 35.283600
    35.283672! → 35.283672
    35.2836!72 → 35.283600
    a35.283672 → 0.000000
    !35.283672 → 0.000000
    abc → 0.000000
    !@# → 0.000000
    */

    printf("%f\n", fnum1);    // 35.234621
    printf("%e %f\n", fnum2, fnum2);    // 3.000000e+05 300000.000000
    printf("\n");

    // 'str'ing 'to' 'f'loat
    // strtof(문자열, 끝 포인터)
    
    // string to double
    // strtod(문자열, 끝 포인터)
    char* string = "35.23456 3.e5 9.2 7.e-5";
    // 9.2f를 넣으면 안됨. 9.2에서 끊기고 "f 7.e-5" 형태가 되어 다음 strtof가 0을 반환함.
    float ffnum1, ffnum2, ffnum3, ffnum4;
    char* endPtr;

    ffnum1 = strtof(string, &endPtr);
    ffnum2 = strtof(endPtr, &endPtr);
    ffnum3 = strtof(endPtr, &endPtr);
    ffnum4 = strtof(endPtr, NULL);

    printf("%f\n", ffnum1);
    printf("%e\n", ffnum2);
    printf("%f\n", ffnum3);
    printf("%e\n", ffnum4);

    return 0;
}