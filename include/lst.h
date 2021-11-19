#pragma once
#include <stdbool.h>

// ======================================================================================================================================

/** @brief Le type d'une liste :
	* + head - le premier élément de la liste
	* + tail - le dernier élément de la liste
	* + numelm - le nombre d'élément dans la liste
*/
struct lst_t {
    struct lst_elm_t * head ;
    struct lst_elm_t * tail ;
    int numelm ;
};

// ======================================================================================================================================

/***
 * DÉCLARATION DES FONCTIONS PUBLIQUES
 ***/
/** @brief Construire une liste vide */
struct lst_t * new_lst () ;
/** @brief Libèrer la mémoire occupée par la liste */
void del_lst ( struct lst_t ** ptrL , void (* ptrFct ) () );
/** @brief Vérifier si la liste L est vide ou pas */
bool empty_lst ( const struct lst_t * L) ;
/** @brief Ajouter en tête de la liste L la donnée */
void cons ( struct lst_t * L , void * datum );
/** @brief Ajouter en queue de la liste L la donnée */
void queue ( struct lst_t * L , void * datum ) ;
/** @brief Insérer dans la liste L la donnée suivant l'ordre donné par la fonction pointée par ptrFct */
void insert_ordered ( struct lst_t * L , void * datum , bool (* ptrFct ) () );
/** @brief Consulter la tête de la liste */
struct lst_elm_t * getHead ( struct lst_t * L);
/** @brief Consulter la queue de la liste */
struct lst_elm_t * getTail ( struct lst_t * L);
/** @brief Consulter le nombre d'éléments rangés dans la liste */
int getNumelm ( struct lst_t * L);
/** @brief Modifier le nombre d'éléments rangés dans la liste */
int setNumelm ( struct lst_t * L , int numElm );
/** @brief Visualiser les éléments de la liste L grâce à la fonction pointée par ptrFct */
void view_lst ( struct lst_t * L , void (* ptrFct ) () );

