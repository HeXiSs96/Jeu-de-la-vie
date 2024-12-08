#include <SFML/Graphics.hpp>
#include "GameOfLife.hpp"
#include <iostream>
#include <cstdlib> // Pour std::atoi

int main(int argc, char* argv[]) {
    // Dimensions par défaut
    int gridWidth = 100;
    int gridHeight = 100;

    // Lecture des dimensions depuis les arguments (si fournis)
    if (argc == 3) {
        gridWidth = std::atoi(argv[1]);
        gridHeight = std::atoi(argv[2]);

        if (gridWidth <= 0 || gridHeight <= 0) {
            std::cerr << "Erreur : les dimensions doivent être positives et non nulles.\n";
            return 1;
        }
    } else if (argc != 1) {
        // Message d'erreur si un mauvais nombre d'arguments est fourni
        std::cerr << "Utilisation : " << argv[0] << " [<gridWidth> <gridHeight>]\n";
        return 1;
    }

    int maxIterations = 100; // Nombre maximal d'itérations (ou -1 pour illimité)

    // Initialisation de la simulation du jeu de la vie
    GameOfLife game(gridWidth, gridHeight, maxIterations);

    // Démarrer l'exécution de la simulation
    game.run();

    return 0;
} 
