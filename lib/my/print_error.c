/*
** EPITECH PROJECT, 2020
** print_error.c
** File description:
** function to print on the stderr output
*/

#include "my.h"

int print_error(char *str)
{
    write(2, str, my_strlen(str));
    return (84);
}