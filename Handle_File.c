#include "main.h"

// write output in new file
/**
 * write_data_in_file: store output in file
 *
 * @file: name output file
 * @frequency: Letter Frequency
 * @frequency: Word Lengths
 * @sentenceLengthCount: Sentence Lengths
 * Return: void
 */
void write_data_in_file(FILE *file, const int *frequency, const int *wordLengthCount, const int *sentenceLengthCount)
{
    fprintf(file, "Letter Frequency:\n");
    for (int i = 0; i < 26; i++)
    {
        fprintf(file, "%c: %d\n", 'a' + i, frequency[i]);
    }

    fprintf(file, "\nWord Lengths:\n");
    for (int i = 1; i <= MAX_WORD_LENGTH; i++)
    {
        if (wordLengthCount[i] == 0)
            continue;
        fprintf(file, "Word lenght %d: %d\n", i, wordLengthCount[i]);
    }

    fprintf(file, "\nSentence Lengths:\n");
    for (int i = 1; i <= MAX_SENTENCE_LENGTH; i++)
    {
        if (sentenceLengthCount[i] == 0)
            continue;
        fprintf(file, "Sentence Length %d: %d\n", i, sentenceLengthCount[i]);
    }
}