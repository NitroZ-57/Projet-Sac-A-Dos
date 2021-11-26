#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "global.h"
#include "dp_array.h"
#include "array.h"
#include "objects.h"

// Private function 

void init_opt_chm(struct states_array_t * states);



// =======================================================================

void free_states_array(struct states_array_t ** states) { 
	assert(*states);

	free((*states)->OPT); // on libère la mémoire de la matrice d'état
	free((*states)->CHM); // on libère la mémoire du chemin de la matrice d'état
	free(*states); // on libère la structure des informations de la structure d'état
	(*states) = NULL; // on fait pointer le pointeur vers rien

}

// =======================================================================

struct states_array_t * new_states_array(const int num_objects, const int Vmax) { 
	struct states_array_t * NS = (struct states_array_t *)calloc(1, sizeof(struct states_array_t)); // allocation dynamique d'une structure des informations de  matrice d'état
	assert(NS != NULL);

	NS->num_obj = num_objects; // on initialise le nombre d'objet
	NS->Vmax = Vmax; // on initialise le volume maximum

	init_opt_chm(NS);
	return NS;
}

// =======================================================================

void push_object_in_array(struct states_array_t * states, const struct objects_t * set, const int i) { /** @todo */
  for(int bag = 0; bag < (states->Vmax +1 ); bag += 1) {
 		// Pour l'objet courant (i-1), parcourir chaque état du sac-à-dos
 		// Identifier cet état pour l'étape précédente (i-1)
 		// Identifier cet état pour l'étape courante (i)
    int pred = (i-1) * states->Vmax + bag; // valeur à la même colonne et la ligne du dessus
    int curr = i * states->Vmax + bag; // valeur à la même colonne et même ligne
    int OPT1 = set->objects[pred].utility;
    states->CHM[curr] = INFTY; //hyp.: l'object i n'est pas dans le sac
    if( bag >= set->objects[curr].volume ) { // Il faut s'assurer qu'il y a de la place dans le sac
      int pred_without_i = bag - set->objects[curr].volume; // volume - volume de l'objet courrant
			int OPT2 = set->objects[curr].utility + states[i-1 *bag - set->objects[cur].volume]; // ligne du dessus et volume - volume de l'obejt courrant
			if( OPT1 > OPT2 ) { // Sélectionne le max entre OPT1 et OPT2
				states->OPT[curr] = OPT1; //l'objet précédent est meilleur solution
				states->CHM[curr] = OPT1; // Noter que l'object i est dans le sac
			} else {
				states->OPT[curr] = OPT2; 
			}
    } else {
        states->OPT[curr] = OPT1 ; // on met la valeur qui se trouve dans pred
    }
  }
}

// =======================================================================

void view_path_array(const struct states_array_t * states, const struct objects_t * set) {
    int obj = states->num_obj;
    int vol = states->Vmax;
    int idx = obj * (states->Vmax + 1) + vol;
    bool nonstop = (obj == 0);
    printf("*********\nTotal packaging utility : %d\n*********\n", states->OPT[idx]);
	while(nonstop) {
    if(states->CHM[idx] != INFTY) { // object actually put in bag
				printf("\tobjet #%d(%d, %d)\n", obj, set->objects[obj-1].volume, set->objects[obj-1].utility);
				nonstop = (states->CHM[idx] == 0);
				vol = states->CHM[idx];
			}
			obj -= 1;
			nonstop = nonstop || (obj == 0);
			idx = obj * (states->Vmax + 1) + vol;
    }
    printf("\n");
}

// =======================================================================

void view_opt(const struct states_array_t * states) {
  printf("OPT |\t");
	for(int bag = 0; bag < (states->Vmax + 1); bag += 1) printf("%2d\t", bag);
	printf("\n----|");
	for(int bag = 0; bag < (states->Vmax + 1); bag += 1) printf("--------");
	printf("\n");
	for(int obj = 0; obj < (states->num_obj + 1); obj += 1) {
		printf("%3d |\t", obj);
		for(int bag = 0; bag < (states->Vmax + 1); bag += 1) {
			int idx = obj * (states->Vmax + 1) + bag;
			if(states->OPT[idx] == INFTY) {
				printf("INF\t");
			} else if(states->OPT[idx] == UNDTR) {
				printf("UND\t");
			} else {
				printf("%2d\t", states->OPT[idx]);
			}            
		}
		printf("\n");
	}
	printf("\n");
}

// =======================================================================

void view_chm(const struct states_array_t * states) {
	printf("CHM |\t");
	for(int bag = 0; bag < (states->Vmax + 1); bag += 1) printf("%2d\t", bag);
	printf("\n----|");
	for(int bag = 0; bag < (states->Vmax + 1); bag += 1) printf("--------");
	printf("\n");
	for(int obj = 0; obj < (states->num_obj + 1); obj += 1) {
		printf("%3d |\t", obj);
		for(int bag = 0; bag < (states->Vmax + 1); bag += 1) {
			int idx = obj * (states->Vmax + 1) + bag;
			if(states->CHM[idx] == INFTY) {
				printf("PRE\t");
			} else if(states->CHM[idx] == UNDTR) {
				printf("UND\t");
			} else {
				printf("%2d\t", states->CHM[idx]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

// =======================================================================

void init_opt_chm(struct states_array_t * states) {
    states->OPT = (state_t *)calloc(states->num_obj * states->Vmax, sizeof(state_t)); // on alloue dynamiquement la matrice d'état;
    states->CHM = (state_t *)calloc(states->num_obj * states->Vmax, sizeof(state_t)); // on alloue dynamiquement les chemins de la matrice d'état

    for( int obj = 1; obj <= states->num_obj; obj += 1) {
        for(int bag = 0; bag <= states->Vmax; bag += 1) {
            int idx = obj*states->Vmax + bag; // trouver l'indice de où enregistrer une valeur dans un vecteur à partir de deux indices (ligne, colonne) d'une matrice d'état
            states->OPT[idx] = UNDTR;
            states->CHM[idx] = UNDTR;
        }
    }
    for(int bag = 0; bag <= states->Vmax; bag += 1) {
        states->CHM[bag] = UNDTR;
    }
}