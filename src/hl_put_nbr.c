/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** jitter jitter
*/

#include <unistd.h>

void hl_put_nbr(int nb)
{
    long int nb_cp = (long int)nb;
    long int nb_length = 1;
    long int nb_elem = 0;
    long int nb_index = 0;
    if (nb_cp < 0) {
        write(1, "-", 1);
        nb_cp = nb_cp * (-1);
    }
    if (nb_cp == 0)
        write(1, "0", 1);
    for (long int counter = nb_cp; counter > 0; counter /= 10)
        nb_length *= 10;
    nb_length /= 10;
    for (; nb_length > 0; nb_length /= 10) {
        nb_elem = nb_cp / nb_length;
        nb_index = nb_elem * nb_length;
        write(1, (void *)(nb_elem + '0'), 1);
        nb_cp -= nb_index;
    }
}
