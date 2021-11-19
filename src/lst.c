#include "lst.h"
#include "lst_elm.h"

#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h> 
#include <assert.h> 



void insert_after(struct list_t * L, void * datum, struct list_elm_t * place);


// ======================================================================================================================================

struct list_t * new_list() {
    struct list_t * L = ( struct list_t *) calloc (1 , sizeof ( struct list_t ) );
    assert (L);
    return L;
}

// ======================================================================================================================================

void del_list(struct list_t ** ptrL, void (*ptrFct)() ) {
    assert ( ptrL && * ptrL );

    if( (*ptrFct) != NULL ) {
        for ( struct list_elm_t * E = (* ptrL )->head ; E; ) {
            struct list_elm_t * T = E;
            E = E->suc;
            (*ptrFct) (T->datum );
            free(T);
        }
    } 
    else {
        for ( struct list_elm_t * E = (* ptrL )->head ; E; ) {
            struct list_elm_t * T = E;
            E = E->suc ;
            free(T);
        }
    }
	free (*ptrL);
	(*ptrL) = NULL;
}

// ======================================================================================================================================

bool empty_list(const struct list_t * L ) {
	return (L->numelm == 0);
}

// ======================================================================================================================================

void cons(struct list_t * L, void * datum) { 
	assert (L);
	struct list_elm_t * E = new_list_elm ( datum );
	assert (E);
	
	E->suc = L->head ;
	L->head = E;

	if(L->numelm == 0) 
		L->tail = E;

	L->numelm += 1;

}

// ======================================================================================================================================
void view_list(struct list_t * L, void (* ptrFct)() ) {

	printf( "[ " );
	for( struct list_elm_t * E = L->head; E; E = E->suc) {
		(*ptrFct)(E->datum);
	}
	printf( "]\n\n" );    

} 

// ======================================================================================================================================

void queue ( struct list_t * L , void * datum ) {
    assert(L);

	struct list_elm_t *new_tail = new_list_elm(datum);
	L->tail->suc = new_tail;

    L->numelm += 1;
}

// ======================================================================================================================================

void insert_ordered(struct list_t * L, void * datum, bool (* ptrFct ) ()) {

    assert(L);

    if(empty_list(L)) 
        cons(L, datum);

    else if((*ptrFct)(datum, L->head->datum)) 
        cons(L, datum);
    
    else if((*ptrFct)( L->tail->datum, datum)) 
        queue(L, datum);
    
    else {


        for( struct list_elm_t * E = L->head; E->suc; E = E->suc) {
		    if((*ptrFct)(datum, E->suc->datum)) {
                
                insert_after(L, datum, E);
                break;
            }
	    }


    }
    
}


// ======================================================================================================================================


struct list_elm_t * getHead ( struct list_t * L) {
	assert(L);
    return L->head;
}

// ======================================================================================================================================


struct list_elm_t * getTail ( struct list_t * L) {
    assert(L);
	return L->tail;
}

// ======================================================================================================================================

int getNumelm ( struct list_t * L) {
    assert(L);
	return L->numelm;
}

// ======================================================================================================================================

int setNumelm ( struct list_t * L , int numElm ) {
	assert(L);
    L->numelm = numElm;
    return numElm; 
}

// ======================================================================================================================================

void insert_after(struct list_t * L, void * datum, struct list_elm_t * place) {
    assert(L && place);
    if(place == NULL) 
        cons(L, datum);
    else {
        struct list_elm_t * New = new_list_elm(datum);
        New->suc = place->suc;
        place->suc = New;
    }
}

// ======================================================================================================================================

struct list_t * listcpy(struct list_t *l) {

    struct list_t * lst = new_list();
    lst->numelm = 0;

	for( struct list_elm_t * E = l->head; E; E = E->suc) {
		queue(lst, E->datum);
	}

    return lst;
}