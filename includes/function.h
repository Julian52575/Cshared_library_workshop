/*
** EPITECH PROJECT, 2024
** Cshared_library_workshop
** File description:
** all function prototyping
*/
#pragma once
#include <stdbool.h>
typedef struct linkedHandler_s linkedHandler_t;

void linkedHandler_destroy(linkedHandler_t **handler);

bool linkedHandler_add_node(linkedHandler_t *handler, const void *data, const char *name);

bool linkedHandler_remove_node(linkedHandler_t *handler, const char *name);

void *linkedHandler_get_node_data(linkedHandler_t *handler, const char *name);