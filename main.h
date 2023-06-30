#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 500
#define MAX_WORD 2000

void calculateLetterFrequency(FILE *file, int *frequency);
void calculateWordLengths(FILE *file, int *lengthCount);
void calculateSentenceLengths(FILE *file, int *lengthCount);

void displayResults(const int *frequency, const int *wordLengthCount, const int *sentenceLengthCount);
void write_data_in_file(FILE *file, const int *frequency, const int *wordLengthCount, const int *sentenceLengthCount);

char **split_string(char *str, char *delim);

#endif
