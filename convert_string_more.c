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
 * convert_r - handle reverse spec
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

/**
 * convert_R - handle rot13 spec
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_R(va_list args, buffer_t *output)
{
	char *str, *null = "(null)";
	char alpha[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
			  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
			  'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a',
			  'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
			  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
			  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
	}, key[52] = {'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
		      'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
		      'H', 'I', 'J', 'K', 'L', 'M', 'n', 'o', 'p', 'q',
		      'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a',
		      'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
		      'l', 'm'
	};
	unsigned int len = 0, i = 0, j;

	str = va_arg(args, char *);

	if (str == NULL || !str)
		return (_memcpy(output, null, 6));
	while (str[i])
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == alpha[j])
			{
				len += _memcpy(output, key + j, 1);
				break;
			}
			else if (j == 51)
				len += _memcpy(output, str + i, 1);
		}
		i++;
	}
	return (len);
}
