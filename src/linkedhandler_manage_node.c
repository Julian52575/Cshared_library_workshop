/*
** EPITECH PROJECT, 2024
** Cshared_library_workshop
** File description:
** Gère les éléments présent dans le gestionnaire
*/
#include "linked.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

static void
link(linked_t **head, linked_t *new)
{
    if (*head == NULL) {
        *head = new;
        return;
    }
    new->next = (*head);
    (*head)->prev = new;
    (*head) = new;
}

static void
unlink(linked_t *dead)
{
    if (dead->prev)
        dead->prev->next = dead->next;
}

bool linked_handler_add_node(linked_handler_t *handler,
    const void *data, const char *name)
{
    linked_t *node = NULL;

    if (name == NULL)
        return false;
    if (handler->get_node(handler, name) != NULL)
        return false;
    node = malloc(sizeof(linked_t));
    assert(node != NULL);
    node->data = data;
    node->name = name;
    node->next = NULL;
    node->prev = NULL;
    link(&handler->node, node);
    handler->element += 1;
    return true;
}

bool linked_handler_remove_node(linked_handler_t *handler,
    const char *name)
{
    linked_t *dead = NULL;

    if (name == NULL)
        return false;
    dead = handler->get_node(handler, name);
    if (dead == NULL)
        return false;
    if (dead == handler->node) {
        handler->node = dead->next;
    } else {
        unlink(dead);
    }
    free(dead);
    handler->element -= 1;
    return true;
}

linked_t *linked_handler_get_node(linked_handler_t *handler,
    const char *node_name)
{
    if (node_name == NULL)
        return NULL;
    if (handler->get_size(handler) == 0)
        return NULL;
    for (linked_t *current = handler->node;
    current != NULL; current = current->next) {
        if (strcmp(node_name, current->name) == 0)
            return current;
    }
    return NULL;
}

size_t linked_handler_get_size(const struct linked_handler_s *this)
{
    return this->element;
}
