#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_string(char *str);
int	ft_print_digit(int nb);
int	ft_print_hexa(unsigned int nb, int uppercase);
int ft_print_unsigned(unsigned int nb);
int ft_print_pointer(void *ptr);
int ft_print_char(char nb);
void print_hex_digit(unsigned long nb, int uppercase, int *count);

#endif
