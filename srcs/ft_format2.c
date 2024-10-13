/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:01:32 by ftapponn          #+#    #+#             */
/*   Updated: 2024/10/13 15:01:33 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_print_pointer(void *ptr)
{
	int				count;
	unsigned long	ptr_adress;

	ptr_adress = (unsigned long)ptr;
	count = 0;
	count += write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "0", 1);
	else
		print_hex_digit(ptr_adress, 0, &count);
	return (count);
}

int	ft_print_char(char c)
{
	write (1, &c, 1);
	return (1);
}

static	void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	char	digit;

	if (n >= 10)
		ft_putnbr_unsigned(n / 10, count);
	digit = (n % 10) + '0';
	*count += write(1, &digit, 1);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	ft_putnbr_unsigned(n, &count);
	return (count);
}
