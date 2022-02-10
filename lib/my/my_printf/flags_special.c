/*
** EPITECH PROJECT, 2020
** flags_special.c
** File description:
** function to look for special flags
*/

#include "my.h"

void f_hashtag(const char *format, int *i, va_list ap)
{
    va_list ap_cpy;
    va_copy(ap_cpy, ap);

    if (format[(*i) + 2] == 'o' && va_arg(ap_cpy, int) != 0)
        my_putstr("0");
    if (format[(*i) + 2] == 'x')
        my_putstr("0x");
    if (format[(*i) + 2] == 'X')
        my_putstr("0X");
    (*i) += 1;

    va_end(ap_cpy);
}