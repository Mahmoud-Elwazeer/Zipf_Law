#include "main.h"

/**
 * calculateLetterFrequency - Function to calculate the frequency of letters
 *
 * @file: read from file
 * @frequency: store data work as return value
 * Return: void
 */
void calculateLetterFrequency(FILE *file, int *frequency)
{
    int c;
    while ((c = fgetc(file)) != EOF)
    {
        if (isalpha(c))
        {
            c = tolower(c);
            frequency[c - 'a']++;
        }
    }
}

void insert_word(const char *word, char *words[], int frequencies[], int *count)
{
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(words[i], word) == 0)
        {
            frequencies[i]++;
            return;
        }
    }

    words[*count] = strdup(word);
    frequencies[*count] = 1;
    (*count)++;
}

void insert_sentence(const char *sentence, char *sentences[], int sentence_lengths[], int *count)
{
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(sentences[i], sentence) == 0)
        {
            sentence_lengths[i]++;
            return;
        }
    }

    sentences[*count] = strdup(sentence);
    sentence_lengths[*count] = 1;
    (*count)++;
}