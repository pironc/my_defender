/*
** EPITECH PROJECT, 2021
** my_putarr.c
** File description:
** function to print an array
*/

#include "my.h"

void my_putarr(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        my_printf("%s\n", array[i]);
}