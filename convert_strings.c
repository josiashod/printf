#include "main.h"

/**
 * convert_c - convert argument to a char
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_c(va_list args, buffer_t *output)
{
	char c;
	unsigned int len = 0;

	c = va_arg(args, int);

	len += _memcpy(output, &c, 1);

	return (len);
}

/**
 * convert_s - convert argument to a string
 * and put it in the output
 *
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_s(va_list args, buffer_t *output)
{
	char *str, *null = "(null)";
	unsigned int len = 0;
	int i = 0;

	str = va_arg(args, char *);

	if (str == NULL)
		return (_memcpy(output, null, 6));

	while (str[i])
	{
		len += _memcpy(output, str + i, 1);
		i++;
	}
	return (len);
}

/**
 * c_percent - convert percent argument
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int c_percent(va_list args __attribute__((unused)), buffer_t *output)
{
	char c = '%';
	unsigned int len = 0;

	len += _memcpy(output, &c, 1);

	return (len);
}