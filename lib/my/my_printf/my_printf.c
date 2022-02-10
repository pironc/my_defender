/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** function that reproduces the printf system function
*/

#include "my.h"

int flag_check(const char *format, int i, va_list ap)
{
    pad_s *pad = malloc(sizeof(*pad));
    int cur_i = i;
    pad->zero_pad = 0;
    pad->sp_pad_left = 0;
    pad->sp_pad_right = 0;

    if (modulo_check(format, i) == 1)
        return (i + 1);
    special_flags_check(format, &i, ap, &pad);
    i = basic_flags_check(format, i, ap, &pad);
    pad->zero_pad = 0;
    pad->sp_pad_left = 0;
    pad->sp_pad_right = 0;
    if (cur_i == i)
        my_putchar(format[i]);
    return (i);
}

int my_printf(const char *format, ...)
{
    int i = 0;
    va_list ap;

    if (format == NULL)
        return (0);

    va_start(ap, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%')
            i = flag_check(format, i, ap);
        else
            my_putchar(format[i]);
    }
    va_end(ap);
    return (0);
}