#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h> 
#include <assert.h>
#include "global.h"
#include "lst_elm.h"
#include "lst.h" 


// ======================================================================================================================================

void setSuc ( struct list_elm_t * E, struct list_elm_t * S ) { /** @todo */
    assert(E);
    E->suc = S;
}

// ======================================================================================================================================

void setDatum (struct list_elm_t * E, void* datum ) { /** @todo */
    assert(E);
    E->datum = datum;
}

// ======================================================================================================================================

struct list_elm_t * getSuc ( struct list_elm_t * E ) { /** @todo */
    assert(E);
    return E->suc;
}

// ======================================================================================================================================

void * getDatum ( struct list_elm_t * E ) { /** @todo */
    assert(E);
    return E->datum;
}

// ======================================================================================================================================

void del_list_elm_t(struct list_elm_t ** ptrE, void (* ptrFct ) ()) { 
    assert ( ptrE && * ptrE );

    free (*ptrE);
    *ptrE = NULL;

}

// ======================================================================================================================================

struct list_elm_t * new_list_elm( void * datum) { 
    struct list_elm_t * E = ( struct list_elm_t *) calloc (1 , sizeof( struct list_elm_t ) );
    assert(E);
    E->datum = datum;
    return E;

}


