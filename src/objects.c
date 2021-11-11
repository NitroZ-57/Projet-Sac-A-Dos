#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "objects.h"

// =======================================================================

struct objects_t * new_objects(const int argc, char ** argv, bool utility) { 
    struct objects_t * set = (struct objects_t*)calloc(1, sizeof(struct objects_t)); 
    assert(set);
    int i;
    set->nb_objects = (utility) ? (argc - 4) / 2 : (argc - 4);
    set->objects = (struct object_t*)calloc(set->nb_objects, sizeof(struct object_t)); 
    assert(set);
    if(utility) {
        int j;
        for(i = 4, j = 0; i < argc; i += 2, j += 1) { 
        	set->objects[j].volume = atoi(argv[i]); 
            set->objects[j].utility = atoi(argv[i+1]); 
        }
    } else {
        for(i = 4; i < argc; i += 1) {
        	set->objects[i-3].volume = atoi(argv[i]);
            set->objects[i-3].utility = atoi(argv[i]);
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