#include <stdio.h>
#include <stdarg.h>  // va_list, va_start, va_arg, va_end가 정의된 헤더 파일


void printNumber(int args, ...) {
    printf("%d ", args);
}

// (자료형 고정매개변수, ...)
void printNumbers(int args, ...) {   // 가변 인자 개수 = args

    // ap = argument pointer
    va_list ap;  // 가변 인자 목록 포인터

    va_start(ap, args);  // 가변 인자 목록 포인터 설정
    for (int i = 0; i < args; i++) {  // 가변 인자 개수만큼 반복
        int num = va_arg(ap, int);  // int 크기만큼 가변 인자 목록 포인터에서 값을 가져옴
                                    // ap를 int 크기만큼 순방향으로 이동
        printf("%d ", num);         // 가변 인자 값 출력
    }
    va_end(ap);         // 가변 인자 목록 포인터를 NULL로 초기화

    printf("\n");

}

void printValues(char *types, ...) {   // 가변 인자 자료형 받음

    va_list ap;
    int i = 0;

    va_start(ap, types);            // "types 문자열"에서 문자 개수를 구해서 가변 인자 포인터 설정
    while (types[i] != '\0') {      // 가변 인자 자료형이 없을 때까지 반복
        switch (types[i])           // 가변 인자 자료형으로 분기
        {
        case 'i':  // int형일 때
            printf("%d ", va_arg(ap, int));
            break;
        case 'd':  // double형일 때
            printf("%f ", va_arg(ap, double));
            break;
        
        // char형 문자일 때 va_arg 매크로에 "int"를 사용해야 함!
        /*
        가변인자 자료형이 int보다 작으면 int로, float은 double로 지정해야 함
        char, short, bool -> int
        float -> double
        */
        case 'c':  // char형 문자일 때
            printf("%c ", va_arg(ap, int /*char NO! NO!*/));   // int 크기만큼 값을 가져옴
            break;
        case 's':  // char*형 문자열일 때
            printf("%s ", va_arg(ap, char*));
            break;

        default:
            break;
        }
        i++;
    }
    va_end(ap);

    printf("\n");
}


int main(void) {
    // 1. 가변 인자 함수 만들기
    printNumber(1, 10);
    printNumber(2, 10, 20);
    printNumber(3, 10, 20, 30);
    printNumber(4, 10, 20, 30, 40);
    printf("\n");

    printNumbers(1, 10);
    printNumbers(2, 10, 20);
    printNumbers(3, 10, 20, 30);
    printNumbers(4, 10, 20, 30, 40);
    printf("\n");


    // 2. 자료형이 다른 가변 인자 함수 만들기
    printValues("i", 10);
    printValues("ci", 'a', 10);
    printValues("dci", 1.234567, 'a', 10);
    printValues("sicd", "Hello, world!", 10, 'a', 1.234567);

    return 0;
}