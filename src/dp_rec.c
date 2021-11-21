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

void bagcpy(struct retained_t * duplicata, const struct retained_t * bagpack) {
	assert(duplicata && bagpack);
	duplicata->objects_list = listcpy(bagpack->objects_list);
	duplicata->utilities_sum = bagpack->utilities_sum;
}

// =======================================================================

void free_bag(struct retained_t ** bagpack) {
	assert(bagpack);
	/** @todo **/


	(*bagpack)->utilities_sum = 0;
	free (bagpack);
	(*bagpack) = NULL;
	// libérer un à un les éléments de objects_list et mettre utilities_sum à 0, puis libérer le bagpack, enfin faire pointer le pointeur à NULL
}

// =======================================================================

void clean_bag(struct retained_t * bagpack) {
	assert(bagpack);
	
	//suppression de la liste
	del_list( &bagpack->objects_list, &free_object );

	//new list ds list de la struct
	bagpack->objects_list = new_list() ;

	bagpack->utilities_sum = 0;
	// enlever tous les éléments de objects_list en mettant les pointeurs à NULL un à un, et mettre la somme des utilités à 0
}

// =======================================================================

void push_object_in_bag(struct retained_t * bagpack, struct object_t * ptr_object) { 
	/** @todo **/
	//dans objet.h
	/*on veux ajouter objet dans bagpack
	cons list; datum = object.volume
	//ajoute l'objet a la suite de la liste objects_list*/&
	assert(bagpack && ptr_object);
	
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
