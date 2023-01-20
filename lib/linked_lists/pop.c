/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** pop.c
*/

#include <stdlib.h>

#include "linked_lists.h"

/*
** Pop: take the n'th element of the linked list and return it's value.
** ---------------------------------------------------------------------------
** Function type: void *
** Input arguments:
**  1. linked_list_t *linked_list -> the list containing the node to be freed
**  2. int index                  -> the index of the node to be freed
**  3. data_type_e *type          -> a pointer to know the type of the
**                                   returned data
** ---------------------------------------------------------------------------
** Output:
**   The data under the form of a void *
** ---------------------------------------------------------------------------
** Error management:
**   if the requested node does not exist:
**      -  NULL will be the return value
**      -  UNKNOWN will be the type input in data_type_e
*/

void *pop(linked_lists_t **ll, int index, data_type_e *type)
{
    linked_lists_t *tmp;
    void *result = NULL;
    *type = UNKNOWN;

    if (*ll == NULL && index < 0)
        return result;
    for (tmp = *ll; tmp != NULL && index > 0; tmp = tmp->next, index--);
    if (index > 0)
        return result;
    if (tmp->prev != NULL) {
        tmp->prev->next = tmp->next;
    } else {
        *ll = (*ll)->next;
    }
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    result = tmp->data;
    *type = tmp->type;
    update_indexes(ll);
    free(tmp);
    return result;
}
