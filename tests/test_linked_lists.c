/*
** EPITECH PROJECT, 2022
** tmp
** File description:
** test_linked_lists.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "root.h"

void redirect_outputs(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test(init_list, test_list_initialisation, .init = redirect_outputs, .description = "Test the function in charge of initialising a linked list")
{
    linked_lists_t *ll = init_list((void *)"Test_node 0", STRING);
    cr_assert_neq(ll, NULL, "Allocation of linked list failed.");
    if (ll != NULL) {
        free(ll);
    }
}

Test(init_list, test_list_initialisation_content, .init = redirect_outputs, .description = "Test the content of the function in charge of initialising a linked list")
{
    char *data_node_0 = "Test_node 0";
    data_type_e type_node_0 = STRING;
    linked_lists_t *ll = init_list((void *)data_node_0, type_node_0);
    cr_assert_neq(ll, NULL, "Allocation of linked list failed.");
    if (ll != NULL) {
        cr_assert_str_eq((char *)ll->data, data_node_0, "Expected %s, but got %s.", data_node_0);
        cr_assert_eq(ll->next, NULL, "The child next from the node 0 of the linked list, has not properly been initialised.");
        cr_assert_eq(ll->prev, NULL, "The child prev from the node 0 of the linked list, has not properly been initialised.");
        cr_assert_eq(ll->index, 0, "The child index from the node 0 of the linked list, has not properly been initialised.");
        cr_assert_eq(ll->type, type_node_0, "The chile type from the node 0 of the linked list, has not properly been initialised.");
        free(ll);
    }
}


Test(append, test_node_adding, .init = redirect_outputs, .description = "test the function in charge of adding a node to the linked list")
{
    char *data_node_0 = "Test_node 0";
    data_type_e type_node_0 = STRING;
    char *data_node_1 = "Test node 1";
    data_type_e type_node_1 = STRING;
    linked_lists_t *ll = init_list((void *)data_node_0, type_node_0);
    cr_assert_neq(ll, NULL, "Allocation of linked list failed.");
    if (ll != NULL) {
        append(ll, (void *)data_node_1, type_node_1);
        cr_assert_str_eq((char *)ll->data, data_node_0, "Expected %s, but got %s.", data_node_0);
        cr_assert_eq(ll->prev, NULL, "The child prev from the node 0 of the linked list, has not properly been initialised.");
        cr_assert_eq(ll->index, 0, "Expected %d but got %d.", 0);
        cr_assert_eq(ll->type, type_node_0, "The chile type from the node 0 of the linked list, has not properly been initialised.");
        cr_assert_neq(ll->next, NULL, "Allocation of node 1 failed.");
        cr_assert_str_eq((char *)ll->data, data_node_0, "Expected %s, but got %s.", data_node_0);
        cr_assert_eq(ll->next->next, NULL, "The child next from the node 1 of the linked list, has not properly been initialised.");
        cr_assert_neq(ll->next->prev, NULL, "The child prev from the node 1 of the linked list, has not properly been initialised.");
        cr_assert_eq(ll->next->index, 1, "Expected %d but got %d.", 1);
        cr_assert_eq(ll->next->type, type_node_1, "The chile type from the node 1 of the linked list, has not properly been initialised.");
        cr_assert_str_eq((char *)ll->next->data, data_node_1, "Expected %s but got %s.", data_node_1);
        free(ll->next);
        free(ll);
    }
}

Test(free_node, test_node_freeing, .init = redirect_outputs, .description = "test the function in charge of freeing a node from the linked list")
{
    char *data_node_0 = "Test_node 0";
    char *data_node_1 = "Test node 1";
    linked_lists_t *ll = init_list((void *)data_node_0, STRING);
    cr_assert_neq(ll, NULL, "Allocation of linked list failed.");
    if (ll != NULL) {
        cr_assert_str_eq((char *)ll->data, data_node_0, "Expected %s, but got %s.", data_node_0);
        append(ll, (void *)data_node_1, STRING);
        cr_assert_neq(ll->next, NULL, "Allocation of node 1 failed.");
        cr_assert_str_eq((char *)ll->next->data, data_node_1, "Expected %s but got %s.", data_node_1);
        free_node(ll, 1);
        cr_assert_eq(ll->next, NULL, "The freeing of node 1 has partially (or totally) failed, please check if leaks are present.");
        free(ll);
    }
}
