#include <stdio.h>
#include <stdlib.h>

/**
 * errorAndExit - prints Error and exits with status 98
 */
void errorAndExit(void)
{
	char error[] = "Error\n";

	for (int i = 0; error[i]; i++)
        _putchar(error[i]);
	exit(98);
}

/**
 * isDigit - checks if a char is a digit
 * @c: char to check
 * Return: 1 if c is a digit, 0 otherwise
 */
int isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * multiply - multiplies two numbers
 * @num1: first number to multiply
 * @num2: second number to multiply
 * Return: 0 if success, 1 otherwise
 */
void multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	int lenResult = len1 + len2;
	int *result = calloc(lenResult, sizeof(int));

	if (!result)
		errorAndExit();
	for (int i = len1 - 1; i >= 0; i--)
	{
		for (int j = len2 - 1; j >= 0; j--)
		{
			int mul = (num1[i] - '0') * (num2[j] - '0');
			int sum = mul + result[i + j + 1];

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
 * @argc: number of arguments passed
 * @argv: array of pointers to arguments
 * Return: 0 if success, 1 otherwise
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
		errorAndExit();

	char *num1 = argv[1];
	char *num2 = argv[2];

	for (int i = 0; num1[i]; i++)
	{
		if (!isDigit(num1[i]))
			errorAndExit();
	}

	for (int i = 0; num2[i]; i++)
	{
		if (!isDigit(num2[i]))
			errorAndExit();
	}
	multiply(num1, num2);
	return (0);
}
