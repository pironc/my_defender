/*
** EPITECH PROJECT, 2020
** my_int_to_str.c
** File description:
** function to convert an integer to a string
*/

#include "my.h"

char *my_int_to_str(int nb)
{
    int i = 0;
    int nb_len = 0;
    int new_nb = nb;
    char *result = NULL;

    while (new_nb % 10) {
        new_nb = new_nb / 10;
        nb_len++;
    }

    result = malloc(sizeof(char) * nb_len + 2);

    for (i = 0; nb >= 10; i++) {
        result[i] = (nb % 10) + '0';
        nb /= 10;
    }
    result[i] = (nb % 10) + '0';
    result[i + 1] = '\0';
    result[i + 2] = '\0';
    result = my_revstr(result);
    return (result);
}