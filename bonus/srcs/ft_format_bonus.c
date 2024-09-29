#include "ft_printf.h"

int ft_print_binary(int nb)
{
    int count = 0;
    char bit;

    if (nb == 0)
        return write(1, "0", 1);
    if (nb > 1)
        count += ft_print_binary(nb / 2);
    bit = (nb % 2) + '0'; 
    count += write(1, &bit, 1);

    return (count);
}

int ft_print_octal(int nb)
{
    int count = 0;
    char digit;

    if (nb == 0)
        return write(1, "0", 1);
    if (nb >= 8)
        count += ft_print_octal(nb / 8);
    digit = (nb % 8) + '0';
	count += write(1, &digit, 1);
    return (count);
}

static void print_integer_part(int nb, int *count)
{
    char digit;

    if (nb >= 10)
        print_integer_part(nb / 10, count);
    
    digit = (nb % 10) + '0';
    write(1, &digit, 1);
    (*count)++;
}

static void print_fractional_part(float nb, int *count)
{
    int precision = 6; 
    int digit;
    char c;

    while (precision > 0)
    {
        nb *= 10;
        digit = (int)nb;
        c = digit + '0';
        write(1, &c, 1);
        (*count)++;
        nb -= digit;
        precision--;
    }
}

int ft_print_float(float nb)
{
    int count = 0;
    int integer_part;
    float fractional_part;

    if (nb < 0)
    {
        count += write(1, "-", 1);
        nb = -nb;
    }
    integer_part = (int)nb;
    fractional_part = nb - integer_part;
    print_integer_part(integer_part, &count);
    count += write(1, ".", 1);
    print_fractional_part(fractional_part, &count);

    return (count);
}


