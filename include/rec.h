#pragma once

#include "dp_rec.h"
#include "objects.h"

// =======================================================================

/**
 * @brief The function for the recursive method
 * Find the best bag solution, and print it for each function call
 * 
 * @param Vmax the volume maximum of the bag
 * @param object_set all the objects and informations 
 * @param bagpack the bag pack that is supposed to be the best
 */
void rec(const int Vmax, struct objects_t * object_set, struct retained_t * bagpack);
