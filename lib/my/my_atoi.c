/*
** EPITECH PROJECT, 2020
** my_atoi.c
** File description:
** function to convert a string to an int
*/

#include "my.h"

int my_atoi(const char *nptr)
{
    int i = 0;
    int res = 0;
    int neg = 0;

    if (nptr[0] == '-') {
        i = 1;
        neg = 1;
    }
    for (; nptr[i] != '\0'; i++)
        res = (res * 10) + (nptr[i] - '0');
    if (neg == 1)
        res *= -1;
    return (res);
}