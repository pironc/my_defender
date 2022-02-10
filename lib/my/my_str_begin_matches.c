/*
** EPITECH PROJECT, 2021
** my_str_begin_matches.c
** File description:
** function to check if the beginning of a string matches the string sent
*/

#include "my.h"

int my_str_begin_matches(char *str, char *to_match)
{
    for (int i = 0; to_match[i] != '\0'; i++)
        if (str[i] != to_match[i])
            return (-1);
    return (0);
}