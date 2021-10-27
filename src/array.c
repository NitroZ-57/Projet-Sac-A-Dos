#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dp_array.h"
#include "array.h"
#include "objects.h"


void array(const bool utility, const int Vmax, const struct objects_t * objects) {
    struct states_array_t * states = new_states_array(objects->nb_objects, Vmax);
    assert(states != NULL);
    #ifdef _TRACE_
        view_opt(states);
    #endif

    for(int i = 1; i <= objects->nb_objects; i += 1) {
        #ifdef _TRACE_
            printf("#%d Object\n", i);
        #endif
        push_object_in_array(states, objects, i);
        #ifdef _TRACE_
            view_opt(states);
            view_chm(states);
        #endif
    }
    view_path_array(states, objects);
    free_states_array(states);
}
