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

/**
 * calculateWordLengths - Function to calculate the length of words
 *
 * @file: read from file
 * @lengthCount: store data work as return value
 * Return: void
 */
void calculateWordLengths(FILE *file, int *lengthCount)
{
    int c;
    int length = 0;
    while ((c = fgetc(file)) != EOF)
    {
        printf("%c\n", c);
        if (isalpha(c))
        {
            length++;
        }
        else if (length > 0)
        {
            if (length <= MAX_WORD_LENGTH)
            {
                lengthCount[length]++;
            }
            length = 0;
        }
    }
}

/**
 * calculateWordLengths - Function to calculate the length of sentences
 *
 * @file: read from file
 * @lengthCount: store data work as return value
 * Return: void
 */
void calculateSentenceLengths(FILE *file, int *lengthCount)
{
    int c;
    int length = 0;
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            if (length > 0)
            {
                if (length <= MAX_SENTENCE_LENGTH)
                {
                    lengthCount[length]++;
                }
                length = 0;
            }
        }
        else if (isalpha(c))
        {
            length++;
        }
    }
}

/**
 * displayResults - display the results
 *
 * @frequency: Letter Frequency
 * @frequency: Word Lengths
 * @sentenceLengthCount: Sentence Lengths
 * Return: void
 */

void displayResults(const int *frequency, const int *wordLengthCount, const int *sentenceLengthCount)
{
    printf("Letter Frequency:\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%c: %d\n", 'a' + i, frequency[i]);
    }

    printf("\nWord Lengths:\n");
    for (int i = 1; i <= MAX_WORD_LENGTH; i++)
    {
        if (wordLengthCount[i] == 0)
            continue;
        printf("Word lenght %d: %d\n", i, wordLengthCount[i]);
    }

    printf("\nSentence Lengths:\n");
    for (int i = 1; i <= MAX_SENTENCE_LENGTH; i++)
    {
        if (sentenceLengthCount[i] == 0)
            continue;
        printf("Sentence Length %d: %d\n", i, sentenceLengthCount[i]);
    }
}