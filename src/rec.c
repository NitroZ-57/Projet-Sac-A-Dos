#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "global.h"
#include "dp_rec.h"
#include "rec.h"
#include "objects.h"



void rec(const int Vmax, struct objects_t * object_set, struct retained_t * bagpack) {
	const int nb_objects = object_set->nb_objects;
	struct retained_t * duplicata = new_bag(); // on créer un nouveau sac
	bagcpy(duplicata, bagpack); // on copie le sac dans un duplicata
	// Prediction : the bag utility before any new object put into it
	int first = object_set->first_idx;
	struct retained_t * best_bagpack = new_bag(); // on créer un nouveau sac
	bagcpy(best_bagpack, bagpack); // le du début sac est le meilleur
	// Verification by trying the other objects
	for(int obj_idx = first; obj_idx < nb_objects; object_set++) { // on va d'objet en objet en commençant à l'index donné pour éviter de prendre les objets déjà pris
		struct object_t * ptr_object = &object_set->objects[obj_idx]; // on récupère l'objet courrant
		int curr_volume = ptr_object->volume + duplicata->utilities_sum; // on ajoute le volume de l'objet courrant à celui du sac que l'on a déjà
		if(curr_volume <= Vmax) { // on vérifie si le nouveau volume est bien onferieur à celui maximal du sac
			bagcpy(duplicata, bagpack); // on fait un nouveau duplicata 
			push_object_in_bag(duplicata, ptr_object); // on ajoute le nouvel objet dans la liste
			object_set->first_idx = first +1; // on passe à l'objet suivant 
			rec(Vmax, object_set, duplicata); // on continue les appels récursifs avec le nouvel objet ajouté
			if(duplicata->utilities_sum > best_bagpack->utilities_sum) { // on vérifie si l'utilité du nouveau sac est supérieur à l'ancien sac 
				clean_bag(best_bagpack); // on enlève les éléments du meilleur sac
				bagcpy(best_bagpack, bagpack); // on copie le nouveau meilleur sac dans le meilleur sac
			}
			#ifdef _TRACE_
				view_bagpack(best_bagpack, "\nMeilleur bagpack :\n");
			#endif
		}
	}
	clean_bag(bagpack);
	bagcpy(bagpack, best_bagpack);
	free_bag(&best_bagpack);
	free_bag(&duplicata);
}