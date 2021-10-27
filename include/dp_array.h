
typedef int state_t;

struct states_array_t {
  state_t * OPT;			// Matrice d'états proprement dite
  state_t * CHM;			// Matrice des chemins dans la matrice d'états
  int num_obj, Vmax;	// Dimensions de la matrice d'états
};

// =======================================================================

// Libérer la mémoire occupée par lamatrice d'états
void free_states_array(struct states_array_t * states);

// =======================================================================

// Créer une matrice d'états ET l'initialiser à "vide"
struct states_array_t * new_states_array(const int num_objects, const int Vmax);

// =======================================================================

// Ajouter un objet dans les états "valides" de la matrice
void push_object_in_array(struct states_array_t * states, const struct objects_t * objects, int i);

// =======================================================================

// Visualiser la solution optimale
void view_path_array(const struct states_array_t * states, const struct objects_t * set);

// =======================================================================

// Visualiser la matrice d'états
void view_opt(const struct states_array_t * states);

// =======================================================================

// Visualiser les chemins associés aux états de la matrice d'états
void view_chm(const struct states_array_t * states);