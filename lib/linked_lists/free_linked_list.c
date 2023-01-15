/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** free_linked_list.c
*/

#include <stdlib.h>
#include "linked_lists.h"

void free_linked_list(linked_lists_t *ll)
{
    linked_lists_t *tmp;
    if (ll != NULL) {
        for (tmp = ll; tmp->next != NULL; tmp = tmp->next) {
            if (tmp->prev != NULL) {
                free(tmp->prev);
            }
        }
        if (tmp != NULL) {
            free(tmp);
        }
    }
}
