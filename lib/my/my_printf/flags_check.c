/*
** EPITECH PROJECT, 2020
** flags_check.c
** File description:
** function to check for special flags
*/

#include "my.h"

void special_flags_check(const char *format, int *i, va_list ap, pad_s **pad)
{
    if (format[(*i) + 1] == '#')
        f_hashtag(format, &(*i), ap);
    if (format[(*i) + 1] == ' ')
        f_space(format, &(*i), ap);
    if (format[(*i) + 1] == '0')
        f_zero(format, &(*i), &(*pad));
    if (format[(*i) + 1] == '-')
        f_dash(format, &(*i), &(*pad));
    if (format[(*i) + 1] >= '1' && format[(*i) + 1] <= '9')
        f_number(format, &(*i), &(*pad));
}

int basic_flags_check(const char *format, int i, va_list ap, pad_s **pad)
{
    int step = i;
    char *bas_flags = "cCdisSbouxXp";
    int (*basic_flags[])(const char*, int, va_list, pad_s**) = {f_c2, f_c2, \
        f_di, f_di, f_s2, f_s2, f_b, f_o, f_u, f_x, f_x_cap, f_p};

    for (int x = 0; bas_flags[x] != '\0'; x++)
        if (format[i + 1] == bas_flags[x])
            step = basic_flags[x](format, i, ap, &(*pad));
    return (step);
}