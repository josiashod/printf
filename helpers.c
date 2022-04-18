#include "main.h"

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
		(dest->buffer)++;
		dest->len++;
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
