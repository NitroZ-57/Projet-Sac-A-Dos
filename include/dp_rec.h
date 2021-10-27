
/**
 * abstract type to record objects put in the bag until now
**/
struct retained_t {
	struct list_t * objects_list;
	int utilities_sum;
};

// =======================================================================

struct retained_t * new_bag();

// =======================================================================

void bagcpy(struct retained_t * newbagpack, const struct retained_t * bagpack);

// =======================================================================

void free_bag(struct retained_t * bagpack);

// =======================================================================

void clean_bag(struct retained_t * bagpack);

// =======================================================================

void push_object_in_bag(struct retained_t * bagpack, struct object_t * ptr_object);

// =======================================================================

void view_bagpack(struct retained_t * bagpack, const char * title);