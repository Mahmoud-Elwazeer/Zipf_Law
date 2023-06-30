#include "main.h"

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
    sentences[*count] = strdup(sentence);
    sentence_lengths[*count] = strlen(sentence);
    (*count)++;
}