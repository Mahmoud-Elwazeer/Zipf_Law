#include "main.h"

int main()
{
	char *words[MAX_WORDS];
	int word_frequencies[MAX_WORDS];
	int word_count = 0;

	char *sentences[MAX_SENTENCES];
	int sentence_lengths[MAX_SENTENCES];
	int sentence_count = 0;
	char name_file[100];

	printf("please Enter Full Path of File\n");
	printf("(EX: C:\\Users\\elwazeer\\Desktop\\Working\\textfile.txt\nOR textfile.txt if in same folder of executable file): ");
	scanf("%s", name_file);

	read_words(name_file, words, word_frequencies, &word_count, sentences, sentence_lengths, &sentence_count);

	FILE *dest_file;
	FILE *file = fopen(name_file, "r");
	if (file == NULL)
	{
		printf("Unable to open file.\n");
		return 1;
	}

	printf("Word Frequencies:\n");
	print_frequency(words, word_frequencies, word_count);
	printf("\nSentence Frequencies:\n");
	print_frequency(sentences, sentence_lengths, sentence_count);

	// Free memory
	for (int i = 0; i < word_count; i++)
	{
		free(words[i]);
	}
	for (int i = 0; i < sentence_count; i++)
	{
		free(sentences[i]);
	}

	dest_file = fopen("Output.txt", "w");
	if (dest_file == NULL)
	{
		printf("Error opening the Output file.\n");
		fclose(file);
		return 1;
	}

	//	write_data_in_file(dest_file, letterFrequency, wordLengthCount, sentenceLengthCount);
	fclose(file);
	fclose(dest_file);

	return 0;
}
