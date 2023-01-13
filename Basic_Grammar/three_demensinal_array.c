#include <stdio.h>
#include <stdlib.h>

int make_three_di_array()
{
    long long*** m = malloc(sizeof(long long**) * 2);

    for (int depth = 0; depth < 2; depth++)
    {
        m[depth] = malloc(sizeof(long long*) * 3);

        for (int row = 0; row < 3; row++)
        {
            m[depth][row] = malloc(sizeof(long long) * 5);
        }
    }

    m[1][2][4] = 100;

    printf("%lld\n", m[1][2][4]);

    for (int depth = 0; depth < 2; depth++)
    {
        for (int row = 0; row < 3; row++)
        {
            free(m[depth][row]);
        }
        free(m[depth]);
    }

    /*
    메모리를 해제할 때는 메모리 할당과 반대 순서로
    
    메모리를 할당할 때 면 → 세로 → 가로 순서
    해제할 때는 반대로 가로 → 세로 → 면 순서
    
    */

    free(m);

    return 0;
}