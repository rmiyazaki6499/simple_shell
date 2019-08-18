#include "stringwrapper.h"

/**
 *  * print_number - a function that prints an integer.
 *   * @n: input integer
 *    */
void print_number(int n)
{
	unsigned int m;

	if (n >= 0)
	{
		if (n >= 10)
			print_number(n / 10);
		_putchar (n % 10 + '0');
	}
	else
	{
		_putchar('-');
		m = -n;
		if (m >= 10)
			print_number(m / 10);
		_putchar(m % 10 + '0');
	}
}
