/*
** EPITECH PROJECT, 2022
** tmp
** File description:
** my_putstr.c
*/

#include <unistd.h>

#include "root.h"

void hl_putstr(char const *str)
{
    write(1, str, hl_strlen(str));
}
