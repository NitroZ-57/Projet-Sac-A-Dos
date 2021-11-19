#include "lst.h"
#include "lst_elm.h"
#include "outils.h"

#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h> 
#include <assert.h> 



void insert_after(struct lst_t * L, void * datum, struct lst_elm_t * place);


// ======================================================================================================================================

struct lst_t * new_lst() {
    struct lst_t * L = ( struct lst_t *) calloc (1 , sizeof ( struct lst_t ) );
    assert (L);
    return L;
}

// ======================================================================================================================================

void del_lst(struct lst_t ** ptrL, void (*ptrFct)() ) {
    assert ( ptrL && * ptrL );

    if( (*ptrFct) != NULL ) {
        for ( struct lst_elm_t * E = (* ptrL )->head ; E; ) {
            struct lst_elm_t * T = E;
            E = E->suc;
            (*ptrFct) (T->datum );
            free(T);
        }
    } 
    else {
        for ( struct lst_elm_t * E = (* ptrL )->head ; E; ) {
            struct lst_elm_t * T = E;
            E = E->suc ;
            free(T);
        }
    }
	free (*ptrL);
	(*ptrL) = NULL;
}

// ======================================================================================================================================

bool empty_lst(const struct lst_t * L ) {
	return (L->numelm == 0);
}

// ======================================================================================================================================

void cons(struct lst_t * L, void * datum) { 
	assert (L);
	struct lst_elm_t * E = new_lst_elm ( datum );
	assert (E);
	
	E->suc = L->head ;
	L->head = E;

	if(L->numelm == 0) 
		L->tail = E;

	L->numelm += 1;

}

// ======================================================================================================================================
void view_lst(struct lst_t * L, void (* ptrFct)() ) {

	printf( "[ " );
	for( struct lst_elm_t * E = L->head; E; E = E->suc) {
		(*ptrFct)(E->datum);
	}
	printf( "]\n\n" );    

} 

// ======================================================================================================================================

void queue ( struct lst_t * L , void * datum ) {
    assert(L);

	struct lst_elm_t *new_tail = new_lst_elm(datum);
	L->tail->suc = new_tail;

}

// ======================================================================================================================================

void insert_ordered(struct lst_t * L, void * datum, bool (* ptrFct ) ()) {

    assert(L);

    if(empty_lst(L)) 
        cons(L, datum);

    else if((*ptrFct)(datum, L->head->datum)) 
        cons(L, datum);
    
    else if((*ptrFct)( L->tail->datum, datum)) 
        queue(L, datum);
    
    else {


        for( struct lst_elm_t * E = L->head; E->suc; E = E->suc) {
		    if((*ptrFct)(datum, E->suc->datum)) {
                
                insert_after(L, datum, E);
                break;
            }
	    }


    }
    
}


// ======================================================================================================================================


struct lst_elm_t * getHead ( struct lst_t * L) {
	assert(L);
    return L->head;
}

// ======================================================================================================================================


struct lst_elm_t * getTail ( struct lst_t * L) {
    assert(L);
	return L->tail;
}

// ======================================================================================================================================

int getNumelm ( struct lst_t * L) {
    assert(L);
	return L->numelm;
}

// ======================================================================================================================================

int setNumelm ( struct lst_t * L , int numElm ) {
	assert(L);
    L->numelm = numElm;
    return numElm; 
}

// ======================================================================================================================================

void insert_after(struct lst_t * L, void * datum, struct lst_elm_t * place) {
    assert(L && place);
    if(place == NULL) 
        cons(L, datum);
    else {
        struct lst_elm_t * New = new_lst_elm(datum);
        New->suc = place->suc;
        place->suc = New;
    }
}