#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "global.h"
#include "dp_rec.h"
#include "objects.h"
#include "lst.h"

struct retained_t * new_bag() {
	struct retained_t * bagpack = ( struct retained_t *) calloc (1, sizeof ( struct retained_t) ); // allocation dynamique d'un struct retained_t
	assert(bagpack);
	bagpack->objects_list = new_list(); // allocation dynamique d'une liste (dans lst.h)
	assert(bagpack->objects_list);
	return bagpack;
}

// =======================================================================

void bagcpy(struct retained_t * newbagpack, const struct retained_t * bagpack) {
	assert(newbagpack && bagpack);
	newbagpack->objects_list = listcpy(bagpack->objects_list);
	newbagpack->utilities_sum = bagpack->utilities_sum;
}

// =======================================================================

void free_bag(struct retained_t ** bagpack) {
	assert(*bagpack);
	//supprime la liste d'objet
	del_list( &((*bagpack)->objects_list), &free_object );
	// libère le bagpack
	free (*bagpack);

	//le pointeur du pointeur a NULL
	(*bagpack) = NULL;
}

// =======================================================================

void clean_bag(struct retained_t * bagpack) {
	assert(bagpack);
	
	//suppression de la liste
	del_list( &bagpack->objects_list, &free_object );

	//new list ds list de la struct
	bagpack->objects_list = new_list();

	//met la somme des utilité a 0
	bagpack->utilities_sum = 0;
}

// =======================================================================

void push_object_in_bag(struct retained_t * bagpack, struct object_t * ptr_object) { 
	assert(bagpack && ptr_object);

	//ajoute l'objet a la suite de la liste
	cons( bagpack->objects_list , ptr_object );
	
	//ajoute l'utilité de l'objet a l'utilité exitante du sac
	bagpack->utilities_sum += ptr_object->utility ;

}

// =======================================================================

void view_bagpack(struct retained_t * bagpack, const char * title) {
	void (* ptr_view_fct) (const struct object_t *) = &view_object;
	printf("\n*****************\nVIEW BAGPACKAGING\t%s\n", title);
	view_list(bagpack->objects_list, ptr_view_fct);
	printf("\t\tWith utilities sum = %d\n\n", bagpack->utilities_sum);
	
}
