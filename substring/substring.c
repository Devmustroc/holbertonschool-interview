#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * find_substring - finds all the possible substrings containing a list of
 *                  words, within a given string.
 * @s: string to scan
 * @words: array of words all substrings must be a concatenation arrangement of
 *         zero or more of these words
 * @nb_words: number of elements in the array words
 * @n: holds the address at which to store the number of elements in the
 *     returned array.
 * Return:  an allocated array, storing each index in s, at which a substring
 *          was found. If no solution is found, NULL can be returned
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len = strlen(words[0]);
	int s_len = strlen(s);
	int total_len = word_len * nb_words;
	int *indices = NULL;
	int count = 0;

	if (nb_words == 0 || s_len < total_len)
	{
		*n = 0;
		return (NULL);
	}

	for (int i = 0; i <= s_len - total_len; ++i)
	{
		if (is_valid_substring(s, words, nb_words, word_len, i))
		{
			indices = realloc(indices, sizeof(int) * (count + 1));
			indices[count++] = i;
		}
	}

	*n = count;
	return (indices);
}
/**
 * is_valid_substring - checks if a substring is valid
 * @s: string to scan
 * @words: array of words all substrings must be a concatenation arrangement of
 * zero or more of these words
 * @nb_words: number of elements in the array words
 * @word_len: length of each word
 * @start: starting index to check
 * Return: 1 if the substring is valid, 0 otherwise
 */
int is_valid_substring(char const *s, char const **words
		, int nb_words, int word_len, int start)
{
	int *seen = calloc(nb_words, sizeof(int));
	int i, index;

	for (i = 0; i < nb_words; ++i)
	{
		index = start + i * word_len;
		char *substring_word = strndup(s + index, word_len);

		int j;

		for (j = 0; j < nb_words; ++j)
		{
			if (seen[j] == 0 && strcmp(substring_word, words[j]) == 0)
			{
				seen[j] = 1;
				break;
			}
		}

		free(substring_word);
		if (j == nb_words)
		{
			free(seen);
			return (0);
		}
	}

	free(seen);
	return (1);
}
