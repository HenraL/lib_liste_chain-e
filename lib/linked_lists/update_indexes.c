/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** update_indexes.c
*/

#include <stddef.h>

#include "linked_lists.h"

/*
** Update the index of every node in the linked list.
** -------------------------------------------------------------------
** In:
**   - linked_lists_t **ll    -> The linked list
*/

void update_indexes(linked_lists_t **ll)
{
    int i = 0;
    linked_lists_t *tmp;
    if (*ll != NULL) {
        for (tmp = *ll; tmp->next != NULL; tmp = tmp->next, i++) {
            tmp->index = i;
        }
    }
}
