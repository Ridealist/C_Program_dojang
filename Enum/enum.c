#include <stdio.h>

/*
enum 열거형이름 {
    값1 = 초깃값,
    값2,
    값3
};
*/
// enum DayOfWeek {    // 열거형 정의
//     Sunday = 0,         // 초깃값 할당 -> 선택, default로 0부터 시작
//     Monday,  // 아랫값 자동으로 1씩 증가하며 값 할당
//     Tuesday,
//     Wednesday,
//     Thursday,
//     Friday,
//     Saturday = 100
// };

enum LuxSkill {
    LightBinding = 1,
    PrismaticBarrier,
    LucentSingularity,
    FinalSpark
};

typedef enum _DayOfWeek {
    Sunday = 0,                  // 초깃값을 0으로 할당
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    DayOfWeekCount               // 열거형 값의 개수를 나타내는 항목 추가
} DayOfWeek;                 // typedef를 사용하여 열거형 별칭을 DayOfWeek로 정의


int main()
{
    // 1. 열거형 기본 개념
    enum _DayOfWeek week;    // 열거형 변수 선언

    week = Saturday;    // 열거형 값 할당
    // week = 100; 도 가능. but, 정의하지 않은 열거형 값은 불가

    printf("%d\n", week);   // 2: Tuesday의 값 출력
    printf("%d\n", week);   // 100: Saturday의 값 출력

    printf("%zd\n", sizeof(week));  // 크기 4 -> 일종의 공용체??


    // 2. 열거형을 switch에 활용
    /*
    switch (열거형 변수)
    {
        case 열거형값:
            실행할코드;
            break;
    }
    */
    enum LuxSkill skill;

    skill = FinalSpark;

    switch (skill)
    {
    case LightBinding:         // 열거형 값이 LightBinding일 때
        printf("LightBinding\n");
        break;
    case PrismaticBarrier:     // 열거형 값이 PrismaticBarrier일 때
        printf("PrismaticBarrier\n");
        break;
    case LucentSingularity:    // 열거형 값이 LucentSingularity일 때
        printf("LucentSingularity\n");
        break;
    case FinalSpark:           // 열거형 값이 FinalSpark일 때
        printf("FinalSpark\n");
        break;
    default:
        break;
    }
    // 열거형을 사용하여 숫자 대신 '스킬 이름'으로 처리 가능
    // 프로그램은 1, 2, 3, 4로 처리하고 사람은 LightBinding, PrismaticBarrier, LucentSingularity, FinalSpark를 보고 사용하는 식


    // 3. 열거형을 for에 활용하기

    // 초깃값은 Sunday, 정의된 DayOfWeekCount 활용 for loop 종단점 설정
    for (DayOfWeek i = Sunday; i < DayOfWeekCount; i++)
    {
        printf("%d\n", i);
    }


    return 0;
}