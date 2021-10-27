#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "objects.h"

// =======================================================================

struct objects_t * new_objects(const int argc, char ** argv, bool utility) { /** @todo */
    struct objects_t * set = /** @todo */;
    assert(set);
    int i;
    set->nb_objects = (utility) ? (argc - 4) / 2 : (argc - 4);
    set->objects = /** @todo */;
    if(utility) {
        int j;
        for(i = 3, j = 0; i < argc; i += 2, j += 1) {
        	/** @todo **/
        }
    } else {
        for(i = 3; i < argc; i += 1) {
        	/** @todo **/
        }
    }
    return set;
}

// =======================================================================

void view_object(const struct object_t * object) {
    assert(object);
    printf("(%d , %d) ", object->volume, object->utility);
}

// =======================================================================

void view_objet_set(const struct objects_t * set) {
	printf("\n*** View objet set ***\n");
	for(int o = 0; o < set->nb_objects; o += 1) {
		view_object(set->objects + o);
	}
	printf("\n**********************\n");
}