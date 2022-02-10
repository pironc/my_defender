/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** function to calculate the length of a string
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;
    if (str == NULL)
        return (0);

    while (str[i] != '\0')
        i++;
    return (i);
}