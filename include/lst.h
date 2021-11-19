#pragma once
#include <stdbool.h>

// ======================================================================================================================================

/** @brief Le type d'une liste :
	* + head - le premier élément de la liste
	* + tail - le dernier élément de la liste
	* + numelm - le nombre d'élément dans la liste
*/
struct list_t {
    struct list_elm_t * head ;
    struct list_elm_t * tail ;
    int numelm ;
};

// ======================================================================================================================================

/***
 * DÉCLARATION DES FONCTIONS PUBLIQUES
 ***/
/** @brief Construire une liste vide */
struct list_t * new_list () ;
/** @brief Libèrer la mémoire occupée par la liste */
void del_list ( struct list_t ** ptrL , void (* ptrFct ) () );
/** @brief Vérifier si la liste L est vide ou pas */
bool empty_list ( const struct list_t * L) ;
/** @brief Ajouter en tête de la liste L la donnée */
void cons ( struct list_t * L , void * datum );
/** @brief Ajouter en queue de la liste L la donnée */
void queue ( struct list_t * L , void * datum ) ;
/** @brief Insérer dans la liste L la donnée suivant l'ordre donné par la fonction pointée par ptrFct */
void insert_ordered ( struct list_t * L , void * datum , bool (* ptrFct ) () );
/** @brief Consulter la tête de la liste */
struct list_elm_t * getHead ( struct list_t * L);
/** @brief Consulter la queue de la liste */
struct list_elm_t * getTail ( struct list_t * L);
/** @brief Consulter le nombre d'éléments rangés dans la liste */
int getNumelm ( struct list_t * L);
/** @brief Modifier le nombre d'éléments rangés dans la liste */
int setNumelm ( struct list_t * L , int numElm );
/** @brief Visualiser les éléments de la liste L grâce à la fonction pointée par ptrFct */
void view_list ( struct list_t * L , void (* ptrFct ) () );
/** @brief Fait une copie la liste passée en paramètre et la retourne */
struct list_t * listcpy(struct list_t * l);