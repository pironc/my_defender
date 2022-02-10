/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** function to concatenate src at the end of dest
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *newdest = malloc(sizeof(char) * (dest_len + src_len + 1));

    newdest = my_strcpy(newdest, dest);
    for (int i = 0; src[i] != '\0' && src[i] != ' '; i++) {
        dest[dest_len] = src[i];
        dest_len++;
    }
    dest[dest_len] = '\0';
    return (dest);
}