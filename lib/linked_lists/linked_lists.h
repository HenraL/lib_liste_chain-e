/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** linked_lists.h
*/

#ifndef LINKED_LISTS_H_
#define LINKED_LISTS_H_

static const int llerror = 84;
static const int llsuccess = 0;

typedef enum data_type_e {
    INT,
    VOID,
    CHAR,
    FLOAT,
    STRUCT,
    STRING,
    UNKNOWN,
    INT_ARRAY,
    FLOAT_ARRAY,
    END_OF_LINKED_LIST
} data_type_e;

typedef struct linked_lists_s {
    int index;
    void *data;
    data_type_e type;
    char *struct_name;
    struct linked_lists_s *prev;
    struct linked_lists_s *next;
} linked_lists_t;

void ll_put_nbr(int nb);
void ll_putchar(char word);
void ll_putstr(char const *str);
void free_list(linked_lists_t **ll);
void update_indexes(linked_lists_t **ll);
void ll_put_str_nb(char *str, int nb, char *end);
void display_list(linked_lists_t *ll, char *name);
void display_node(linked_lists_t *node, char *name);
void ll_put_str_str(char *str, char *var, char *end);
void *pop(linked_lists_t **ll, int index, data_type_e *type);
void *get_node_data(linked_lists_t *ll, int index, int *status);

int ll_strlen(char const *str);
int append_node(linked_lists_t **ll, void *data, data_type_e type);

linked_lists_t *init_list(void *data, data_type_e type);
linked_lists_t *get_node(linked_lists_t *ll, int index, int *status);

data_type_e get_node_type(linked_lists_t *ll, int index, int *status);

#endif
