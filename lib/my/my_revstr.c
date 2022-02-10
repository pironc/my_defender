/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** function to reverse a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    int end = len;
    char tmp;

    for (int begin = 0; begin <= (len / 2); begin++) {
        tmp = str[begin];
        str[begin] = str[end];
        str[end] = tmp;
        end--;
    }
    return (str);
}