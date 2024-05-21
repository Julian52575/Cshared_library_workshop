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
         * @brief   Crée une nouvelle node dans gestionnaire
         * @param this L'instance de linked_handler à mettre à jour
         * @param data Un pointeur sur une donnée à sauvegarder dans la liste
         * @param node_name Le nom du nouvel element */
    bool (*add_node)(struct linked_handler_s *this,
        const void *data, const char *node_name);

        /**
         * @return True si la déstruction s'est éffectuée correctement
         * @brief   Détruit une node du gestionnaire
         *(la donnée n'est pas détruite)
         * @param this L'instance de linked_handler à mettre à jour
         * @param node_name Le nom de l'élement à retirer */
    bool (*remove_node)(struct linked_handler_s *this,
        const char *node_name);

        /**
         * @brief  Obtient le donnée de la node name ou NULL
         * @return Le pointeur sur la donnée contenue par name / NULL.
         * @param this L'instance de linked_handler
         * @param node_name Le nom de la node qui contient la donnée */
    void *(*get_node_data)(const struct linked_handler_s *this,
        const char *node_name);

        /**
         * @return Renvoie le nombre d'éléments dans le gestionnaire
         * @param  this L'instance de linked_handler */
    size_t (*get_size) (const struct linked_handler_s *this);
} linked_handler_t;

/**
 * @brief   Crée une instance de linked_handler
*/
linked_handler_t *linked_handler_create(void);
