/*
** EPITECH PROJECT, 2020
** special_checks.c
** File description:
** special checks for special cases
*/

#include "my.h"

void f_space(const char *format, int *i, va_list ap)
{
    va_list ap_cpy;
    va_copy(ap_cpy, ap);
    int nb = va_arg(ap_cpy, int);

    if (format[*i + 2] == 'i' || format[*i + 2] == 'd') {
        if (nb >= 0)
            my_putchar(' ');
        *i += 1;
    }
    va_end(ap_cpy);
}

void f_zero(const char *format, int *i, pad_s **pad)
{
    int x = 0;
    char *padding_str = NULL;

    (*i) += 2;
    for (x = *i; format[x] >= '0' && format[x] <= '9'; x++);
    padding_str = malloc(sizeof(char) * ((x - *i) + 1));
    for (x = 0; format[(*i)] >= '0' && format[(*i)] <= '9'; x++) {
        padding_str[x] = format[(*i)];
        (*i)++;
    }
    padding_str[x] = '\0';
    (*pad)->zero_pad = my_atoui(padding_str);
    (*i)--;
}

void f_dash(const char *format, int *i, pad_s **pad)
{
    int x = 0;
    char *padding_str = NULL;

    (*i) += 2;
    for (x = *i; format[x] >= '0' && format[x] <= '9'; x++);
    padding_str = malloc(sizeof(char) * ((x - *i) + 1));
    for (x = 0; format[(*i)] >= '0' && format[(*i)] <= '9'; x++) {
        padding_str[x] = format[(*i)];
        (*i)++;
    }
    padding_str[x] = '\0';
    (*pad)->sp_pad_right = my_atoui(padding_str);
    (*i)--;
}

void f_number(const char *format, int *i, pad_s **pad)
{
    int x = 0;
    char *padding_str = NULL;

    (*i) += 1;
    for (x = *i; format[x] >= '0' && format[x] <= '9'; x++);
    padding_str = malloc(sizeof(char) * ((x - *i) + 1));
    for (x = 0; format[(*i)] >= '0' && format[(*i)] <= '9'; x++) {
        padding_str[x] = format[(*i)];
        (*i)++;
    }
    padding_str[x] = '\0';
    (*pad)->sp_pad_left = my_atoui(padding_str);
    (*i)--;
}