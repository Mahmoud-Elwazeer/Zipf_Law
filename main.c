#include "main.h"

int main()
{
	int letterFrequency[26] = {0};

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

	FILE *dest_file;
	FILE *file = fopen(name_file, "r");
	if (file == NULL)
	{
		printf("Unable to open file.\n");
		return 1;
	}
	calculateLetterFrequency(file, letterFrequency);
	fseek(file, 0, SEEK_SET);
	read_words(file, words, word_frequencies, &word_count, sentences, sentence_lengths, &sentence_count);

	print_letters(letterFrequency);
	printf("Word Frequencies:\n");
	print_frequency(words, word_frequencies, word_count);
	printf("\nSentence Frequencies:\n");
	print_frequency(sentences, sentence_lengths, sentence_count);

	

	dest_file = fopen("Output.txt", "w");
	if (dest_file == NULL)
	{
		printf("Error opening the Output file.\n");
		fclose(file);
		return 1;
	}

	write_data_in_file(dest_file, letterFrequency,  words, word_frequencies, word_count, sentences, sentence_lengths, sentence_count);
	
	// Free memory
	free_item(words, word_count);
	free_item(sentences, sentence_count);
	fclose(file);
	fclose(dest_file);

	return 0;
}
