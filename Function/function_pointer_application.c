#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}

// 구조체 멤버로 함수 포인터 활용
struct Calc {
    int (*fp)(int, int);
};

// 함수 매개변수로 함수 포인터 활용
void executer(int (*fp)(int, int), int a, int b) {
    printf("%d\n", fp(a, b));
}

// 함수 반환값으로 함수 포인터 활용
int (*return_func(int a, int b))(int, int) {
    if (a - b > 0)
        return add;
    else 
        return sub;
}

int (*get_add())(int, int) {
    return add;
}

// typedef로 함수 포인터 별칭 정의
         // 함수 포인터 별칭
typedef int (*FP)(int, int);

// -> 여러가지로 확장해 사용 가능
FP get_add_brief() {
    return add;
}

struct CalcBrief
{
    FP fp;
};

void executer_brief(FP fp) {
    printf("%d", fp(50, 30));
}


int main() {
    // 1. 함수 포인터 배열 사용하기
    int funcNumber;
    int num1, num2;
    int (*fp)(int, int) = NULL;

    // printf("함수 번호와 계산할 값을 입력하세요: ");
    // scanf("%d %d %d", &funcNumber, &num1, &num2);

    switch (funcNumber)
    {
    case 0:
        fp = add;
        break;
    case 1:
        fp = sub;
        break;
    case 2:
        fp = mul;
        break;
    case 3:
        fp = div;
        break;
    }

    // printf("%d\n", fp(num1, num2));

    // 위에 식을 단순화하기 위한 "함수 포인터 배열" 선언
    int (*fp_arr[4])(int, int);
    fp_arr[0] = add;
    fp_arr[1] = sub;
    fp_arr[2] = mul;
    fp_arr[3] = div;

    // printf("%d\n", fp_arr[funcNumber](num1, num2));

    // 배열의 모든 함수 호출
    for (int i = 0; i < sizeof(fp_arr) / sizeof(fp_arr[0]); i++) {
        // printf("%d\n", fp_arr[i](num1, num2));
    }

    // 함수 포인터 배열 선언과 동시에 초기화
    // int (*fp_arr[4])(int, int) = {add, sub, mul, div};


    // 2. 함수 포인터를 구조체 멤버로 사용하기
    struct Calc c;

    c.fp = add;

    // 변수.함수포인터(arg1, arg2);
    printf("%d\n", c.fp(10, 20));


    // 3. 함수 포인터를 함수 매개변수로 사용하기
    // add함수의 메모리 주소 전달 -> add()를 사용하면 반환값이 전달되므로 주의

    int (*fppp)(int, int);
    fppp = add;
    executer(fppp, 10, 50);
    
    executer(add, 10, 50);


    // 4. 함수 포인터를 함수의 반환값으로 사용하기
                        // 앞의 함수에 전달  // 반환된 함수에 전달
    printf("%d\n", return_func(10, 40)(40, 50));
    printf("%d\n", get_add()(40, 50));


    // 5. typedef로 함수 포인터 별칭 정의하기
    printf("%d\n", get_add_brief()(30, 40));

    FP fppppp = sub;  // 포인터 별칭 변수 선언
    FP fpppparr[10];  // 포인터 별칭 배열 선언

    return 0;
}