#pragma once
#include <stdbool.h>
#include "objects.h"

// ======================================================================================================================================

/***
 * LES TYPES ABSTRAITS
 ***/

/** @brief Le type d'un élément de liste:
 * + x - un entier,
 * + suc - un pointeur sur son successeur (ou NULL s'il n'y en a pas)
 */
struct list_elm_t {
  void * datum ;
  struct list_elm_t * suc ;
};

// ======================================================================================================================================


/** @brief create a new list element and store datum into it */
struct list_elm_t * new_list_elm ( void * datum );
/** @brief destroy the list element pointed by E and set E to NULL */
void del_list_elm ( struct list_elm_t ** ptrE , void (* ptrFct ) ());
/** @brief retreive the datum of the list element E */
void * getDatum ( struct list_elm_t * E) ;
/** @brief retreive the succesor of the list element E */
struct list_elm_t * getSuc ( struct list_elm_t * E );
/** @brief modify the date of the list element */
void setDatum ( struct list_elm_t * E , void * datum );
/** @brief modify the succesor of the list element */
void setSuc ( struct list_elm_t * E , struct list_elm_t * S );
