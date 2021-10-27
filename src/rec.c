#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dp_rec.h"
#include "rec.h"
#include "objects.h"



void rec(const int Vmax, struct objects_t * object_set, struct retained_t * bagpack) {
	const int nb_objects = object_set->nb_objects;
	struct retained_t * duplicata = /** @todo */;
	bagcpy(/** @todo */);
	// Prediction : the bag utility before any new object put into it
	int first = object_set->first_idx;
	struct retained_t * best_bagpack = /** @todo */;
	bagcpy(/** @todo */);
	// Verification by trying the other objects
	for(int obj_idx /** @todo */) {
		struct object_t * ptr_object = /** @todo */;
		int curr_volume = /** @todo */;	
		if(/** @todo */) {
			bagcpy(/** @todo */);
			push_object_in_bag(/** @todo */);
			object_set->first_idx = /** @todo */;
			p_rec(/** @todo */);
			if(/** @todo */) {
				clean_bag(/** @todo */);
				bagcpy(/** @todo */);
			}
		}
	}
	clean_bag(bagpack);
	bagcpy(bagpack, best_bagpack);
	free_bag(best_bagpack);
	free_bag(duplicata);
}