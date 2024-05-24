/*
** EPITECH PROJECT, 2024
** Cshared_library_workshop
** File description:
** node unit tests
*/
#include "linked.h"
#include <assert.h>
#include <stdio.h>

static void
remove_node(linked_handler_t *handler)
{
    printf("[Tests] Running remove...\n"); //
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
get_node_data(linked_handler_t *handler)
{
    int *ptr = NULL;

    printf("[Tests] Running basic get node...\n"); //
    ptr = (int *) handler->get_node(handler, "First")->data;
    check_data(ptr, 1);
    ptr = (int *) handler->get_node(handler, "Second")->data;
    check_data(ptr, 2);
    ptr = (int *) handler->get_node(handler, "Third")->data;
    check_data(ptr, 3);
    ptr = (int *) handler->get_node(handler, "Fourth")->data;
    check_data(ptr, 4);
    ptr = (int *) handler->get_node(handler, "Fifth")->data;
    check_data(ptr, 5);

    printf("[Tests] Running NULL add node...\n"); //
    ptr = (int *) handler->get_node(handler, "Non existant");
    assert(ptr == NULL);
    ptr = (int *) handler->get_node(handler, "Null")->data;
    assert(ptr == NULL);
}

static void
add_node(linked_handler_t *handler)
{
    static int first = 1;
    static int second = 2;
    static int third = 3;
    static int fourth = 4;
    static int fifth = 5;

    printf("[Tests] Running basic add node...\n"); //
    assert(handler->add_node(handler, &first, "First") == true);
    assert(handler->add_node(handler, &second, "Second") == true);
    assert(handler->add_node(handler, &third, "Third") == true);
    assert(handler->add_node(handler, &fourth, "Fourth") == true);
    assert(handler->add_node(handler, &fifth, "Fifth") == true);
    assert(handler->add_node(handler, NULL, "Null") == true);

    assert(handler->add_node(handler, &first, NULL) == false);
    assert(handler->add_node(handler, &first, "destroy") == true);
    assert(handler->remove_node(handler, "destroy") == true);

    printf("[Tests] Running node duplicate...\n"); //
    assert(handler->add_node(handler, &fifth, "Duplicate") == true);
    assert(handler->add_node(handler, &fifth, "Duplicate") == false);
    assert(handler->remove_node(handler, "Duplicate") == true);
}

int main(void)
{
    linked_handler_t *handler = linked_handler_create();

    add_node(handler);
    get_node_data(handler);
    remove_node(handler);
    return 0;
}
