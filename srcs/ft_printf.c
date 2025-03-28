/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:44:15 by ftapponn          #+#    #+#             */
/*   Updated: 2024/10/13 14:44:16 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int	ft_find_format(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(ap, int));
	else if (c == 's')
		count = ft_print_string(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count = ft_print_digit(va_arg(ap, int));
	else if (c == 'x')
		count = ft_print_hexa(va_arg(ap, unsigned int), 0);
	else if (c == 'X')
		count = ft_print_hexa(va_arg(ap, unsigned int), 1);
	else if (c == 'u')
		count = ft_print_unsigned(va_arg(ap, unsigned int));
	else if (c == 'p')
		count = ft_print_pointer(va_arg(ap, void *));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if (count == -1)
		exit(1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_find_format(format[i], ap);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end (ap);
	return (count);
}

/*
int main()
{
    char *str = "Hello, World!";
    int num = 42;
    void *ptr = str;
    unsigned int hex = 0x1A3F;
    double lf = 3.141592653589793;

    printf("String: %s\n", str);
    printf("Pointer: %p\n", ptr);
    printf("Integer: %d\n", num);
    printf("Hexadecimal: 0x%x\n", hex);
    printf("Long Floating: %lf\n", lf);

    return 0;
}
*/
