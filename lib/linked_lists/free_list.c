/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** free_list.c
*/

#include <stdlib.h>

#include "linked_lists.h"

/*
** Free the totality of the linked list.
** -------------------------------------------------------------------
** In:
**   - linked_list_t **linked_list   -> The linked list to be freed
** -------------------------------------------------------------------
** Important notice:
**     The data contained in data will not be freed by this function.
**     It is thus, up to you to free it.
*/

void free_list(linked_lists_t **ll)
{
    linked_lists_t *tmp;

    while (*ll != NULL) {
        tmp = (*ll)->next;
        free(*ll);
        *ll = tmp;
    }
}
