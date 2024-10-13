/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:09:22 by ftapponn          #+#    #+#             */
/*   Updated: 2024/10/13 15:09:23 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_digit(int nb)
{
	char	*result;
	int		i;

	result = ft_itoa(nb);
	if (!result)
		return (-1);
	i = 0;
	while (result[i])
	{
		write(1, &result[i], 1);
		i++;
	}
	free(result);
	return (i);
}

void	print_hex_digit(unsigned long nb, int uppercase, int *count)
{
	static char	*hexa_low = "0123456789abcdef";
	static char	*hexa_up = "0123456789ABCDEF";

	if (nb >= 16)
		print_hex_digit(nb / 16, uppercase, count);
	if (uppercase)
		write(1, &hexa_up[nb % 16], 1);
	else
		write(1, &hexa_low[nb % 16], 1);
	(*count)++;
}

int	ft_print_hexa(unsigned int nb, int uppercase)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	print_hex_digit(nb, uppercase, &count);
	return (count);
}
