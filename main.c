#include "main.h"

int main()
{
    char name_file[100];
    printf("please Enter Full Path of File\n");
    printf("(EX: C:\\Users\\elwazeer\\Desktop\\Working\\textfile.txt\nOR textfile.txt if in same folder of executable file): ");
    scanf("%s", name_file);

    FILE *dest_file;
    FILE *file = fopen(name_file, "r");
    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    int letterFrequency[26] = {0};
    int wordLengthCount[MAX_WORD_LENGTH + 1] = {0};
    int sentenceLengthCount[MAX_SENTENCE_LENGTH + 1] = {0};

    calculateLetterFrequency(file, letterFrequency);
    fseek(file, 0, SEEK_SET);
    calculateWordLengths(file, wordLengthCount);
    fseek(file, 0, SEEK_SET);
    calculateSentenceLengths(file, sentenceLengthCount);

    // displayResults(letterFrequency, wordLengthCount, sentenceLengthCount);

    dest_file = fopen("Output.txt", "w");
    if (dest_file == NULL)
    {
        printf("Error opening the Output file.\n");
        fclose(file);
        return 1;
    }
    write_data_in_file(dest_file, letterFrequency, wordLengthCount, sentenceLengthCount);
    fclose(file);
    fclose(dest_file);

    return 0;
}
