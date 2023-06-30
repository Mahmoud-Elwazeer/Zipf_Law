#include "main.h"

void print_frequency(char *items[], int frequencies[], int count)
{
    printf("Item\tFrequency\n");
    printf("-----------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s\t%d\n", items[i], frequencies[i]);
    }
}