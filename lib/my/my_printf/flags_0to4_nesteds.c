/*
** EPITECH PROJECT, 2020
** flag_0to4_nesteds.c
** File description:
** function for nested for loops in "0to4" flags
*/

#include "my.h"

void f_c2_nested_loop(pad_s **pad, va_list ap)
{
    for (int x = 0; x < (int)(*pad)->zero_pad - 1; x++)
        my_putchar(' ');
    for (int x = 0; x < (int)(*pad)->sp_pad_left - 1; x++)
        my_putchar(' ');
    my_putchar(va_arg(ap, int));
    for (int x = 0; x < (int)(*pad)->sp_pad_right - 1; x++)
        my_putchar(' ');
}

void f_di_nested_loop(pad_s **pad, va_list ap, int arg_len)
{
    for (int x = 0; x < (int)(*pad)->zero_pad - arg_len; x++)
        my_putchar('0');
    for (int x = 0; x < (int)(*pad)->sp_pad_left - arg_len; x++)
        my_putchar(' ');
    my_put_nbr(va_arg(ap, int));
    for (int x = 0; x < (int)(*pad)->sp_pad_right - arg_len; x++)
        my_putchar(' ');
}

void f_s2_nested_loop(pad_s **pad, char *str)
{
    for (int x = 0; x < ((int)(*pad)->zero_pad - my_strlen(str)); x++)
        my_putchar(' ');
    for (int x = 0; x < ((int)(*pad)->sp_pad_left - my_strlen(str)); x++)
        my_putchar(' ');
    my_putstr(str);
    for (int x = 0; x < ((int)(*pad)->sp_pad_right - my_strlen(str)); x++)
        my_putchar(' ');
}

void f_u_nested_loop(pad_s **pad, va_list ap, int arg_len)
{
    for (int x = 0; x < ((int)(*pad)->zero_pad - arg_len); x++)
        my_putchar('0');
    for (int x = 0; x < ((int)(*pad)->sp_pad_left - arg_len); x++)
        my_putchar(' ');
    my_put_unsigned_nbr(va_arg(ap, unsigned int));
    for (int x = 0; x < ((int)(*pad)->sp_pad_right - arg_len); x++)
        my_putchar(' ');
}