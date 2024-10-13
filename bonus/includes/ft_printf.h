/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:05:40 by ftapponn          #+#    #+#             */
/*   Updated: 2024/10/13 16:26:05 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	print_hex_digit(unsigned long nb, int uppercase, int *count);
int		ft_printf(const char *format, ...);
int		ft_print_string(char *str);
int		ft_print_digit(int nb);
int		ft_print_hexa(unsigned int nb, int uppercase);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_pointer(void *ptr);
int		ft_print_char(char nb);
int		ft_print_binary(int nb);
int		ft_print_octal(int nb);
int		ft_print_float(float nb);

#endif
