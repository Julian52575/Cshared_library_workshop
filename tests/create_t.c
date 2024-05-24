/*
** EPITECH PROJECT, 2024
** Cshared_library_workshop
** File description:
** create unit test
*/
#include "linked.h"
#include "function.h"
#include <assert.h>

static void
test_function(linked_handler_t *handler)
{
    assert(handler->add_node == linked_handler_add_node);
    assert(handler->destroy == linked_handler_destroy);
    assert(handler->get_node_data == (void*) linked_handler_get_node_data);
    assert(handler->remove_node == linked_handler_remove_node);
    assert(handler->get_size == linked_handler_get_size);
}

int main(void)
{
    linked_handler_t *handler = linked_handler_create();

    assert(handler != NULL);
    assert(handler->node == NULL);
    test_function(handler);
    handler->destroy(&handler);
    assert(handler == NULL);
    return 0;
}
