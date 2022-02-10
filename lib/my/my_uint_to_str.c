/*
** EPITECH PROJECT, 2020
** my_uint_to_str.c
** File description:
** function to convert an integer to a string
*/

#include "my.h"

char *my_uint_to_str(unsigned int nb)
{
    int i = 0;
    int nb_len = 1;
    char *res = NULL;
    unsigned int nb_copy = nb;

    for (nb_len = 1; (nb_copy / 10) > 0; nb_len++)
        nb_copy = nb_copy / 10;

    res = malloc(sizeof(char) * nb_len + 1);

    for (nb_copy = nb; nb_len > 1; i++) {
        res[i] = (nb_copy % 10) + '0';
        nb_copy = nb_copy / 10;
        nb_len--;
    }
    res[i] = (nb_copy % 10) + '0';
    res = my_revstr(res);
    res[i + 1] = '\0';
    return (res);
}