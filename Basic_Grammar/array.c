#include <stdio.h>

int array()
{
    // 1. 배열 선언하고 요소 접근하기
    int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

    printf("%d\n", numArr[0]);
    printf("%d\n", numArr[5]);
    printf("%d\n", numArr[9]);
    printf("\n");

    // 2. 배열 초기화하기
    int numArr2[10] = { 0, }; // 배열의 요소를 모두 0으로 초기화

    printf("%d\n", numArr2[0]);  // : 0
    printf("%d\n", numArr2[5]);
    printf("%d\n", numArr2[9]);

    int numArr3[10] = { 6, 6,  }; // 배열의 0과 1 인덱스를 6으로, 나머지 요소를 0으로 초기화
    printf("%d\n", numArr3[0]);  // : 6
    printf("%d\n", numArr3[1]);  // : 6
    printf("%d\n", numArr3[5]);
    printf("%d\n", numArr3[9]);
    printf("\n");

    // 3. 배열의 요소에 값 할당하기
    int numArrTen[10];

    numArrTen[0] = 11;
    numArrTen[1] = 11;
    numArrTen[2] = 11;

    printf("%d\n", numArrTen[1]);
    // 다음의 경우 컴파일 에러는 발생하지 않음. But 쓰레기 값이 출력.
    // 배열의 범위를 벗어난 인덱스에 접근하면 배열이 아닌 다른 메모리 공간에 접근하게 됨.
    printf("%d\n", numArrTen[5]);  // 할당되지 않은 요소
    printf("%d\n", numArrTen[-2]);  // 음수이므로 잘못된 인덱스
    printf("%d\n", numArrTen[20]);  // 배열의 범위를 벗어난 인덱스
    printf("\n");

    // 4. 배열의 크기 구하기
    int numArrSize[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

    printf("%d\n", sizeof(numArrSize));  // 40 : 4바이트 크기의 요소가 10개이므로
    printf("%d\n", sizeof(numArrSize) / sizeof(int));  // 10: 배열의 크기 -> 전체 공간을 각 요소의 크기로 나눠줌
    printf("%d\n", sizeof(numArrSize) / sizeof(numArrSize[0]));  // 요소를 직접 가져와도 됨
    printf("\n");

    // 5. 배열의 요소 출력하기
    int numArrIter[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

    for (int i = 0; i < sizeof(numArrIter) / sizeof(int); i++)
    {
        printf("%d\n", numArrIter[i]);
    }

    // C 언어는 index 유효성 여부를 검사하지 않으므로, 꼭 고려해 작성!
    int numArrIterReverse[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

    for (int i = sizeof(numArrIterReverse) / sizeof(int) - 1; i >= 0; i--)
    {
        printf("%d\n", numArrIterReverse[i]);
    }
    printf("\n");


    // 8. 배열을 포인터에 넣기
    // int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

    int* numPtr = numArr;

    // 배열은 첫 번째 요소의 주솟값만 담고 있음
    printf("%d\n", *numPtr);  // 11 : 배열의 주소가 들어있는 포인터를 역참조하면 배열의 첫 번째 요소 접근

    printf("%d\n", *numArr);  // 11 : 배열 자체를 역참조해도 배열의 첫 번째 요소 접근

    printf("%d\n", numPtr[5]);  // 66 : 배열의 주소가 들어있는 포인터는 인덱스로 접근 가능

    printf("%d\n", sizeof(numArr));  // 40 : 배열이 메모리에 차지하는 전체 공간

    printf("%d\n", sizeof(numPtr));  // 8 : 배열의 주소가 들어 있는 포인터의 크기 -> 포인터의 크기(8바이트)
    printf("\n");

    // 9. 배열로 10진수를 2진수로 변환하기

    int decimal = 13;
    int binary[20] = { 0, };

    int position = 0;
    while (decimal > 0)
    {
        binary[position] = decimal % 2;
        decimal = decimal / 2;
        position++;
    }

    for (int i = position - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    printf("\n");


    return 0;
}