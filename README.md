# Projet-Sac-A-Dos
Par COMTE Quentin & ZELL Camille

## Pricipe du projet
Un algorithme ayant pour but de ranger plusieurs objets donnés dans un sac. On a la taille du sac à ne pas dépasser ainsi que des informations sur les obejts tel que leur taille et leur utilité. Notre but sera d'avoir le sac ayant l'utilité la plus forte sans dépasser sa capacité maximale.  
Pour se faire nous allons utiliser 3 approches différentes :   
* Une récursive
* Une utilisant des matrices d'états
* Une utilisant des listes gérériques chaînées dynamique

------------------------------------------------------------------

## Utilisation du programme
Le makefile compile et éxécute, donnat les démarches pour lancer l'exécutable avec les paramètres de la fonction main. L'éxécutable se situe dans le dossier `bin`. Il faut créer les fichiers `obj`et `bin` dans le dossier principal.
Pour lancer le programme un fait appel au fichier executable (éxecuter par le makefile) qui est :
    *./nom_programme méthode utilité Volume_max obj_1 ... obj_n*
* Le nom du programme est le programme que l'on souhaite exécuter. 
* méthode est soit `R` pour appeler le programme en récurssif, `A` pour appelé la méthode utilisant les matrices d'états et `L` pour appeler la méthode utilisant les listes générique doublement chaîner ; Si il y a une autre valeur un message d'erreur apparaît.
* Utilité va prendre la valeur 0 ou 1 (valeur booléenne). 0 correspond au fait que l'objet a un volume et une utilité identique . 1 correspond au fait que les objets seront selectionner par paire ; la première valeur correspond au volume et la seconde a l'utilité. Lorsque l'utilité est de 0 il y a n objets, lorsque l'utilité est de 1 il y a n/2 objets.
* Volume_max est le volume du sac.
* obj_1 ... obj_n on écrit les objet sous forme d'entier. On peux écrire de 1 à n objet différent.  

--------------------------------------------------

## Informations sur le code 

Pour simplifier le code et comme il n'y a pas beaucoup de fonctions, la plupart des fonctions sont dans des fichiers d'entête en publique.

### .gitignore
Mettre dans tous les fichiers ou dossiers qui ne doivent pas être envoyés sur github

### Makefile
Le Makefile est finit et fonctionnel, il ne faut pas le modifier. Ne pas oublier de supprimer les fichiers obj et bin avant d'envoyer sur github.  
Commandes :  
- **make** compile et éxécute le programme  
- **make delete** supprime les fichiers obj et bin  

### Fichier main.c
La fonction main ne doit pas être touché, on peut faire une autre fonction main à coté pour faire nos tests  

### Fichier global.h
Ce fichier n'est pas à modifier il permet d'inclure toutes les constantes pour faire le programme

### Fichiers objects.c et objects.h
Ces fichiers contiennent toutes les fonctions utilitaire sur le sac à dos. Le fichier h sera inclu dans presque tous les fichiers  

### Fichiers dp_rec.c et dp_rec.h 
Ces fichiers contiennent toutes les fonctions utilitaire pour la version récursive. Le fichier h sera inclu dans *rec.c* qui contient la fonction récursive finale.  

### Fichiers rec.c et rec.h
Ces fichiers contiennent la fonction récursive, étape 1 du projet.  

### Fichiers dp_array.c et dp_array.h 
Ces fichiers contiennent toutes les fonctions utilitaire pour la version matrice d'états. Le fichier h sera inclu dans *array.c* qui contient la fonction matrice d'états finale.  

### Fichiers array.c et array.h
Ces fichiers contiennent la fonction matrice d'états, étape 2 du projet.  

### Fichiers lst.c et lst.h
Ces fichiers servent à utiliser les listes génériques simplement chaînées pour la version récursive et pour la version avec les listes 

### Fichiers lst_elm.c et lst_elm.h
Ces fichiers servent pour les fichiers *lst.c* et *lst.h* 

---------------------------------------------------------

## Ensemble des structures de données, constantes et types utilisés  

### lst_elm.h
* `struct list_elm_t` : Maillon d'une liste générique simplement chaînée qui contient deux champs, un pointeur vers la donnée `datum` générique (type void) et le succésseur `suc` qui est aussi un maillon d'une liste générique simplement chainée  

