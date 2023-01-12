#include <stdio.h>
#include <math.h>

int convert_binary()
{
    int decimal = 0;
    int binary[4] = { 1, 1, 0, 1 };
    
    int position = 0;
    for (int i = sizeof(binary) / sizeof(int) - 1; i >= 0; i--)
    /*
    {
        decimal += binary[i] * (int)pow((double)2, (double)3 - i);
    }

    */

    {
        if (binary[i] == 1)
        {
            decimal += 1 << position;
        }

        position++;
    }

    printf("%d\n", decimal);

    return 0;
}