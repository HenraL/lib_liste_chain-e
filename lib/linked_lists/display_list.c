/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** display_list.c
*/

#include <unistd.h>

#include "linked_lists.h"

/*
** Display all the nodes of a linked list
** -------------------------------------------------------------------
** In:
**   - linked_list_t *ll -> the linked list to be displayed
**   - char *name        -> The tag you wish to give to the current output
*/


void display_list(linked_lists_t *ll, char *name)
{
    linked_lists_t *tmp;
    for (tmp = ll; tmp != NULL; tmp = tmp->next) {
        display_node(tmp, name);
    }
    ll_put_str_str(name, "= (NULL)", ";\n");
}