### lst.h
* `structu lst_t` : Liste simplement chainée qui contient un nombre d'élément dans la liste `numelm`, la tête de la liste `head` et la queue de la liste `tail`, ces deux dernières sont des maillons d'une liste générique simplement chaînée  

### dp_array.h
* `typedef state_t` : un entier qui correspond à l'état de la matrice (l'utilité de l'objet entre autre), qui est un nombre entier   
* `struct states_array_t` : Matrice d'état qui est composé d'un volume max `Vmax`, du numéro courrant de l'objet `num_obj`. Et aussi un tableau d'état `OPT` ainsi qu'un tableau de chemin pour avoir une trace du programme CHM`   

### dp_rec.h
* `struct retained_t` : un sac retenu avec un entier, la somme de l'utilité des objets du sac et la liste des objets du sac qui est une liste générique simplement chainée   

### global.h
* `INFTY` : état qui correspond à l'état précédent dans la matrice d'état   
* `UNDIR`: état interminé dans la matrice d'état  
* `_TRACE_` : suivis de chemin pour savoir ce qu'il se passe dans le programme, possibilité de l'enlever  

### objects.h
* `struct object_t` : Correspond à un objet du sac avec le volume de l'objet en question et son utilité   
* `struct objects_t` : L'ensemble des objets donnés avec le nombre d'objet total `nb_objects`, l'indice du premier objet pour la version récursive dans `first_index` et un tableau d'objets `objects`    

---------------------------------------------------------  

## Tableau des fonction du programme

| NOM FONCTION  | NOM FICHIER | LIGNE .h | UTILITÉ | ETAT |
|:------------|:------------|:------------:|:------------|:------------|
|`array()`|*array*|17|cherche la meilleure solution pour le sac et l'affiche méthode matrice d'état|Donnée|
|`rec()`|*rec*|16|cherche la meilleure solution pour le sac et l'affiche méthode récursive|Fonctionnelle|
|`free_states_array()`|*dp_array*|20|libère la mémoire d'une matrice d'état|Fonctionelle|
|`new_states_array()`|*dp_array*|31|crée une matrice d'état initialisée a 0|à tester|
|`push_object_in_array()`|*dp_array*|42|ajoute un objet valide dans la matrice d'état|Fonctionelle|
|`view_path_array()`|*dp_array*|52|affiche la meilleure solution optimiser|Donnée|
|`view_opt()`|*dp_array*|61|affiche la matrice d'état|Donnée|
|`view_chm()`|*dp_array*|70|affiche le chemin de la matrice d'état|Donnée|
|`ìnit_opt_chm()`|*dp_array*|131 (fichier c)|initialise le chemin de la matrice d'état|Fonctionelle|
|`new_bag()`|*dp_rec*|22|crée un nouveau sac et l'initialise a 0|Fonctionnelle|
|`bagcpy()`|*dp_rec*|32|copie un sac dans un autre|Donnée|
|`free_bag()`|*dp_rec*|41|libère la mémoire d'un sac|Fonctionnelle|
|`clean_bag()`|*dp_rec*|50|enlève tous les objet dans un sac|Fonctionnelle|
|`push_object_in_bag()`|*dp_rec*|60|ajoute un nouvel objet au sac|Fonctionnelle|
|`view_bagpack()`|*dp_rec*|70|affiche un sac|Donnée|
|`new_objects()`|*objects*|39|crée un ensemble d'objet à partir des objets donné par l'utilisateur|Fonctionnel|
|`view_object()`|*objects*|48|affiche un objet|Donnée|
|`view_object_set()`|*objects*|57|affiche un ensemble d'objets|Donnée|
|`void free_object()`|*objects*|66|Libère la mémoire utilisé pour un seul objet|Fonctionnelle|
|`free_object_set()`|*objects*|75|libère la mémoire de l'ensemble d'objets|Fonctionnelle|

+ Les fonctions dans *lst_elm.h* qui sont des fonctions manipulants les maillons de listes génériques simplement chaînées et les fonctions dans *lst.h*  qui sont les fonctions manipulant les maillins de listes génériques simplement chaînées