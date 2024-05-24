/*
** EPITECH PROJECT, 2024
** Cshared_library_workshop
** File description:
** stdout
*/
#include "linked.h"
#include <stdio.h>

void linked_handler_debug(const struct linked_handler_s *this)
{
    printf("Handler at address %p of %lu elements:\n",
        this, this->get_size(this));
}
