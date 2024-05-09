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
        //  Vous pouvez ajouter des éléments à la structure en fonction de vos besoin...
        //  ...
} linked_t;


        /**
         * @brief Un gestionnaire de liste chainée */
typedef struct linkedHandler_s {
    linked_t *node;
        //  Vous pouvez ajouter des éléments à la structure en fonction de vos besoin...
        //  ...
    
        /** 
         * @brief   Detruit une instance de linkedHandler et modifie le pointeur passé en paramètre
         * @param handler_ptr Double pointeur vers le gestionnaire */
    void    (*destroy)         (struct linkedHandler_s **handler_ptr);

        /**
         * @return True si l'ajout s'est éffectuée correctement
         * @brief   Crée une nouvelle node dans gestionnaire
         * @param handler L'instance de linkedHandler à mettre à jour
         * @param data Un pointeur sur une donnée à sauvegarder dans la liste
         * @param name Le nom de la nouvelle instance */
    bool    (*add_node)        (struct linkedHandler_s *handler, const void *data, const char *name);

        /**
         * @return True si la déstruction s'est éffectuée correctement
         * @brief   Détruit une node du gestionnaire
         * @param handler L'instance de linkedHandler à mettre à jour
         * @param name Le nom de la node à détruire */
    bool    (*remove_node)     (struct linkedHandler_s *handler, const char *name);

        /**
         * @brief  Obtient le donnée de la node name ou NULL
         * @return Le pointeur sur la donnée contenue par name ou NULL.
         * @param handler L'instance de linkedHandler
         * @param name Le nom de la node qui contient la donnée */
    void *  (*get_node_data)   (const struct linkedHandler_s *handler, const char *name);

        /**
         * @return Renvoie le nombre d'éléments dans le gestionnaire
         * @param  handler L'instance de linkedHandler */
    size_t (*get_size)  (const struct linkedHandler_s *handler);
} linkedHandler_t;

/**
 * @brief   Crée une instance de linkedHandler
*/
linkedHandler_t *linkedHandler_create(void);