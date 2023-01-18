#include <stdio.h>
#include <float.h>    // 실수 자료형의 양수 최솟값, 최댓값이 정의된 헤더 파일
// #include <limits.h>

int main()
{
    // 1. 실수형 변수 선언
    float num1 = 0.1f;  // 단정밀도 부동소수점 변수를 선언하고 값을 할당
                        // float은 숫자 뒤에 f 붙임
    
    double num2 = 3281.213421;  // 배정밀도 부동소수점 변수 선언
                                // double은 숫자 뒤에 아무것도 붙이지 않음

    long double num3 = 9.234123l;  // 배정밀도 부동소수점
                                   // long double은 숫자 뒤에 l 붙임
    
    // float와 double은 %f로 출력, long double은 %Lf로 출력
    printf("%f %f %Lf\n", num1, num2, num3);

    // 1-2. 지수 표기법
    float num4 = 3.e5f;   // 지수 표기법으로 300000을 표기

    double num5 = -1.3827e-2;  // 지수 표기법으로 -0.013827을 표기

    long double num6 = 5.21e+9l;

    // float와 double은 %f로 출력, long double은 %Lf로 출력
    printf("%f %f %Lf\n", num4, num5, num6); // 300000.000000 -0.013827 5210000000.000000

    // 지수 표기법으로 출력할 때는 float와 double은 %e로 출력, long double은 %Le로 출력
    printf("%e %e %Le\n", num4, num5, num6); // 3.000000e+05 -1.382700e-02 5.210000e+09


    // 2. 자료형의 크기
    float num11 = 0.0f;
    double num12 = 0.0;
    long double num13 = 0.0l;

    printf("float: %zd, double: %zd, long double: %zd\n",
        sizeof(num11),     // 4: sizeof로 float 변수의 자료형 크기를 구함
        sizeof(num12),     // 8: sizeof로 double 변수의 자료형 크기를 구함
        sizeof(num13)      // 8: sizeof로 long double 변수의 자료형 크기를 구함
    );
    printf("\n");


    // 3. 최솟값과 최댓값
    float num31 = FLT_MIN;
    float num32 = FLT_MAX;

    double num33 = DBL_MIN;
    double num34 = DBL_MAX;

    long double num35 = LDBL_MIN;    // long double의 양수 최솟값
    long double num36 = LDBL_MAX;    // long double의 양수 최댓값

    printf("%.40f %.2f\n", num31, num32);    // 0.0000000000000000000000000000000000000118
                                           // 340282346638528859811704183484516925440.00

    printf("%e %e\n", num33, num34);         // 2.225074e-308 1.797693e+308
    printf("%Le %Le\n", num35, num36);       // 2.225074e-308 1.797693e+308


    // 4. 오버플로우 언더플로우
    float num41 = FLT_MIN;
    float num42 = FLT_MAX;

    // float의 양수 최솟값을 100000000.0으로 나누면 아주 작은 수가 되면서 언더플로우 발생
    num41 = num41 / 1000000000.0f;

    // float의 양수 최댓값에 1000.0을 곱하면 저장할 수 있는 범위를 넘어서므로 오버플로우 발생
    num42 = num42 * 10000000.0f;

    printf("%e %e\n", num41, num42);
    // 0.000000e+00 inf: 실수의 언더플로우는 0
    // 오버플로우는 무한대가 됨

    return 0;
}