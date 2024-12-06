#include <SFML/Graphics.hpp>
#include "GameOfLife.hpp"

int main() {
    // Définition des dimensions de la grille et du nombre d'itérations (max -1 pour illimité)
    int gridWidth = 150;
    int gridHeight = 150;
    int maxIterations = 100;  // Nombre maximal d'itérations (ou -1 pour illimité)

    // Initialisation de la simulation du jeu de la vie
    GameOfLife game(gridWidth, gridHeight, maxIterations);

    // Démarrer l'exécution de la simulation
    game.run();

    return 0;
}
