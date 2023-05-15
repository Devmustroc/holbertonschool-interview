#include "palindrome.h"
/**
 * is_palindrome - checks if a given unsigned integer is a palindrome
 * @n: unsigned long integer to check
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, remainder, original = n;

	while (n != 0)
	{
		/* get the last digit */
		remainder = n % 10;
		/* reverse the number */
		reversed = reversed * 10 + remainder;
		/* remove last digit from n */
		n /= 10;
	}
	/* palindrome if orignal and reversed are equal */
	if (original == reversed)
		return (1);
	/* not a palindrome */
	else
		return (0);
}
