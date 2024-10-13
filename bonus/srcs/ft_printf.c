/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:09:46 by ftapponn          #+#    #+#             */
/*   Updated: 2024/10/13 17:50:31 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int	ft_find_bonus_format(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'b')
		count = ft_print_binary(va_arg(ap, int));
	else if (c == 'o')
		count = ft_print_octal(va_arg(ap, int));
	else if (c == 'f')
		count = ft_print_float(va_arg(ap, double));
	return (count);
}

int	ft_find_format(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 's')
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
	count = ft_find_bonus_format(c, ap);
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
	va_end(ap);
	return (count);
}

/*
int	main(void)
{
	int	i, j;
	ft_printf(" en float  j'ai%f", 45.548855);
	ft_printf(" in binary i have i have %b", 545);
	ft_printf(" in octal i have %o 54");
}
*/
