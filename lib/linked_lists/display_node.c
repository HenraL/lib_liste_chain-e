/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** display_node.c
*/

#include <stddef.h>

#include "linked_lists.h"

/*
** Display a specific node of a linked list
** -------------------------------------------------------------------
** In:
**   - linked_list_t *node -> the node to be displayed
**   - char *name          -> The tag you wish to give to the current output
*/

static char *get_correct_type_ovf(data_type_e type)
{
    switch (type) {
    case UNKNOWN:
        return "UNKNOWN";
    case INT_ARRAY:
        return "INT_ARRAY";
    case FLOAT_ARRAY:
        return "FLOAT_ARRAY";
    case END_OF_LINKED_LIST:
        return "END_OF_LINKED_LIST";
    default:
        return "{ERROR: UNKNOWN TYPE}";
    }
}

static char *get_correct_type(data_type_e type)
{
    switch (type) {
    case INT:
        return "INT";
    case VOID:
        return "VOID";
    case CHAR:
        return "CHAR";
    case FLOAT:
        return "FLOAT";
    case STRUCT:
        return "STRUCT";
    case STRING:
        return "STRING";
    default:
        return get_correct_type_ovf(type);
    }
}

/*
** skipping lines
** if (node->data != NULL) {
**        ll_put_str_nb("\tdata = ", (int)(node->data), ";\n");
**    } else {
**        ll_putstr("\tdata = (NULL);\n");
**    }
**
** if (node->prev != NULL) {
**        ll_put_str_nb("\tprev = ", (int)(node->prev), ";\n");
**    } else {
**        ll_putstr("\tprev = (NULL);\n");
**    }
**    if (node->next != NULL) {
**        ll_put_str_nb("\tnext = ", (int)(node->next), ";\n");
**    } else {
**        ll_putstr("\tnext = (NULL);\n");
**    }
*/

void display_node(linked_lists_t *node, char *name)
{

    ll_putstr(name);
    ll_put_str_nb("[", node->index, "] = {\n");
    ll_put_str_nb("\tindex = ", node->index, ";\n");
    ll_putstr("\tdata = content;\n");
    ll_put_str_str("\ttype = ", get_correct_type(node->type), ";\n");
    ll_putstr("\tprev = data;\n");
    ll_putstr("\tnext = data;\n");
    ll_putstr("}\n");
}
