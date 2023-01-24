#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

long long getSum(char *types, ...) {

    long long sum = 0;
    va_list ap;

    va_start(ap, types);
    int i = 0;
    while (types[i] != '\0') {
        switch (types[i])
        {
        case 's':
            sum += atoll(va_arg(ap, char*));
            break;
        case 'i':
            sum += (va_arg(ap, int));
            break;
        default:
            break;
        }
        i++;
    }
    va_end(ap);

    return sum;
}

int main() {
    printf("%lld\n", getSum("siis", "12", 30000, 500000, "300"));
    printf("%lld\n", getSum("ssi", "150", "150", 100));

    return 0;
}