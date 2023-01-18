#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[30];
    int age;
};

int main()
{
    struct Person *p[5];

    for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
    {
        p[i] = malloc(sizeof(struct Person));
    }

    // string -> 변수 명, char -> &변수(변수의 주소!)
    scanf("%s %d %s %d %s %d %s %d %s %d", 
    p[0]->name, &(p[0]->age), p[1]->name, &(p[1]->age), p[2]->name, &(p[2]->age), p[3]->name, &(p[3]->age), p[4]->name, &(p[4]->age));

    int idx = 0;

    for (int i = 1; i < sizeof(p) / sizeof(struct Person *); i++)
    {
        if (p[i]->age > p[idx]->age)
            idx = i;
    }

    printf("%s\n", p[idx]->name);

    for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
    {
        // printf("%s %d\n", p[i]->name, p[i]->age);
        free(p[i]);
    }

    return 0;
}