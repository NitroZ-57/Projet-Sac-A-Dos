#pragma once

/**
 * @brief The structure of one object with it volume and it utility
 * 
 */
struct object_t {
	// the volume of the current object
	int volume;
	// the utility of the current object
	int utility;
};

// =======================================================================

/**
 * @brief The array of items, the number of item and the first index of the objects
 * 
 */
struct objects_t {
	// the objects array
	struct object_t * objects;
	// the number of objects in the array
	int nb_objects;
	// the first index for the objects
	int first_idx;
};

// =======================================================================

/**
 * @brief Creation of a new set of objects with the main function args
 * 
 * @param argc the arg counter of the main args
 * @param argv the main args in a string
 * @param utility if the utility is enabled or not
 * @return the set objects created 
 */
struct objects_t * new_objects(const int argc, char ** argv, bool utility);

// =======================================================================

/**
 * @brief Print an obeject
 * 
 * @param object the object to sho<
 */
void view_object(const struct object_t * object);

// =======================================================================

/**
 * @brief Print a set of objects
 * 
 * @param set the set to show
 */
void view_objet_set(const struct objects_t * set);

// =======================================================================

/**
 * @brief Free a object 
 * 
 * @param obj the object to free
 */
void free_object(struct object_t ** obj);

// =======================================================================

/**
 * @brief Free an object set  
 * 
 * @param set the set to free
 */
void free_object_set(struct objects_t ** set);