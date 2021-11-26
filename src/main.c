#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "global.h"
#include "objects.h"
#include "rec.h"
#include "array.h"


int main(int argc, char **argv) {
	/** @brief main parameters are :
  	* - argc : # of parameters
    * - argv : a vector of string ; each one is a parameter (as a string) */
	if (argc < 4) {
		fprintf(stderr, "USAGE\n\tdp Mode(R|A|L) Utilié(0|1) Vmax vol_1, use_1 /** @todo */, vol_n, use_n\n");
		fprintf(stderr, "\t* Mode is\n");
		fprintf(stderr, "\t\t- R for recursive approach,\n");
		fprintf(stderr, "\t\t- A for array approach,\n");
		fprintf(stderr, "\t\t- L for list approach\n");
		fprintf(stderr, "\t* Utilité prend 1 pour des objets avec utilités, 0 sinon\n");
		fprintf(stderr, "\t* Vmax is for bag max volume\n");
		fprintf(stderr, "\t* vol_i is for #i object's volume, i in {1, /** @todo */ , n}");
		fprintf(stderr, "\t* use_i is for #i object's utility, i in {1, /** @todo */ , n}");
		
		return EXIT_FAILURE;
	}

	const char mode = argv[1][0];
	const bool utility = (atoi(argv[2]) == 0) ? false : true;
	const int Vmax = atoi(argv[3]);
	struct objects_t * object_set = new_objects(argc, argv, utility);
	
	#ifdef _TRACE_
		fprintf(stderr, "mode=%c usefullness=%c Vmax=%d\n", mode, (utility)?'U':'N', Vmax);
		fprintf(stderr, "Object set full with %d objects\n", object_set->nb_objects);
		view_objet_set(object_set);
	#endif
	
	
	if(mode == 'R') { 
		struct retained_t * my_bag = new_bag(); 
		rec(Vmax, object_set, my_bag);
		view_bagpack(my_bag, "Final selection");
	} else if(mode == 'A') {
		array(utility, Vmax, object_set);
	} else {
		//dp_list(Vmax, object_set); @todo
	}
	free_object_set(&object_set);

	return EXIT_SUCCESS;
	
}