#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
/**
* is_digit - checks if a string is a digit
 * @c: character to check
 * Return: 1 if digit, 0 if not
*/
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
/**
* errorAndExit - prints Error and exits.
 * @void: no arguments
 * Return: void
*/
void errorAndExit(void)
{
	char error[] = "Error\n";

	for (int i = 0; error[i] != '\0'; i++)
	{
		_putchar(error[i]);
	}
	exit(98);
}
/**
* multiply - multiplies two numbers
 * @num1: first number
 * @num2: second number
 * Return: 0 on success, 98 on failure
*/
void multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	int lenResult = len1 + len2;
	int *result = malloc(sizeof(int) * lenResult);

	if (!result)
		errorAndExit();

	for (int i = len1; i >= 0; i--)
	{
		for (int j = len2; j >= 0; j--)
		{
			int digit1 = (num1[i] - '0') * (num2[j] - '0');
			int sum = result[i + j + 1] + digit1;

			result[i + j] += sum / 10;
			result[i + j + 1] = sum % 10;
		}
	}

	int startIndex = 0;

	while (startIndex < lenResult && result[startIndex] == 0)
		startIndex++;

	if (startIndex == lenResult)
		_putchar('0');
	else
	{
		for (int i = startIndex; i < lenResult; i++)
			_putchar(result[i] + '0');
	}
	_putchar('\n');
	free(result);
}
/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Description: multiplies two numbers
 * Return: 0 on success, 98 on failure
*/
int main(int argc, int *argv[])
{
	if (argc != 3)
		errorAndExit();

	char *num1 = argv[1];
	char *num2 = argv[2];

	for (int i = 0; num1[i]; i++)
	{
		if (!is_digit(num1[i]))
			errorAndExit();
	}
	for (int i = 0; num2[i]; i++)
	{
		if (!is_digit(num2[i]))
			errorAndExit();
	}
	multiply(num1, num2);
	return (0);
}

