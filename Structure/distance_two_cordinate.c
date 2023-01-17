#include <stdio.h>
#include <math.h>    // sqrt, pow 함수가 선언된 헤더 파일

typedef struct _Point2D {
    int x;
    int y;
} Point2D;

int main()
{
    Point2D p1 = { 30, 20 };
    Point2D p2 = { 60, 50 };

    // double sqrt(double_X) -> 제곱근을 반환, _X가 음수이면 NaN을 반환
    // double pow(double_X, double_Y) ->  _X의 _Y 거듭제곱을 반환
    double dist = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

    printf("p1: %d %d\n", p1.x, p1.y);
    printf("p2: %d %d\n", p2.x, p2.y);

    printf("Distance of p1 and p2 : %f\n", dist);

    /*
    기타 절댓값('abs'olute value) 함수들

    abs(정수);
        int abs(int _X);
        정수 절댓값을 반환
    fabs(double형 실수);
        double fabs(double _X);
        double형 실수 절댓값을 반환
    fabsf(float형 실수);
        float fabsf(float _X);
        float형 실수 절댓값을 반환

   ▼ C언어 abs 함수
    헤더파일 : <stdlib.h>
    함수원형 : int abs(int num);
    함수설명 : 인자로 들어온 int 타입의 num의 절대값을 반환하는 함수

    ▼ C언어 fabs 함수
    헤더파일 : <math.h>
    함수원형 : double fabs(double num);
    함수설명 : 인자로 들어온 double 타입의 num의 절대값을 반환하는 함수

    위에서 보시는것처럼 abs 함수는 stdlib.h에 존재하고, fabs 함수는 math.h에 존재합니다.
   
   */

    return 0;
}