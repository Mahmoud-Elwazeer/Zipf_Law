#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 500
#define MAX_WORDS 1000
#define MAX_SENTENCES 1000

void calculateLetterFrequency(FILE *file, int *frequency);
void print_letters(int frequency[]);

void insert_word(const char *word, char *words[], int frequencies[], int *count);
void insert_sentence(const char *sentence, char *sentences[], int sentence_lengths[], int *count);

void print_frequency(char *items[], int frequencies[], int count);

void write_data_in_file(FILE *file, const int *frequency, const int *wordLengthCount, const int *sentenceLengthCount);
void read_words(FILE *file, char *words[], int words_freq[], int *words_count, char *sentences[], int sentences_freq[], int *sentences_count);

void free_item(char *items[], int count);

#endif
