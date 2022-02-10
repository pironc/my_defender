/*
** EPITECH PROJECT, 2020
** flags_0to4.c
** File description:
** four first flags for my_printf
*/

#include "my.h"

int f_c2(const char *format, int i, va_list ap, pad_s **pad)
{
    if (format[i + 1] == 'c' || format[i + 1] == 'C') {
        f_c2_nested_loop(pad, ap);
        i++;
    }
    return (i);
}

int f_di(const char *format, int i, va_list ap, pad_s **pad)
{
    va_list ap_cpy;
    va_copy(ap_cpy, ap);
    int arg_len = my_strlen(my_int_to_str(va_arg(ap_cpy, int)));

    if (format[i + 1] == 'd' || format[i + 1] == 'i') {
        f_di_nested_loop(pad, ap, arg_len);
        i++;
    }
    return (i);
}

void f_s2_loop(char *str, int x)
{
    if (str[x] >= 32 && str[x] <= 126)
        my_putchar(str[x]);
    else {
        if (str[x] <= 9)
            my_printf("\\00%d", str[x]);
        else if (str[x] <= 31)
            my_printf("\\0%d", str[x]);
        if (str[x] == 127)
            my_printf("\\%d", str[x]);
    }
}

int f_s2(const char *format, int i, va_list ap, pad_s **pad)
{
    char *str = va_arg(ap, char *);

    if (format[i + 1] == 's') {
        if (str == NULL)
            my_putstr("(null)");
        else
            f_s2_nested_loop(pad, str);
        i++;
    } else if (format[i + 1] == 'S') {
        if (str == NULL) {
            my_putstr("(null)");
            return (i + 1);
        }
        for (int x = 0; str[x] != '\0'; x++)
            f_s2_loop(str, x);
        i++;
    }
    return (i);
}

int f_u(const char *format, int i, va_list ap, pad_s **pad)
{
    va_list ap_cpy;
    va_copy(ap_cpy, ap);
    int arg_len = my_strlen(my_uint_to_str(va_arg(ap_cpy, unsigned int)));

    if (format[i + 1] == 'u') {
        f_u_nested_loop(pad, ap, arg_len);
        i++;
    }
    return (i);
}