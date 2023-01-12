#include <stdio.h>

int main()
{
    // 1. 2차원 배열 선언하기
    int numArr[3][4] = {  // 세로 크기 3, 가로 크기 4인 int형 2차원 배열 선언
        { 11, 22, 33, 44 },
        { 55, 66, 77, 88 },
        { 99, 110, 121, 132 }
    };

    // 첫번째는 세로 index, 두번째는 가로 index
    printf("%d\n", numArr[0][0]);
    printf("%d\n", numArr[1][2]);
    printf("%d\n", numArr[2][3]);
    printf("\n");


    // 2. 2차원 배열 초기화하기
    int numArr2[3][4] = { 0, };  // 2차원 배열 요소 모두 0으로 초기화
    printf("%d\n", numArr2[0][0]);
    printf("%d\n", numArr2[1][2]);
    printf("%d\n", numArr2[2][3]);
    printf("\n");


    // 3. 배열 요소에 값 할당하기
    int numArr3[3][4];

    numArr3[0][0] = 11;    // 세로 인덱스 0, 가로 인덱스 0인 요소에 값 할당
    numArr3[0][1] = 22;    // 세로 인덱스 0, 가로 인덱스 1인 요소에 값 할당
    numArr3[0][2] = 33;    // 세로 인덱스 0, 가로 인덱스 2인 요소에 값 할당
    numArr3[0][3] = 44;    // 세로 인덱스 0, 가로 인덱스 3인 요소에 값 할당

    numArr3[1][0] = 55;    // 세로 인덱스 1, 가로 인덱스 0인 요소에 값 할당
    numArr3[1][1] = 66;    // 세로 인덱스 1, 가로 인덱스 1인 요소에 값 할당
    numArr3[1][2] = 77;    // 세로 인덱스 1, 가로 인덱스 2인 요소에 값 할당
    numArr3[1][3] = 88;    // 세로 인덱스 1, 가로 인덱스 3인 요소에 값 할당

    numArr3[2][0] = 99;    // 세로 인덱스 2, 가로 인덱스 0인 요소에 값 할당
    numArr3[2][1] = 110;   // 세로 인덱스 2, 가로 인덱스 1인 요소에 값 할당
    numArr3[2][2] = 121;   // 세로 인덱스 2, 가로 인덱스 2인 요소에 값 할당
    numArr3[2][3] = 132;   // 세로 인덱스 2, 가로 인덱스 3인 요소에 값 할당

    printf("%d\n", numArr3[-1][-1]);    // 인덱스에서 벗어날 경우 쓰레기값 출력
    printf("%d\n", numArr3[0][4]);    // 55 : [0][4] 인덱스 벗어나므로 -> [1][0] 값을 출력
    printf("%d\n", numArr3[5][5]);    // 인덱스에서 벗어날 경우 쓰레기값 출력
    printf("\n");


    // 4. 2차원 배열의 크기 구하기

    //int numArr[3][4] = {  // 세로 크기 3, 가로 크기 4인 int형 2차원 배열 선언
    //    { 11, 22, 33, 44 },
    //    { 55, 66, 77, 88 },
    //    { 99, 110, 121, 132 }
    //};

    printf("%d\n", sizeof(numArr));  // 48 : 4바이트 크기 요소(int)가 12개 이므로

    int col = sizeof(numArr[0]) / sizeof(int);  // 가로의 크기 -> 가로 한 줄의 크기를 요소의 크기로 나눔
    int row = sizeof(numArr) / sizeof(numArr[0]);  // 세로의 크기 -> 전체 크기를 가로 한줄의 크기로 나눔

    printf("%d\n", col);    // 4
    printf("%d\n", row);    // 3
    printf("\n");


    // 5. 반목문으로 2차원 배열의 요소를 모두 출력하기
    // 순서대로 출력
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", numArr[i][j]);
        }
        printf("\n");  // 한 row 출력 뒤 다음 줄로 넘어감
    }
    printf("\n");

    // 역순 출력

    //int row = sizeof(numArr) / sizeof(numArr[0]);
    //int col = sizeof(numArr[0]) / sizeof(int);

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            printf("%d ", numArr[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    // 6. 2차원 배열을 포인터에 넣기
    // int numArr[3][4] = {  // 세로 크기 3, 가로 크기 4인 int형 2차원 배열 선언
    //    { 11, 22, 33, 44 },
    //    { 55, 66, 77, 88 },
    //    { 99, 110, 121, 132 }
    //};

    int (*numPtr)[4] = numArr;

    printf("%p\n", numPtr);  // 2차원 배열의 포인터는 1행(가로 크기 4인 배열)을 가리키는 포인터
    printf("%p\n", numArr);

    printf("%p\n", *numPtr);  // 2차원 배열 포인터를 역참조하면 세로 첫 번째 주솟값이 나옴 -> 배열이 시작하는 주소
    printf("%p\n", *numArr);  // 2차원 배열을 역참조해도 세로 첫 번째 주솟값이 나옴

    printf("%d\n", *numPtr[0]);  // 11
    printf("%d\n", *numPtr[1]);  // 55
    printf("%d\n", *numPtr[2]);  // 99

    // 2차원 배열 포인터는 []를 두 번 사용해 배열의 요소에 접근 가능
    printf("%d\n", numPtr[2][1]);  // 110

    printf("%d\n", sizeof(numPtr));  // 8 : 포인터의 크기


    // 7. 3차원 배열 알아보기
    // [높이] [세로] [가로]
    int numArrThree[2][3][4] = {
        {
            { 11, 22, 33, 44 },
            { 55, 66, 77, 88 },
            { 99, 110, 121, 132 }
        },
        {
            { 111, 122, 133, 144 },
            { 155, 166, 177, 188 },
            { 199, 1110, 1121, 1132 }
        }
    };

    printf("%d\n", numArrThree[0][2][1]);  // 110
    numArrThree[1][2][3] = 0;

    // 깊이 행 렬
    int depth = sizeof(numArrThree) / sizeof(numArrThree[0]);
    int row = sizeof(numArrThree[0]) / sizeof(numArrThree[0][0]);
    int col = sizeof(numArrThree[0][0]) / sizeof(int);

    // 포인터
    // 자료형 (*포인터이름)[세로크기=row][가로크기=col]
    int(*numThreePtr)[3][4] = numArrThree;

    return 0;
}