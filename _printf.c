#include "main.h"

/**
 * _write - write to stdout
 * @output: the string to write
 */
void _write(buffer_t *output)
{
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * _printf - produces output according to a format.
 * @format: is a character string.
 * Return: the length of the format.
 */
int _printf(const char *format, ...)
{
	unsigned int len = 0, i = 0;
	unsigned int (*convert)(va_list, buffer_t *);
	buffer_t *output;
	va_list args;

	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			convert = handle_specifiers((format + i + 1));
			if (convert != NULL)
			{
				len += convert(args, output);
				format += 2;
				continue;
			}
			else
			{
				len--;
				break;
			}
		}
		len += _memcpy(output, (format + i), 1);
		i++;
	}

	_write(output);
	va_end(args);

	return (len);
}
