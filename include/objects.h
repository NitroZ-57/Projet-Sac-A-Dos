struct object_t {
	int volume;
	int utility;
};

// =======================================================================

struct objects_t {
	struct object_t * objects;
	int nb_objects;
	int first_idx;
};

// =======================================================================

struct objects_t * new_objects(const int argc, char ** argv, bool utility);

// =======================================================================

void view_object(const struct object_t * object);

// =======================================================================

void view_objet_set(const struct objects_t * set);
