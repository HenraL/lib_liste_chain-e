/*
** EPITECH PROJECT, 2022
** linked_lists_lib (Workspace)
** File description:
** main.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#include "root.h"

int main(void)
{
    int i = 0;
    char *usr_message = "This is the function to be used for manual testing.\n";
    char *usr_message2 = "Any manually allocated data that is inputted into a node will not be freed by the program.\n";
    linked_lists_t *ll = init_list((void *)usr_message, STRING);
    linked_lists_t *tmp;

    append(ll, usr_message2, STRING);

    for (tmp = ll; tmp->next != NULL; i++, tmp = tmp->next) {
        if (tmp->type == STRING) {
            hl_putstr((char *)tmp->data);
        }
    }
    hl_putstr((char *)tmp->data);
    free_linked_list(ll);
    return 0;
}
