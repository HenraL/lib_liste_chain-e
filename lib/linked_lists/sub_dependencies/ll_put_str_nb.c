/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** ll_put_str_nb.c
*/

#include "linked_lists.h"

void ll_put_str_nb(char *str, int nb, char *end)
{
    ll_putstr(str);
    ll_put_nbr(nb);
    ll_putstr(end);
}
