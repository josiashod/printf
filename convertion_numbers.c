#include "main.h"


/**
 * long_short - long_short
 * @args: zero flag
 * @len: unsigned char
 * Return: long int
 */
long int long_short(va_list args, unsigned char len)
{
	if (len == LONG)
		return (va_arg(args, long int));
	else
		return (va_arg(args, int));
}

/**
 * convert_d - Converts an argument to a signed int and
 *              stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_d(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	long int d = 0, copy;
	unsigned int ret = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';

	d = long_short(args, len);

	/* Handle space flag */
	if (SPACE_FLAG == 1 && d >= 0)
		ret += _memcpy(output, &space, 1);

	if (prec <= 0 && NEG_FLAG == 0) /* Handle width  */
	{
		if (d == LONG_MIN)
			count += 19;
		else
		{
			for (copy = (d < 0) ? -d : d; copy > 0; copy /= 10)
				count++;
		}
		count += (d == 0) ? 1 : 0;
		count += (d < 0) ? 1 : 0;
		count += (PLUS_FLAG == 1 && d >= 0) ? 1 : 0;
		count += (SPACE_FLAG == 1 && d >= 0) ? 1 : 0;

		/* Handle plus flag when zero flag is active */
		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && d >= 0)
			ret += _memcpy(output, &plus, 1);
		/*Print negative sign when zero flag is active */
		if (ZERO_FLAG == 1 && d < 0)
			ret += _memcpy(output, &neg, 1);

		pad = (ZERO_FLAG == 1) ? '0' : ' ';
		for (wid -= count; wid > 0; wid--)
			ret += _memcpy(output, &pad, 1);
	}

	/* Print negative sign when zero flag is not active */
	if (ZERO_FLAG == 0 && d < 0)
		ret += _memcpy(output, &neg, 1);
	/* Handle plus flag when zero flag is not active */
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && d >= 0))
		ret += _memcpy(output, &plus, 1);

	if (!(d == 0 && prec == 0))
		ret += convert_signed_in_base(output, d, "0123456789",
				flags, 0, prec);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_b - Converts an unsigned int argument to binary
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_b(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)len;

	return (convert_unsigned_in_base(output, num, "01", flags, wid, prec));
}

/**
 * convert_o - Converts an unsigned int to octal and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list poinitng to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_o(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, &zero, 1);

	if (!(num == 0 && prec == 0))
		ret += convert_unsigned_in_base(output, num, "01234567",
				flags, wid, prec);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
