#include "main.h"

/**
 * handle_specifiers - function that handle printf specifiers
 * @specifier: the conversion's specifier
 *
 * Return: a conversion function is good else NULL
 */
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *)
{
	format_t formater[] = {
		{'c', convert_c},
		{'s', convert_s},
		{'d', convert_d},
		{'i', convert_d},
		{'u', convert_u},
		{'b', convert_b},
		{'o', convert_o},
		{'p', convert_p},
		{'r', convert_r},
		{'R', convert_R},
		{'x', convert_hex},
		{'X', convert_HEX},
		{'%', c_percent},
		{0, NULL}
	};
	int i = 0;

	while (formater[i].func)
	{
		if (formater[i].specifier == *specifier)
			return (formater[i].func);
		i++;
	}
	return (NULL);
}
