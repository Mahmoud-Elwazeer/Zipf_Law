#include "main.h"

/**
 * read_words - read each word in file
 * @file: input file
 * @word: store words
 * @frequency: store frequency of word
 * Return: void
 */
void read_words(FILE *file, char *words[], int words_freq[], int *words_count, char *sentences[], int sentences_freq[], int *sentences_count)
{
    char line[256];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        // get whole sentence and sentence_freq
        char *sentence_token = strtok(line, ".!?");
        while (sentence_token != NULL)
        {
            insert_sentence(sentence_token, sentences, sentences_freq, sentences_count);
            sentence_token = strtok(NULL, ".!?");
        }

        // get each word depend on space or new line
        // cal word_freq
        char *word_token = strtok(line, " \t\n");
        while (word_token != NULL)
        {
            insert_word(word_token, words, words_freq, words_count);
            word_token = strtok(NULL, " \t\n");
        }
    }
}

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
