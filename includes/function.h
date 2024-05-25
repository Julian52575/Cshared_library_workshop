/*
** EPITECH PROJECT, 2024
** Cshared_library_workshop
** File description:
** all function prototyping
** should not be included in the program that use this library
*/
#pragma once
#include <stdbool.h>
#include <stddef.h>

typedef struct linked_handler_s linked_handler_t;
typedef struct linked_s linked_t;

void linked_handler_destroy(linked_handler_t **handler);

bool linked_handler_add_node(linked_handler_t *handler,
    const void *data, const char *name);

bool linked_handler_remove_node(linked_handler_t *handler,
    const char *name);

linked_t *linked_handler_get_node(const linked_handler_t *handler,
    const char *node_name);

size_t linked_handler_get_size(const struct linked_handler_s *this);

void linked_handler_debug(const struct linked_handler_s *this);
