#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * struct buffer - A new buffer type
 * @start: - pointer to the head of the pointer
 * @buffer: - pointer to an array of char
 * @len: - size of the buffer
 */
typedef struct buffer
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

/**
 * struct format - A new type defining a format struct.
 * @specifier: A character representing a conversion specifier.
 * @func: A pointer to a conversion function corresponding to specifier.
 */
typedef struct format
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_t *);
} format_t;

int _printf(const char *format, ...);

/* CONVERTER FUNCTIONS */
unsigned int convert_c(va_list args, buffer_t *output);
unsigned int convert_s(va_list args, buffer_t *output);
unsigned int convert_d(va_list args, buffer_t *output);
unsigned int c_percent(va_list args, buffer_t *output);
unsigned int convert_b(va_list args, buffer_t *output);

/* HELPERS FUNCTION */
buffer_t *init_buffer(void);
void free_buffer(buffer_t *buffer);
unsigned int _memcpy(buffer_t *dest, const char *src, unsigned int n);

/* HANDLERS */
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *);

#endif /* MAIN_H */
