#include "main.h"
#include <stdlib.h>

int get_word_count(char *str);
char *copy_word(char *, int, int);

/**
 * get_word_count - look for words
 * @str: array of string
 * Return: word count
 */
int get_word_count(char *str)
{
	int i;
	int count = 0;
	int is_word = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			is_word = 0;
		}
		else if (is_word == 0)
		{
			count++;
			is_word = 1;
		}
	}
	return (count);
}

/**
 * copy_word - copies the words
 * @start_index: starting index of the word
 * @word_lenght: average length of the word
 * Return: pointer
 */
char *copy_word(char *str, int start_index, int word_length)
{
	char *word;
	int i;

	word = malloc((word_length + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	for (i = 0; i < word_length; i++)
	{
		word[i] = str[start_index + 1];
	}
	word[word_length] = '\0';
	return (word);
}
/**
 * strtow - splits a string into words
 * @str: string
 * Return: pointer or NULL
 */
char **strtow(char *str)
{
	char **words;
	int curr_word = 0;
	int len = 0;
	int is_word = 0;
	int i, j;
	int count = get_word_count(str);

	if (str == NULL || *str == '\0')
		return (NULL);
	words = malloc((count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			is_word = 0;
		}
		else if (is_word == 0)
		{
			len = 1;
			while (str[i + len] != ' ' && str[i + len] != '\0')
				len++;
			words[curr_word] = copy_word(str, i, len);
			if (words[curr_word] == NULL)
			{
				for (j = 0; j < curr_word; j++)
					free(words[j]);
				free(words);
				return (NULL);
			}
			curr_word++;
			is_word = 1;
		}
	}
	words[count] = NULL;
	return (words);
}
