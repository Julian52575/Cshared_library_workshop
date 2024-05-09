/*
** EPITECH PROJECT, 2024
** Cshared_library_workshop
** File description:
** create unit test
*/
#include "linked.h"
#include <assert.h>

int main(void)
{
    linkedHandler_t *handler = linkedHandler_create();

    assert(handler != NULL);
    assert(handler->node == NULL);
    assert(handler->add_node != NULL);
    assert(handler->remove_node != NULL);
    assert(handler->get_node_data != NULL);
    assert(handler->get_size != NULL);
    assert(handler == NULL);
    return 0;
}