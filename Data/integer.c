#include <stdio.h>
#include <limits.h>  // 자료형의 최댓값과 최솟값이 정의된 헤더 파일
#include <stdint.h>  // 크기별로 정수 자료형이 정의된 헤더 파일

int main()
{
    /*
    CPU에서 한 번에 처리할 수 있는 정보의 단위를 워드(WORD)라고 합니다.
    https://ko.wikipedia.org/wiki/%EC%9B%8C%EB%93%9C_(%EC%BB%B4%ED%93%A8%ED%8C%85)

    보통 int는 워드 사이즈에 맞춰져 있습니다.

    don't rely on 1 byte being 8 bit in size
    use CHAR_BIT instead of 8 as a constant to convert between bits and bytes

    하드웨어를 다루는 C/C++ 같은 언어에서 8비트 = 1바이트라고 가정하지 말라.
    비트와 바이트를 변환할 때는 상수 8 대신에 CHAR_BIT를 써라.

    WORD는 "CPU가 레지스터에 한 번에 옮길 수 있는 데이터의 크기"를 뜻하므로
    32비트 시스템에서는 1 WORD = 32비트이고,
    64비트 시스템에서는 1 WORD = 64비트이지만,
    역사적으로는 16비트 시스템에서 WORD = 16비트로 썼으므로
    32비트 시스템 어셈블리에서는 DWORD(더블 워드) = 32비트로 표기합니다.

    C 언어 표준안에서 int는 16비트 이상이면 되고, long은 32비트 이상이면 됩니다.
    그러나 정수 타입의 크기는 C 언어 구현체와 플랫폼을 따라 갑니다.
    */

    // 1. 정수형 변수 선언하기
    // 1-1. 부호가 있는 정수 자료형
    char num1 = -10;           // 1바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    short num2 = 30000;        // 2바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    int num3 = -1234567890;    // 4바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    long num4 = 1234567890;    // 4바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    long long num5 = -1234567890123456789;     // 8바이트 부호 있는 정수형으로 변수를 
                                               // 선언하고 값 할당

    // char, short, int는 %d로 출력
    // long은 %ld
    // long long은 %lld로 출력
    printf("%d %d %d %ld %lld\n", num1, num2, num3, num4, num5);
    // -10 30000 -1234567890 1234567890 -1234567890123456789

    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(unsigned long));
    printf("%lu\n", sizeof(signed long));
    printf("%lu\n", sizeof(long long));
    printf("%lu\n", sizeof(unsigned long long));
    printf("%d\n", __CHAR_BIT__);

    // 1-2. 부호가 없는 정수 자료형
    unsigned char num6 = 200;
    unsigned short num7 = 60000;
    unsigned int num8 = 423212312;
    unsigned long num9 = 232425251231UL;
    
    // GCC에서 컴파일 경고를 방지하려면
    // 숫자 뒤에 자료형 크기에 맞는 정수 리터럴 접미사를 붙이면 됩니다.
    unsigned long long num10 = 12345678901234567890ULL;

    /*
    unsigned char, unsigned short는 서식 지정자 %d로도 충분히 출력할 수 있지만
    
    unsigned int는 %u,
    unsigned long은 %lu,
    unsigned long long은 %llu로 출력해야 합니다.
    */

    printf("%u %u %u %lu %llu\n", num6, num7, num8, num9, num10);


    // 2. 오버플로우, 언더플로우
    // char num11 = 128;           // char에 저장할 수 있는 최댓값 127보다 큰 수를 할당
                                // 오버플로우 발생
    // char num12 = -129;          // 언더플로우 발생

    // unsigned char num13 = 256;  // unsigned char에 저장할 수 있는 최댓값 255보다 큰 수를 할당
                                // 오버플로우 발생
    // unsigned char num14 = -1;   // 언더플로우 발생

    // printf("%d %d %u %u\n", num11, num12, num13, num14);    // -128 127 0 255: 저장할 수 있는 범위를 넘어서므로 
                                                              // 최솟값 / 최댓값부터 다시 시작


    // 3. 자료형의 크기 구하기
    int num = 0;
    int size;

    // size of 표현식 -> 표현식 : 변수, 상수, 배열 등 프로그래머가 만들어낸 요소
    // size of(자료형)
    // size of(표현식)
    size = sizeof num;    // 변수 num1의 자료형 크기를 구함

    printf("num의 크기: %d\n", size);


    // 4. 최솟값과 최댓값 표현하기
    char ch = CHAR_MIN;
    short sh = SCHAR_MIN;
    int i = INT_MIN;
    long l = LONG_MIN;
    long long ll = LLONG_MIN;

    unsigned char uch = UCHAR_MAX;
    unsigned short ush = USHRT_MAX;
    unsigned int ui = UINT_MAX;
    unsigned long ul = ULONG_MAX;
    unsigned long long ull = ULLONG_MAX;

    printf("%d %d %d %ld %lld\n", ch, sh, i, l, ll);
    // -128 -128 -2147483648 -9223372036854775808 -9223372036854775808

    printf("%u %u %u %lu %llu\n", uch, ush, ui, ul, ull);
    // 255 65535 4294967295 18446744073709551615 18446744073709551615    


    // 5. 크기가 표시된 정수 자료형 사용하기
    int8_t num21 = -128;                    // 8비트(1바이트) 크기의 부호 있는 정수형 변수 선언
    int16_t num22 = 32767;                  // 16비트(2바이트) 크기의 부호 있는 정수형 변수 선언 
    int32_t num23 = 2147483647;             // 32비트(4바이트) 크기의 부호 있는 정수형 변수 선언
    int64_t num24 = 9223372036854775807;    // 64비트(8바이트) 크기의 부호 있는 정수형 변수 선언

    int8_t num31 = INT8_MAX;
    int16_t num32 = INT16_MAX;

    // int8_t, int16_t, int32_t는 %d로 출력하고 int64_t는 %lld로 출력
    printf("%d %d %d %lld\n", num21, num22, num23, num24); // -128 32767 2147483647 9223372036854775807
    printf("%d %d\n", num31, num32);

    uint8_t num25 = 255;                      // 8비트(1바이트) 크기의 부호 없는 정수형 변수 선언
    uint16_t num26 = 65535;                   // 16비트(2바이트) 크기의 부호 없는 정수형 변수 선언
    uint32_t num27 = 4294967295;              // 32비트(4바이트) 크기의 부호 없는 정수형 변수 선언
    uint64_t num28 = 18446744073709551615;    // 64비트(8바이트) 크기의 부호 없는 정수형 변수 선언

    // u(  ) -> 최솟값 모두 0
    uint32_t num41 = UINT32_MAX;
    uint64_t num42 = UINT64_MAX; 

    // uint8_t, uint16_t, uint32_t는 %u로 출력하고 uint64_t는 %llu로 출력
    printf("%u %u %u %llu\n", num25, num26, num27, num28); // 255 65535 4294967295 18446744073709551615
    printf("%lu, %llu\n", num41, num42);

    return 0;
}