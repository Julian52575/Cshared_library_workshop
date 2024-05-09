/*
** EPITECH PROJECT, 2024
** Cshared_library_workshop
** File description:
** node unit tests
*/
#include "linked.h"
#include <assert.h>

static void
remove_node(linkedHandler_t *handler)
{
    assert(handler->remove_node(handler, "First") == true);
    assert(handler->remove_node(handler, "Second") == true);
    assert(handler->remove_node(handler, "Third") == true);
    assert(handler->remove_node(handler, "Fourth") == true);
    assert(handler->remove_node(handler, "Fifth") == true);
    assert(handler->remove_node(handler, "Null") == true);

    assert(handler->remove_node(handler, "Non existant") == false);
}

static void check_data(int *ptr, int value)
{
    assert(ptr != NULL);
    assert(*ptr == value);
}
static void
get_node_data(linkedHandler_t *handler)
{
    int *ptr = NULL;

    ptr = (int *) handler->get_node_data(handler, "First");
    check_data(ptr, 1);
    ptr = (int *) handler->get_node_data(handler, "Second");
    check_data(ptr, 2);
    ptr = (int *) handler->get_node_data(handler, "Third");
    check_data(ptr, 3);
    ptr = (int *) handler->get_node_data(handler, "Fourth");
    check_data(ptr, 4);
    ptr = (int *) handler->get_node_data(handler, "Fifth");
    check_data(ptr, 5);

    ptr = (int *) handler->get_node_data(handler, "Non existant");
    assert(ptr == NULL);

    ptr = (int *) handler->get_node_data(handler, "Null");
    assert(ptr == NULL);
}

static void
add_node(linkedHandler_t *handler)
{
    static int first = 1;
    static int second = 2;
    static int third = 3;
    static int fourth = 4;
    static int fifth = 5;

    assert(handler->add_node(handler, &first, "First") == true);
    assert(handler->add_node(handler, &second, "Second") == true);
    assert(handler->add_node(handler, &third, "Third") == true);
    assert(handler->add_node(handler, &fourth, "Fourth") == true);
    assert(handler->add_node(handler, &fifth, "Fifth") == true);
    assert(handler->add_node(handler, NULL, "Null") == true);
    
    assert(handler->add_node(handler, &first, NULL) == false);

    assert(handler->add_node(handler, &fifth, "Duplicate") == true);
    assert(handler->add_node(handler, &fifth, "Duplicate") == false);
    assert(handler->remove_node(handler, "Duplicate") == true);
}

int main(void)
{
    linkedHandler_t *handler = linkedHandler_create();

    malloc(1);
    assert(handler != NULL);
    add_node(handler);
    get_node_data(handler);
    remove_node(handler);
    return 0;
}