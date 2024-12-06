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

Voici sa structure

├── src/
│   ├── main.cpp               # Point d'entrée du programme
│   ├── AliveCell.hpp
│   ├── AliveCell.cpp
│   ├── DeadCell.hpp
│   ├── DeadCell.cpp
│   ├── Cell.hpp
│   ├── GameOfLife.hpp
│   ├── GameOfLife.cpp
│   ├── Renderer.hpp
│   ├── Renderer.cpp
│   ├── Utils.hpp
│   ├── Utils.cpp
├── output/                    # Dossier généré pour les sauvegardes
