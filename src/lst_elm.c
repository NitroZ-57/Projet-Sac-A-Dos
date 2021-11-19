#include "lst_elm.h"
#include "lst.h" 
#include "outils.h"

#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h> 
#include <assert.h>

// ======================================================================================================================================

void setSuc ( struct lst_elm_t * E, struct lst_elm_t * S ) { /** @todo */
    assert(E);
    E->suc = S;
}

// ======================================================================================================================================

void setDatum (struct lst_elm_t * E, void* datum ) { /** @todo */
    assert(E);
    E->datum = datum;
}

// ======================================================================================================================================

struct lst_elm_t * getSuc ( struct lst_elm_t * E ) { /** @todo */
    assert(E);
    return E->suc;
}

// ======================================================================================================================================

void * getDatum ( struct lst_elm_t * E ) { /** @todo */
    assert(E);
    return E->datum;
}

// ======================================================================================================================================

void del_lst_elm_t(struct lst_elm_t ** ptrE, void (* ptrFct ) ()) { 
    assert ( ptrE && * ptrE );

    free (*ptrE );
    *ptrE = NULL ;

}

// ======================================================================================================================================

struct lst_elm_t * new_lst_elm( void * datum) { 
    struct lst_elm_t * E = ( struct lst_elm_t *) calloc (1 , sizeof( struct lst_elm_t ) );
    assert(E);
    E->datum = datum;
    return E;

}


