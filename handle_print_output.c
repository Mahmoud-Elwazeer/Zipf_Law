#include "main.h"

/**
 * print_letters - print letter frequency
 *
 * @frequency: frequencies of letters
 * Return: void
 */
void print_letters(int frequency[])
{
    int i;
    printf("Letter Frequency:\n");
    for (i = 0; i < 26; i++)
    {
        printf("%c: %d\n", 'a' + i, frequency[i]);
    }
}

/**
 * print_frequency - print word or sentence frequency
 *
 * @items: word or sentences
 * @frequencies: frequencies
 * @count: count
 * Return: void
 */
void print_frequency(char *items[], int frequencies[], int count)
{
    printf("Item\tFrequency\n");
    printf("-----------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s\t%d\n", items[i], frequencies[i]);
    }
}
