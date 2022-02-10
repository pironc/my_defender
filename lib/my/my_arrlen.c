/*
** EPITECH PROJECT, 2020
** my_arrlen.c
** File description:
** function to get the length of an array
*/

#include "my.h"

int my_arrlen(char **arr)
{
    int arrlen = 0;

    for (arrlen = 0; arr[arrlen] != NULL; arrlen++);
    return (arrlen);
}