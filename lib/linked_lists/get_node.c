/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** get_node.c
*/

#include <stdlib.h>

#include "linked_lists.h"

/*
** Get a specific node of a linked list
** -------------------------------------------------------------------
** In:
**   - linked_list_t *ll -> the linked list to process
**   - int index         -> the index of the node to return
**   - int *status       -> the current status of the function
** -------------------------------------------------------------------
** Out:
**   - linked_list_t
**   - an up to date status (the value of the pointer get updated)
*/

linked_lists_t *get_node(linked_lists_t *ll, int index, int *status)
{
    linked_lists_t *tmp;
    *status = llsuccess;

    if (ll == NULL) {
        *status = llerror;
        return NULL;
    }
    for (tmp = ll; index > 0 && tmp != NULL; tmp = tmp->next, index--);
    if (index > 0) {
        *status = llerror;
        return NULL;
    }
    return tmp;
}
