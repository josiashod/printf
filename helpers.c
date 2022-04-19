#include "main.h"

/**
 * convert_base - convert a number to a specified base
 * @number: number to convert
 * @base: the destination base
 * @representation: the destinated base representation
 * @output: the buffer
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_base(unsigned int number, int base,
	char *representation, buffer_t *output)
{
	unsigned int len = 0;

	if (number != 0)
	{
		len += convert_base(number / base, base, representation, output);
		len += _memcpy(output, (representation + (number % base)), 1);
	}
	return (len);
}

/**
 * _memcpy - copies memory area.
 * @dest: destination
 * @src: source
 * @n: number of bytes.
 *
 * Return: a pointer to dest.
 */
unsigned int _memcpy(buffer_t *dest, const char *src, unsigned int n)
{
	unsigned int i = 0;

	for (; i < n; i++)
	{
		*(dest->buffer) = src[i];
		dest->len++;

		if (dest->len == BUFFER_SIZE)
		{
			write(1, dest->start, dest->len);
			dest->buffer = dest->start;
			dest->len = 0;
		}
		else
			(dest->buffer)++;

	}

	return (n);
}

/**
 * free_buffer - Frees a buffer
 * @buffer: the buffer
 */
void free_buffer(buffer_t *buffer)
{
	free(buffer->start);
	free(buffer);
}

/**
 * init_buffer - Init a variable of type buffer_t
 *
 * Return: pointer to the created buffer
 */
buffer_t *init_buffer(void)
{
	buffer_t *output;

	output = malloc(sizeof(buffer_t));
	if (output == NULL)
		return (NULL);

	output->buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (output->buffer == NULL)
	{
		free(output);
		return (NULL);
	}

	output->start = output->buffer;
	output->len = 0;

	return (output);
}
