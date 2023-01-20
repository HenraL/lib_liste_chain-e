/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** init_list.c
*/

#include <stdlib.h>

#include "linked_lists.h"

/*
** Create the first node of any linked list
** -------------------------------------------------------------------
** In:
**   - void *data             -> The data of the first node
**   - data_type_e type       -> The type of data
** -------------------------------------------------------------------
** Out:
**   - linked_list_t *
** -------------------------------------------------------------------
** Error management:
**    if the allocation fails:
**       the NULL value will be returned
*/

linked_lists_t *init_list(void *data, data_type_e type)
{
    linked_lists_t *ll = malloc(sizeof(linked_lists_t));

    if (ll == NULL) {
        return NULL;
    }
    ll->index = 0;
    ll->data = data;
    ll->type = type;
    ll->next = NULL;
    ll->prev = NULL;
    return ll;
}
