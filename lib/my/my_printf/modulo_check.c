/*
** EPITECH PROJECT, 2020
** modulo_check.c
** File description:
** function to check for double modulos
*/

#include "my.h"

int modulo_check(const char *format, int i)
{
    if (format[i + 1] == '%') {
        my_putchar('%');
        return (1);
    }
    return (0);
}