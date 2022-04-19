#include "main.h"

/**
 * convert_b - convert argument to binary
 * and put it in the output
 *
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_b(va_list args, buffer_t *output)
{
	unsigned int d, len = 0;

	d = va_arg(args, unsigned int);

	len += convert_base(d, 2, "01", output);

	return (len);
}

/**
 * convert_o - convert argument to base8
 * and put it in the output
 *
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_o(va_list args, buffer_t *output)
{
	int d;
	unsigned int len = 0;

	d = va_arg(args, unsigned int);
	len += convert_base(d, 8, "01234567", output);
	return (len);
}

/**
 * convert_hex - convert argument to hex
 * and put it in the output
 *
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_hex(va_list args, buffer_t *output)
{
	unsigned int d, len = 0;

	d = va_arg(args, unsigned int);

	len += convert_base(d, 16, "0123456789abcdef", output);

	return (len);
}

/**
 * convert_HEX - convert argument to HEX
 * and put it in the output
 *
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_HEX(va_list args, buffer_t *output)
{
	unsigned int d, len = 0;

	d = va_arg(args, unsigned int);

	len += convert_base(d, 16, "0123456789ABCDEF", output);

	return (len);
}