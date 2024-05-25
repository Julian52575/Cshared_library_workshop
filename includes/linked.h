/*
** EPITECH PROJECT, 2024
** linked list workshop
** File description:
** header
*/
#pragma once
#include <stddef.h>
#include <stdbool.h>

        /**
         * @brief Une liste chainnée générique */
typedef struct linked_s {
    const void *data;
    const char *name;

    struct linked_s *prev;
    struct linked_s *next;
        //  Vous pouvez ajouter des éléments à la structure...
} linked_t;

        /**
         * @brief Un gestionnaire de liste chainée */
typedef struct linked_handler_s {
    linked_t *node;
        //  Vous pouvez ajouter des éléments à la structure...

        /**
         * @brief   Detruit une instance de linked_handler
         et nullifie le pointeur passé en paramètre
         * @param this_ptr Double pointeur vers le gestionnaire */
    void (*destroy)(struct linked_handler_s **this_ptr);

        /**
         * @return True si l'ajout s'est éffectuée correctement
         * @brief   Crée une nouvelle node dans gestionnaire,
         * n'accepte pas les nom NULL et les doubles.
         * @param this L'instance de linked_handler à mettre à jour
         * @param data Un pointeur sur une donnée à sauvegarder dans la liste
         * @param node_name Le nom du nouvel element */
    bool (*add_node)(struct linked_handler_s *this,
        const void *data, const char *node_name);

        /**
         * @return True si la déstruction s'est éffectuée correctement
         * @brief   Détruit une node du gestionnaire
         *(Le pointeur sur la donnée stockée (data) n'est pas détruit)
         * @param this L'instance de linked_handler à mettre à jour
         * @param node_name Le nom de l'élement à retirer */
    bool (*remove_node)(struct linked_handler_s *this,
        const char *node_name);

        /**
         * @brief  Obtient un pointeur sur une node.
         * @return Le pointeur sur la node
         * @param this L'instance de linked_handler
         * @param node_name Le nom de la node */
    linked_t *(*get_node)(const struct linked_handler_s *this,
        const char *node_name);

        /**
         * @return Renvoie le nombre d'éléments dans le gestionnaire
         * @param  this L'instance de linked_handler */
    size_t (*get_size) (const struct linked_handler_s *this);

        /**
         * @brief Print les élèments présent dans le gestionnaire.*/
    void (*debug) (const struct linked_handler_s *this);
} linked_handler_t;

/**
 * @brief   Crée une instance de linked_handler
*/
linked_handler_t *linked_handler_create(void);
