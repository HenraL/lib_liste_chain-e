/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** append_node.c
*/

#include <stdlib.h>

#include "linked_lists.h"

/*
** Get a specific node of a linked list
** -------------------------------------------------------------------
** In:
**   - linked_list_t **ll -> a pointer of the linked list to process
**   - void *data         -> the data to be added to the node
**   - data_type_e *type  -> the type of data that is added
** -------------------------------------------------------------------
** Out:
**   - int               -> the status of the operation (success/failure)
*/

int append_node(linked_lists_t **ll, void *data, data_type_e type)
{
    linked_lists_t *new_node = init_list(data, type);
    linked_lists_t *tmp;

    if (new_node == NULL) {
        return llerror;
    }
    if (*ll == NULL) {
        *ll = new_node;
        return llsuccess;
    }
    for (tmp = *ll; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new_node;
    new_node->prev = tmp;
    new_node->index = tmp->index + 1;
    return llsuccess;
}
