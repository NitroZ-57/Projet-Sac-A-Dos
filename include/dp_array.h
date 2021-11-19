#pragma once

#include "objects.h"

typedef int state_t;

struct states_array_t {
	state_t * OPT;			// Matrice d'états proprement dite
	state_t * CHM;			// Matrice des chemins dans la matrice d'états
	int num_obj, Vmax;	// Dimensions de la matrice d'états
};

// =======================================================================

/**
 * @brief Free the memory of the state array 
 * 
 * @param states the array to free the memory
 */
void free_states_array(struct states_array_t ** states);

// =======================================================================

/**
 * @brief Create a state array and init it at 0
 * 
 * @param num_objects the number of obejcts in the bag
 * @param Vmax the maximum volume of the bag
 * @return the array initialized
 */
struct states_array_t * new_states_array(const int num_objects, const int Vmax);

// =======================================================================

/**
 * @brief add object in a valid state in the state array
 * 
 * @param states the state in which one add the objec
 * @param objects the object with the one to add
 * @param i tje index of the object to add
 */
void push_object_in_array(struct states_array_t * states, const struct objects_t * objects, int i);

// =======================================================================

/**
 * @brief Print the more opti solution
 * 
 * @param states the state array to print
 * @param set all the objects
 */
void view_path_array(const struct states_array_t * states, const struct objects_t * set);

// =======================================================================

/**
 * @brief Print the state array
 * 
 * @param states the state array to show
 */
void view_opt(const struct states_array_t * states);

// =======================================================================

/**
 * @brief Print the paths of the state array
 * 
 * @param states the state array to show the paths
 */
void view_chm(const struct states_array_t * states);