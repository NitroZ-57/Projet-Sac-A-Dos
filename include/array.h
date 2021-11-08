#pragma once

#include <stdbool.h>
#include "dp_array.h"

// =======================================================================

/**
 * @brief The function for the state array method
 * Find the best bag solution, and print it for each line of the state array
 * 
 * @param utility if the utility is enabled or not 
 * @param Vmax the volume maximum of the bag
 * @param objects all the objects and informations 
 */
void array(const bool utility, const int Vmax, const struct objects_t * objects);
