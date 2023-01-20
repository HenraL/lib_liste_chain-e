/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** get_node_type.c
*/

#include <stdlib.h>

#include "linked_lists.h"

/*
** Get a the data from a specific node within a linked list
** -------------------------------------------------------------------
** In:
**   - linked_list_t *ll -> the linked list to process
**   - int index         -> the index of the node to return
**   - int *status       -> the current status of the function
** -------------------------------------------------------------------
** Out:
**   - data_type_e
**   - an up to date status (the value of the pointer get updated)
** -------------------------------------------------------------------
** Error management:
**   if the requested node does not exist:
**      -  NULL will be the return value
**      -  UNKNOWN will be the type input in data_type_e
*/

data_type_e get_node_type(linked_lists_t *ll, int index, int *status)
{
    linked_lists_t *tmp;
    *status = llsuccess;

    if (ll == NULL) {
        *status = llerror;
        return UNKNOWN;
    }
    for (tmp = ll; index > 0 && tmp != NULL; tmp = tmp->next, index--);
    if (index > 0) {
        *status = llerror;
        return UNKNOWN;
    }
    return tmp->type;
}
