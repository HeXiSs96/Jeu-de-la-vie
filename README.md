# Jeu de la Vie


Une implémentation du célèbre Jeu de la Vie de John Conway en C++ avec une interface interactive pour ajuster la vitesse de simulation et mettre en pause le jeu.

## 🌟 Description  
Ce projet simule le Jeu de la Vie, un automate cellulaire basé sur une grille 2D où chaque cellule évolue selon des règles simples.

Les fonctionnalités incluent :

- Démarrage automatique de la simulation.
- Mise en pause et reprise du jeu avec la barre Espace.
- Ajustement de la vitesse de simulation avec les touches flèche haut et flèche bas.
- Cette implémentation inclut une interface graphique pour visualiser les itérations en temps réel, ainsi que des fonctionnalités de personnalisation (taille de la grille, vitesse, mode pause).



## 💡 Fonctionnalités principales  
Simulation dynamique : basée sur les règles de Conway :
- Une cellule vivante reste vivante si elle a 2 ou 3 voisines vivantes.
- Une cellule morte devient vivante si elle a exactement 3 voisines vivantes.
Contrôle interactif : Pause/lecture et ajustement de la vitesse.
Tests unitaires : Vérifient les règles du jeu et les mises à jour de la grille.


## Prérequis
Avant de commencer, assurez-vous d'avoir :

- C++ (version C++11 ou supérieure).
- CMake (pour la gestion du projet).
- Google Test (pour exécuter les tests unitaires).

## Étapes pour compiler et exécuter

- Pour compiler :
  g++ -o GameOfLife main.cpp GameOfLife.cpp Renderer.cpp Utils.cpp  -lsfml-graphics -lsfml-window -lsfml-system

 - Pour executer :
  ./GameOfLife


Voici sa structure :

 src/
 - main.cpp               # Point d'entrée du programme
 - AliveCell.hpp
 - AliveCell.cpp
 - DeadCell.hpp
 - DeadCell.cpp
 - Cell.hpp
 - GameOfLife.hpp
 - GameOfLife.cpp
 - Renderer.hpp
 - Renderer.cpp
 - Utils.hpp
 - Utils.cpp

Test Unitaires :
   - test_planeur
   - test_grille_vide
   - test_grille_pleine


output/                    # Dossier généré pour les sauvegardes

## 🖲️ Commandes
- Flèche haut : Augmente la vitesse de la simulation.
- Flèche bas : Diminue la vitesse de la simulation.
- Barre d'espace : Met en pause ou reprend la simulation.
 
