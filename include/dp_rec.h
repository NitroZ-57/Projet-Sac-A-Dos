#pragma once

/**
 * @brief the structure with all the objects in a retained bag, with their utility sum
 * 
 */
struct retained_t {
	// All the objects in the retained bag
	struct list_t * objects_list;
	// The retained objects utility sum
	int utilities_sum;
};

// =======================================================================
/**
 * @brief Create a new bag and init it at 0
 * 
 * @return The new bag 
 */
struct retained_t * new_bag();

// =======================================================================

/**
 * @brief Copy a bag in an other
 * 
 * @param newbagpack the bag create with the other
 * @param bagpack the reference bag
 */
void bagcpy(struct retained_t * newbagpack, const struct retained_t * bagpack);

// =======================================================================

/**
 * @brief Free the memory of a bag
 * 
 * @param bagpack the bag to free the memory
 */
void free_bag(struct retained_t * bagpack);

// =======================================================================

/**
 * @brief Clean all obejcts in the bag
 * 
 * @param bagpack the bag to clean
 */
void clean_bag(struct retained_t * bagpack);

// =======================================================================

/**
 * @brief Add an object in the bag
 * 
 * @param bagpack the bag to add the object
 * @param ptr_object the object to add in the bag
 */
void push_object_in_bag(struct retained_t * bagpack, struct object_t * ptr_object);

// =======================================================================

/**
 * @brief Print a bag
 * 
 * @param bagpack the bag to show
 * @param title a string to print before the bag
 */
void view_bagpack(struct retained_t * bagpack, const char * title);