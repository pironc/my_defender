/*
** EPITECH PROJECT, 2020
** flags_bases.c
** File description:
** functions to print numbers into bases
*/

#include "my.h"

int f_b(const char *format, int i, va_list ap, pad_s **pad)
{
    int x = 0;
    unsigned int uint_arg = va_arg(ap, unsigned int);
    char *binary = malloc(sizeof(char) * \
    (my_strlen(my_int_to_str(uint_arg)) * 3) + 2);

    if (format[i + 1] == 'b') {
        for (x = 0; uint_arg >= 2; x++) {
            binary[x] = uint_arg % 2 + '0';
            uint_arg /= 2;
        }
        binary[x] = uint_arg % 2 + '0';
        my_revstr(binary);
        binary[x + 1] = '\0';
        i++;
    }
    f_b_nested_loop(binary, pad);
    return (i);
}

int f_o(const char *format, int i, va_list ap, pad_s **pad)
{
    int x = 0;
    unsigned int uint_arg = va_arg(ap, unsigned int);
    char *octal = malloc(sizeof(char) * \
    (my_strlen(my_int_to_str(uint_arg)) * 3) + 2);

    if (format[i + 1] == 'o') {
        for (x = 0; uint_arg >= 8; x++) {
            octal[x] = uint_arg % 8 + '0';
            uint_arg /= 8;
        }
        octal[x] = uint_arg % 8 + '0';
        my_revstr(octal);
        octal[x + 1] = '\0';
        i++;
    }
    f_o_nested_loop(octal, pad);
    return (i);
}

int f_x(const char *format, int i, va_list ap, pad_s **pad)
{
    int x = 0;
    char *base = "0123456789abcdef";
    unsigned int uint_arg = va_arg(ap, unsigned int);
    char *hexa = malloc(sizeof(char) * (my_strlen(my_int_to_str(uint_arg))));

    if (format[i + 1] == 'x') {
        for (x = 0; uint_arg >= 16; x++) {
            hexa[x] = base[uint_arg % 16];
            uint_arg /= 16;
        }
        hexa[x] = base[uint_arg % 16];
        my_revstr(hexa);
        hexa[x + 1] = '\0';
        i++;
    }
    f_x_nested_loop(hexa, pad);
    return (i);
}

int f_x_cap(const char *format, int i, va_list ap, pad_s **pad)
{
    int x = 0;
    char *base = "0123456789ABCDEF";
    unsigned int uint_arg = va_arg(ap, unsigned int);
    char *hexa = malloc(sizeof(char) * (my_strlen(my_int_to_str(uint_arg))));

    if (format[i + 1] == 'X') {
        for (x = 0; uint_arg >= 16; x++) {
            hexa[x] = base[uint_arg % 16];
            uint_arg /= 16;
        }
        hexa[x] = base[uint_arg % 16];
        my_revstr(hexa);
        hexa[x + 1] = '\0';
        i++;
    }
    f_x_cap_nested_loop(hexa, pad);
    return (i);
}

int f_p(const char *format, int i, va_list ap, pad_s **pad)
{
    char *str = va_arg(ap, char *);

    if (format[i + 1] == 'p') {
        if (str == NULL)
            my_putstr("(nil)");
        else
            f_p_nested_loop(str, pad);
    }
    return (i + 1);
}