/*
** EPITECH PROJECT, 2021
** Task02 - my_putstr.c
** File description:
** abc
*/

#include <unistd.h>
#include "linked_lists.h"

void ll_putstr(char const *str)
{
    write(1, str, ll_strlen(str));
}
