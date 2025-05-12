# Correcteur Orthographique

Un correcteur orthographique qui suggère des corrections pour les mots mal orthographiés dans un fichier texte.

## Description

Ce projet implémente un correcteur orthographique capable de détecter et de suggérer des corrections pour les mots mal orthographiés dans un fichier texte donné. Il utilise différentes structures de données comme l'ATR (Arbre de Recherche Ternaire) et l'Arbre BK pour stocker et rechercher efficacement des mots dans un dictionnaire. Le projet propose trois versions différentes du correcteur, chacune utilisant des approches différentes pour la détection et la correction d'erreurs.

## Structure du projet

```
sophiescn-correcteur/
├── ATR.c            # Implémentation de l'Arbre de Recherche Ternaire
├── ATR.h            # Fichier d'en-tête pour l'ATR
├── ArbreBK.c        # Implémentation de l'Arbre BK
├── ArbreBK.h        # Fichier d'en-tête pour l'Arbre BK
├── Liste.c          # Implémentation de la structure de Liste
├── Liste.h          # Fichier d'en-tête pour la Liste
├── a_corriger_0.txt # Fichier texte à corriger (fichier test 0)
├── a_corriger_1.txt # Fichier texte à corriger (fichier test 1)
├── correcteur.c     # Implémentation des fonctions de correction
├── correcteur.h     # Fichier d'en-tête pour les fonctions de correction
├── correcteur_0.c   # Fichier principal pour la première version utilisant ATR
├── correcteur_1.c   # Fichier principal pour la deuxième version utilisant ATR et force brute
├── correcteur_2.c   # Fichier principal pour la troisième version utilisant l'Arbre BK
├── dico_1.dico      # Fichier dictionnaire 1
├── dico_2.dico      # Fichier dictionnaire 2
├── dico_3.dico      # Fichier dictionnaire 3
├── levenshtein.c    # Implémentation de l'algorithme de distance de Levenshtein
├── levenshtein.h    # Fichier d'en-tête pour la distance de Levenshtein
├── makefile         # Makefile pour compiler le projet
├── ouverture.c      # Implémentation des fonctions de lecture de fichier et validation d'arguments
└── ouverture.h      # Fichier d'en-tête pour la lecture de fichier et validation d'arguments
```

## Utilisation

Pour compiler le projet, utilisez la commande `make`. Cela générera trois fichiers exécutables : `correcteur_0`, `correcteur_1` et `correcteur_2`.

Chaque exécutable prend deux arguments : le fichier dictionnaire et le fichier texte à corriger. Par exemple :

```bash
./correcteur_0 dico_1.dico a_corriger_0.txt
./correcteur_1 dico_1.dico a_corriger_0.txt
./correcteur_2 dico_2.dico a_corriger_1.txt
```

## Versions du correcteur

### Correcteur 0

Cette version utilise un Arbre de Recherche Ternaire (ATR) pour vérifier les mots mal orthographiés. Elle identifie les mots mal orthographiés et les affiche dans la console.

### Correcteur 1

Cette version utilise un Arbre de Recherche Ternaire (ATR) pour identifier les mots mal orthographiés, puis utilise une approche force brute avec la distance de Levenshtein pour suggérer des corrections à partir du dictionnaire.

### Correcteur 2

Cette version utilise un Arbre BK pour identifier les mots mal orthographiés et suggérer des corrections basées sur la distance de Levenshtein.

## Structures de données

### Arbre de Recherche Ternaire (ATR)

- Implémenté dans ATR.c et ATR.h.
- Utilisé pour un stockage et une recherche efficaces des mots dans le dictionnaire.

### Arbre BK

- Implémenté dans ArbreBK.c et ArbreBK.h.
- Utilisé pour stocker le dictionnaire et trouver des corrections candidates basées sur la distance de Levenshtein.

### Liste

- Implémentée dans Liste.c et Liste.h.
- Utilisée pour stocker des listes de mots, comme les mots mal orthographiés ou les corrections suggérées.

## Algorithmes

### Distance de Levenshtein

- Implémentée dans levenshtein.c et levenshtein.h.
- Utilisée pour calculer la distance d'édition entre deux mots, ce qui est utilisé pour suggérer des corrections.

## Fichiers principaux

### correcteur_0.c

- Fichier principal pour la première version du correcteur orthographique.
- Initialise un ATR à partir du fichier dictionnaire et une liste à partir du fichier texte à corriger.
- Utilise la fonction de correction de correcteur.c pour identifier les mots mal orthographiés.

### correcteur_1.c

- Fichier principal pour la deuxième version du correcteur orthographique.
- Utilise un ATR pour identifier les mots mal orthographiés.
- Utilise une approche force brute avec la distance de Levenshtein pour suggérer des corrections.

### correcteur_2.c

- Fichier principal pour la troisième version du correcteur orthographique.
- Utilise un Arbre BK pour identifier les mots mal orthographiés et suggérer des corrections.

### correcteur.c

- Contient la fonction de correction qui identifie les mots mal orthographiés en utilisant soit un ATR, soit un Arbre BK.
- Contient également la fonction force_brute qui suggère des corrections en utilisant une approche force brute et la distance de Levenshtein.
- La fonction correction_BK est utilisée pour trouver des corrections basées sur l'Arbre BK.

### ouverture.c

- Contient des fonctions pour lire des fichiers et valider les arguments de ligne de commande.
- lecture_fichier lit le contenu d'un fichier dans une chaîne de caractères.
- arguments_valides valide les arguments de ligne de commande, en s'assurant que le fichier dictionnaire est fourni.

### makefile

- Makefile pour compiler le projet.
- Spécifie le compilateur (CC), les options du compilateur (CFLAGS) et les dépendances entre les fichiers.

## Auteurs

- Quentin Benesby
- Sophie Cousson
