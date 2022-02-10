/*
** EPITECH PROJECT, 2020
** flag_bases_nesteds.c
** File description:
** function for nested for loops in base flags
*/

#include "my.h"

void f_b_nested_loop(char *binary, pad_s **pad)
{
    for (int x = 0; x < (int)(*pad)->zero_pad - my_strlen(binary); x++)
        my_putchar('0');
    for (int x = 0; x < (int)(*pad)->sp_pad_left - my_strlen(binary); x++)
        my_putchar(' ');
    my_putstr(binary);
    for (int x = 0; x < (int)(*pad)->sp_pad_right - my_strlen(binary); x++)
        my_putchar(' ');
}

void f_o_nested_loop(char *octal, pad_s **pad)
{
    for (int x = 0; x < (int)(*pad)->zero_pad - my_strlen(octal); x++)
        my_putchar('0');
    for (int x = 0; x < (int)(*pad)->sp_pad_left - my_strlen(octal); x++)
        my_putchar(' ');
    my_putstr(octal);
    for (int x = 0; x < (int)(*pad)->sp_pad_right - my_strlen(octal); x++)
        my_putchar(' ');
}

void f_x_nested_loop(char *hexa, pad_s **pad)
{
    for (int x = 0; x < (int)(*pad)->zero_pad - my_strlen(hexa); x++)
        my_putchar('0');
    for (int x = 0; x < (int)(*pad)->sp_pad_left - my_strlen(hexa); x++)
        my_putchar(' ');
    my_putstr(hexa);
    for (int x = 0; x < (int)(*pad)->sp_pad_right - my_strlen(hexa); x++)
        my_putchar(' ');
}

void f_x_cap_nested_loop(char *hexa, pad_s **pad)
{
    for (int x = 0; x < (int)(*pad)->zero_pad - my_strlen(hexa); x++)
        my_putchar('0');
    for (int x = 0; x < (int)(*pad)->sp_pad_left - my_strlen(hexa); x++)
        my_putchar(' ');
    my_putstr(hexa);
    for (int x = 0; x < (int)(*pad)->sp_pad_right - my_strlen(hexa); x++)
        my_putchar(' ');
}

void f_p_nested_loop(char *str, pad_s **pad)
{
    my_printf("0x");
    for (int x = 0; x < (int)(*pad)->zero_pad - (my_strlen(str) + 2); x++)
        my_putchar('0');
    for (int x = 0; x < (int)(*pad)->sp_pad_left - (my_strlen(str) + 2); x++)
        my_putchar(' ');
    my_printf("%x", str);
    for (int x = 0; x < (int)(*pad)->sp_pad_right - (my_strlen(str) + 2); x++)
        my_putchar(' ');
}