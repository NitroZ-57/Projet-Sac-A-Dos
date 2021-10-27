#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dp_rec.h"
#include "objects.h"


struct retained_t * new_bag() {
	struct retained_t * bagpack = /** @todo */;
	assert(bagpack);
	bagpack->objects_list = /** @todo */;
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

void free_bag(struct retained_t * bagpack) {
	assert(bagpack);
	/** @todo **/
}

// =======================================================================

void clean_bag(struct retained_t * bagpack) {
	assert(bagpack);
	/** @todo **/
}

// =======================================================================

void push_object_in_bag(struct retained_t * bagpack, struct object_t * ptr_object) { /** @todo **/ }

// =======================================================================

void view_bagpack(struct retained_t * bagpack, const char * title) {
	void (* ptr_view_fct) (const struct object_t *) = &view_object;
	printf("\n*****************\nVIEW BAGPACKAGING\t%s\n", title);
	view_list(bagpack->objects_list, ptr_view_fct);
	printf("\t\tWith utilities sum = %d\n\n", bagpack->utilities_sum);
}
