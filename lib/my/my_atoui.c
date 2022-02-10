/*
** EPITECH PROJECT, 2020
** my_atoui.c
** File description:
** function to convert a string to an int
*/

#include "my.h"

unsigned int my_atoui(const char *nptr)
{
    unsigned int res = 0;

    for (int i = 0; nptr[i] != '\0'; i++)
        res = (res * 10) + (nptr[i] - '0');
    return (res);
}