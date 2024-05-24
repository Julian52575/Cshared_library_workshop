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
    return handler;
}

void linked_handler_destroy(linked_handler_t **handler)
{
#warning Coder linked_handler_destroy
    return;
}
