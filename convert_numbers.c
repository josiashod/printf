#include "main.h"

/**
 * convert_d - convert argument to a integer
 * and put it in the output
 *
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_d(va_list args, buffer_t *output)
{
	int d;
	unsigned int len = 0;
	char minus = '-';

	d = va_arg(args, int);

	if (d == 0)
	{
		len += _memcpy(output, "0", 1);
		return (len);
	}

	if (d < 0)
	{
		len += _memcpy(output, &minus, 1);
		d = -d;
	}
	len += convert_base(d, 10, "0123456789", output);
	return (len);
}

/**
 * convert_u - convert argument to a unsigned integer
 * and put it in the output
 *
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_u(va_list args, buffer_t *output)
{
	int d;
	unsigned int len = 0;

	d = va_arg(args, unsigned int);

	if (d == 0)
	{
		len += _memcpy(output, "0", 1);
		return (len);
	}

	len += convert_base(d, 10, "0123456789", output);
	return (len);
}
