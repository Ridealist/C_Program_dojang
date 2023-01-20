#include <stdio.h>

void swapNumber(int* first, int* second) {
    int temp;  // 임시 보관 변수

    // 역참조로 값을 가져오고, 값을 다시 역참조한 메모리에 저장
    temp = *first;
    *first = *second;
    *second = temp;
}

enum Type {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT
};

// 반환값 없음, 매개변수로 void 포인터 2개 + 변수의 자료형 알려줄 열거형 받음
void swapValue(void* ptr1, void* ptr2, enum Type t) {
    switch (t)
    {
    case TYPE_CHAR:    // 문자면 (char *)로 변환한 뒤 역참조하여 값을 서로 바꿈
    {
        char temp;
        // *ptr1 -> void 포인터는 역참조 불가.
        // 어떤 자료형으로 역참조할 지 알려주기 위해 (char *) 포인터 타입 캐스팅 필요.
        temp = *(char *)ptr1;
        *(char *)ptr1 = *(char *)ptr2;
        *(char *)ptr2 = temp;
        break;
    }
    case TYPE_INT:     // 정수면 int *로 변환한 뒤 역참조하여 값을 서로 바꿈
    {
        int temp;
        temp = *(int *)ptr1;
        *(int *)ptr1 = *(int *)ptr2;
        *(int *)ptr2 = temp;
        break;
    }
    case TYPE_FLOAT:    // 실수면 float *로 변환한 뒤 역참조하여 값을 서로 바꿈
    {
        float temp;
        temp = *(float *)ptr1;
        *(float *)ptr1 = *(float *)ptr2;
        *(float *)ptr2 = temp;
        break;
    }
    }
}


int main()
{
    /*
        포인터는 메모리 영역을 조작하는 것.
        &num1 = 메모리 공간에 num1이 저장된 주소
        &num2 = 메모리 공간에 num2가 저장된 주소
        
        num1의 주소를 역참조해 값을 찾고 그 값을 num2의 값으로 변경
        num2의 주소를 역참조해 그 값을 num1의 값으로 변경
    */

    // 1. 포인터 매개변수 사용하기
    // int num1 = 10;
    // int num2 = 20;

    // swapNumber(&num1, &num2);

    // printf("%d %d\n", num1, num2);


    // 2. void 포인터 매개변수 사용하기
    char c1 = 'a';
    char c2 = 'b';
    swapValue(&c1, &c2, TYPE_CHAR);       // 변수의 메모리 주소와 TYPE_CHAR를 넣음
    printf("%c %c\n", c1, c2);            // b a: swapValue에 의해서 값이 서로 바뀜

    int num1 = 10;
    int num2 = 20;
    swapValue(&num1, &num2, TYPE_INT);   // 변수의 메모리 주소와 TYPE_INT를 넣음
    printf("%d %d\n", num1, num2);       // 20 10: swapValue에 의해서 값이 서로 바뀜

    float num3 = 1.234567f;
    float num4 = 7.654321f;
    swapValue(&num3, &num4, TYPE_FLOAT);  // 변수의 메모리 주소와 TYPE_FLOAT를 넣음
    printf("%f %f\n", num3, num4);        // 7.654321f 1.234567: 
                                          // swapValue에 의해서 값이 서로 바뀜

    return 0;
}