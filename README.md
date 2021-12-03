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
Pour lancer le programme un fait appel au fichier executable (éxecuter par le makefile) qui est :
    *./nom_programme méthode utilité Volume_max obj_1 ... obj_n*
* Le nom du programme est le programme que l'on souhaite exécuter. 
* méthode est soit `R` pour appeler le programme en récurssif, `A` pour appelé la méthode utilisant les matrices d'états et `L` pour appeler la méthode utilisant les listes générique doublement chaîner ; Si il y a une autre valeur un message d'erreur apparaît.
* Utilité va prendre la valeur 0 ou 1 (valeur booléenne). 0 correspond au fait que l'objet a un volume et une utilité identique . 1 correspond au fait que les objets seront selectionner par paire ; la première valeur correspond au volume et la seconde a l'utilité. Lorsque l'utilité est de 0 il y a n objets, lorsque l'utilité est de 1 il y a n/2 objets.
* Volume_max est le volume du sac.
* obj_1 ... obj_n on écrit les objet sous forme d'entier. On peux écrire de 1 à n objet différent.

--------------------------------------------------

## TODO
- [X] : Faire les fonctions pour le sac dans `objects.h` et `objects.c`
- [X] : Faire les fonctions dont dépend la fonction récursive `dp_rec.h` et `dp_rec.c`
- [x] : Faire la fonction récursive `rec.h` et `rec.c`
- [X] : Faire les fonctions dont dépend la fonction de matrice d'états `dp_array.h` et `dp_array.c`  
- [X] : Faire la fonction de matrice d'états `push_object_in_array()` dans `dp_array.h` et `dp_array.c   
- [ ] : Faire les fonctions dont dépend la fonction de listes gérériques chaînées dynamique `dep_array.h` et `dep_array.c`  
- [ ] : Faire la fonction de listes gérériques chaînées dynamique `push_object_in_array()` dans `dy_dyn.h` et `dp_dyn.c   

- [ ] : Refaire tout le tableau des fonctions

--------------------------------------------------

## TO TEST
- [X] : Tester les fonctions pour le sac dans `objects.h` et `objects.c`
- [X] : Tester les fonctions dont dépend la fonction récursive `dp_rec.h` et `dp_rec.c`
- [X] : Tester la fonction récursive `rec.h` et `rec.h`
- [X] : Tester les fonctions dont dépend la fonction de matrice d'états `dp_array.h` et `dp_array.c`
- [X] : Tester la fonction de matrice d'états `array.h` et `array.h`
- [ ] : Tester les fonctions dont dépend la fonction de listes gérériques chaînées dynamique `dep_array.h` et `dep_array.c`  
- [ ] : Tester la fonction de listes gérériques chaînées dynamique `push_object_in_array()` dans `dy_dyn.h` et `dp_dyn.c  


--------------------------------------------------

## Informations sur le code 

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

### Fichiers dyn.c et dyn.h
Ces fichiers contiennent la fonction de listes gérériques chaînées dynamique, étape 3 du projet.   

### Fichiers dp_dyn.c et dp_dyn.h
Ces fichiers contiennent toutes les fonctions utilitaire pour la version listes gérériques chaînées dynamique. Le fichier h sera inclu dans *dyn.c* qui contient la fonction de listes gérériques chaînées dynamique.  

---------------------------------------------------------

## Tableau des fonction du programme

| NOM FONCTION  | NOM FICHIER | LIGNE .h | UTILITÉ | ETAT |
|:---------|:---------|:---------|:---------|:---------|
|`array()`|*array*|16|cherche la meilleure solution pour le sac et l'affiche|prof|
|`free_states_array()`|*dp_array*|18|libère la mémoire de la matrice d'état|à tester|
|`new_states_array()`|*dp_array*|29|crée une matrice d'état initialisée a 0|à tester|
|`push_object_in_array()`|*dp_array*|40|ajoute un objet valide dans la matrice d'état|à faire|
|`view_path_array()`|*dp_array*|50|affiche la meilleure solution optimiser|prof|
|`view_opt()`|*dp_array*|59|affiche la matrice d'état|prof|
|`view_chm()`|*dp_array*|68|affiche "the path" de la matrice d'état|prof|
|`ìnit_opt_chm()`|*dp_array*|131 (fichier c)|initialise le chemin de la matrice d'état|à tester|
|`new_bag()`|*dp_rec*|20|crée un nouveau sac et l'initialise a 0|à faire|
|`bagcpy()`|*dp_rec*|30|copie un sac dans un autre|prof|
|`free_bag()`|*dp_rec*|39|libère la mémoire d'un sac|à faire|
|`clean_bag()`|*dp_rec*|48|enlève tout les objet du sac|à faire|
|`push_object_in_bag()`|*dp_rec*|58|ajoute un objet au sac|à faire|
|`view_bagpack()`|*dp_rec*|68|affiche un sac|prof|
|`new_objects()`|*objects*|39|crée un set d'objet|à tester|
|`view_object()`|*objects*|48|affiche un objet|prof|
|`view_object_set()`|*objects*|57|affiche un set d'objet|prof|
|`free_object_set()`|*objects*|66|libère la mémoire de l'ensemble d'objets|à tester|
|`rec()`|*rec*|16|fonction pour recursive = trouve meilleure solution et affiche a chaque appel|à tester|
