# Jeu-de-la-vie
Projet POO

Voici notre implémentation élégante et modulaire du " Jeu de la Vie "

## 🌟 Ce que fait le projet  
Ce programme simule le célèbre **Jeu de la Vie** inventé par John Conway.  
Chaque cellule d'une grille peut être vivante ou morte, et évolue à chaque itération selon des règles simples :  
1. Une cellule vivante avec **2 ou 3 voisins vivants** survit.  
2. Une cellule morte avec **exactement 3 voisins vivants** naît.  
3. Dans tous les autres cas, la cellule meurt ou reste morte.  

Cette implémentation inclut une interface graphique pour visualiser les itérations en temps réel, ainsi que des fonctionnalités de personnalisation (taille de la grille, vitesse, mode pause).

Notre programme se constitue de 12 fichiers qui ensemble, lance parfaitement le Jeu de la vie

## 💡 Pourquoi le projet est utile  
Le Jeu de la Vie est bien plus qu'un simple jeu. C'est :  
- Un outil pédagogique pour explorer des concepts mathématiques comme les automates cellulaires.  
- Une manière intuitive de visualiser comment des règles simples peuvent créer des comportements complexes.  
- Une plateforme pour expérimenter des concepts en programmation comme les algorithmes, les graphismes, et l'optimisation.  

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


output/                    # Dossier généré pour les sauvegardes

## 🖲️ Commandes
- Flèche haut : Augmente la vitesse de la simulation.
- Flèche bas : Diminue la vitesse de la simulation.
- Barre d'espace : Met en pause ou reprend la simulation.

## Compilation et exécution
Prérequis
- CMake (version >= 3.10)
- Google Test (gtest)

## Étapes pour compiler et exécuter

- Pour compiler :
  g++ -o GameOfLife main.cpp GameOfLife.cpp Renderer.cpp Utils.cpp  -lsfml-graphics -lsfml-window -lsfml-system

 - Pour executer :
  ./GameOfLife
