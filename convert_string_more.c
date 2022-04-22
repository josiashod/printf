#include "main.h"

/**
 * _memcpy_rev - copies memory area in reverse.
 * @s: the string to print.
 * @output: the buffer
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int _memcpy_rev(char *s,  buffer_t *output)
{
	unsigned int len = 0;

	if (*s)
	{
		len += _memcpy_rev(s + 1, output);
		len += _memcpy(output, s, 1);
	}

	return (len);
}

/**
 * convert_r - convert argument to an adress => in progress
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_r(va_list args, buffer_t *output)
{
	char *str, *null = "(null)";

	str = va_arg(args, char *);

	if (str == NULL || !str)
		return (_memcpy(output, null, 6));

	return (_memcpy_rev(str, output));
}
