# Projet-Sac-A-Dos
Par COMTE Quentin & ZELL Camille

## Pricipe du projet
Un algorithme ayant pour but de ranger plusieurs objets donnés dans un sac. On a la taille du sac à ne pas dépasser ainsi que des informations sur les obejts tel que leur taille et leur utilité. Notre but sera d'avoir le sac ayant l'utilité la plus forte sans dépasser sa capacité maximale.  
Pour se faire nous allons utiliser 3 approches différentes :   
* Une récursive
* Une utilisant des tableaux dynamiques statiques
* Une utilisant des listes dynamiques dynamique

--------------------------------------------------

## Question au prof
1. Pour les objets est-ce que l'on doit faire des variables dynamiques ? Si oui, on libère quand la mémoire ?   

2. Dans les boucles pour dans la fonction pour créer les objets, doit-on commencer par 4 plutot que 3 pour commencer à ranger les objets car 0 est le nom de la fonction, 1 la méthode à effectuer, 2 si on a ou non une utilité et le 3 le volume maximum du sac ?  

--------------------------------------------------

## TODO
- [X] : Faire les fonctions pour le sac dans `objects.h` et `objects.c`
- [ ] : Faire les fonctions dont dépendent les fonctions récursives `dep_rec.h` et `dep_rec.c`
- [ ] : Faire la fonction récursive `rec.h` et `rec.h`
- [ ] : Faire les fonctions dont dépendent les fonctions de tableau dynamique statique `dep_array.h` et `dep_array.c`
- [ ] : Faire la fonction de tableau dynamique statique `array.h` et `array.h`

--------------------------------------------------

## TO TEST
- [ ] : Tester les fonctions pour le sac dans `objects.h` et `objects.c`
- [ ] : TESTER les fonctions dont dépendent les fonctions récursives `dep_rec.h` et `dep_rec.c`
- [ ] : Tester la fonction récursive `rec.h` et `rec.h`
- [ ] : Tester les fonctions dont dépendent les fonctions de tableau dynamique statique `dep_array.h` et `dep_array.c`
- [ ] : Tester la fonction de tableau dynamique statique `array.h` et `array.h`

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
Ce fichier n'est pas à modifier il permet d'inclure tous les fichiers dont la fonction main aura besoin  

### Fichiers objects.c et objects.h
Ces fichiers contiennent toutes les fonctions utilitaire sur le sac à dos. Le fichier h sera inclu dans presque tous les fichiers  

### Fichiers dp_rec.c et dp_rec.h 
Ces fichiers contiennent toutes les fonctions utilitaire pour la version récursive. Le fichier h sera inclu dans *rec.c* qui contient la fonction récursive finale.  

### Fichiers rec.c et rec.h
Ces fichiers contiennent la fonction récursive, étape 1 du projet.  

### Fichiers dp_array.c et dp_array.h 
Ces fichiers contiennent toutes les fonctions utilitaire pour la version tableau dynamique statique. Le fichier h sera inclu dans *array.c* qui contient la fonction tableau dynamique statique finale.  

### Fichiers array.c et array.h
Ces fichiers contiennent la fonction tableau dynamique statique, étape 2 du projet.  


prout