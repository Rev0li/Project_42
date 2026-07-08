# Project_42

Ce dépôt regroupe mes projets réalisés dans le cadre du **Common Core** de l'école 42 (campus 42 Lyon), de novembre 2024 à juin 2025, ainsi que quelques ateliers et outils annexes.

## Structure du dépôt

```
.
├── Milestone_1/    Débuts du cursus : système, parsing, formatage
├── Milestone_2/    Projets graphiques et algorithmiques
├── Milestone_3/    Programmation système avancée (threads/mutex)
├── ult_lib/        Ma bibliothèque C personnelle (équivalent libft)
├── template/       Squelette de projet (Makefile + arborescence type)
└── workshop/       Atelier Test Driven Development (42 Lyon)
```

Les dossiers `Milestone_*` suivent globalement l'ordre de progression du cursus.

## Milestone 1

| Projet | Description | Statut |
|---|---|---|
| **born2root** | Administration système : installation et durcissement d'une VM (Debian, partitions LVM chiffrées, SSH, UFW/pare-feu, sudo, cron de monitoring). Projet réalisé sur machine virtuelle, sans code versionné ici. | Mandatory |
| **getnextline** | Lecture d'un fichier ligne par ligne, quel que soit le descripteur de fichier ou la taille du buffer. | Mandatory + Bonus (multi-fd) |
| **printf** | Réimplémentation de `printf` (`ft_printf`) gérant les conversions `%c %s %p %d %i %u %x %X %%`. | Mandatory |

## Milestone 2

| Projet | Description | Statut |
|---|---|---|
| **fdf** | Wireframe 3D : rendu isométrique d'une carte de altitudes (fichier `.fdf`) via la **MiniLibX** (vendue en dépendance locale), avec mise à l'échelle automatique de la fenêtre. | Mandatory |
| **pipex** | Réimplémentation d'un pipe shell (`cmd1 | cmd2`) en C : `fork`, `dup2`, `execve` et recherche du binaire dans le `PATH`. | Mandatory |
| **push_swap** | Tri d'une pile d'entiers avec un jeu d'instructions restreint (`sa`, `pb`, `ra`, `rr`, ...), en minimisant le nombre d'opérations via un algorithme de tri par lots (chunks). Inclut le `checker` bonus qui valide qu'une séquence d'instructions trie effectivement la pile. | Mandatory + Bonus (checker) |

## Milestone 3

| Projet | Description | Statut |
|---|---|---|
| **philo** (Philosophers) | Simulation du dîner des philosophes en C avec `pthread` : threads, mutex par fourchette, surveillance de la famine (`time_to_die`) et détection de fin de simulation. | Mandatory |

## ult_lib

Bibliothèque C personnelle (équivalent d'un libft), développée au fil du cursus et réutilisée (recompilée localement) dans **fdf**, **pipex** et **philo**. Elle regroupe des utilitaires classiques : `is_*`, conversions, manipulation mémoire, chaînes de caractères, listes chaînées, `get_next_line` et `ft_printf`.

## template

Squelette de projet minimal (Makefile + arborescence `include/`/`src/`) utilisé comme point de départ pour démarrer rapidement un nouveau projet 42.

## workshop

Atelier **Test Driven Development** (42 Lyon) : trois exercices en C (thermomètre, conversion de chiffres romains, diamant) réalisés avec la librairie de tests unitaires **Unity**.

## Compilation

Chaque projet dispose de son propre `Makefile` :

```bash
cd Milestone_2/push_swap
make          # cible mandatory
make bonus    # cible bonus, quand elle existe (push_swap)
```

`fdf` nécessite un environnement Linux avec les dépendances X11 requises par la MiniLibX (fournie dans `lib/minilibx`).
