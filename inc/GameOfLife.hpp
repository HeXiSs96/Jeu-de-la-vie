#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Renderer.hpp"
#include "Utils.hpp"

class GameOfLife {
public:
    GameOfLife(int width, int height, int maxIters = -1);
    void run();  // Méthode principale pour exécuter la simulation
    void updateGrid();  // Met à jour l'état de la grille

private:
    int gridWidth;
    int gridHeight;
    int cellSize = 10;
    int delay = 100;  // Millisecondes entre chaque itération
    int iterationCount = 0;
    int maxIterations;  // Nombre maximal d'itérations
    bool paused = false;
    sf::RenderWindow window;
    std::vector<std::vector<int>> grid;

    Renderer renderer;  // Gestion de l'affichage
    Utils utils;        // Gestion des utilitaires
};

#endif // GAMEOFLIFE_HPP
