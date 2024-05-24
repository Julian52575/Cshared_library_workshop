/*
** EPITECH PROJECT, 2024
** Cshared library workshop
** File description:
** Crée et détruit une instance de linked_handler_t
*/
#include "linked.h"
#include "function.h"
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#warning Coder linked_handler_create
linked_handler_t *linked_handler_create(void)
{
    linked_handler_t *handler = malloc(sizeof(linked_handler_t));

    assert(handler != NULL);
    memset(handler, 0, sizeof(linked_handler_t));
    handler->add_node = linked_handler_add_node;
    handler->destroy = linked_handler_destroy;
    handler->get_node = linked_handler_get_node;
    handler->get_size = linked_handler_get_size;
    handler->remove_node = linked_handler_remove_node;
    return handler;
}

void linked_handler_destroy(linked_handler_t **handler)
{
    for (linked_t *current = (*handler)->node;
    current != NULL; current = current->next) {
        free(current);
    }
    free(handler);
    *handler = NULL;
    return;
}
