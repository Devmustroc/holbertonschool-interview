#include "regex.h"
/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: string to scan
 * @pattern: regular expression
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	if (!*str)
	{
		if (!*pattern)
			return (1);
		if (*(pattern + 1) == '*')
			return (regex_match(str, pattern + 2));
		return (0);
	}
	if (*(pattern + 1) == '*')
	{
		if (*pattern == '.' || *str == *pattern)
			return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
		return (regex_match(str, pattern + 2));
	}
	if (*pattern == '.' || *pattern == *str)
		return (regex_match(str + 1, pattern + 1));
	return (0);
}
