#include "GameOfLife.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

// Constructeur
GameOfLife::GameOfLife(int width, int height, int maxIters) :
    gridWidth(width), gridHeight(height), maxIterations(maxIters),
    window(sf::VideoMode(width * cellSize, height * cellSize), "Jeu de la Vie"),
    renderer(window, gridWidth, gridHeight, cellSize),
    utils()
{
    // Initialiser la grille avec des cellules aléatoires
    grid.resize(gridWidth, std::vector<int>(gridHeight, 0));
    for (int y = 0; y < gridHeight; ++y) {
        for (int x = 0; x < gridWidth; ++x) {
            grid[x][y] = rand() % 2;  // 0 ou 1, cellule morte ou vivante
        }
    }
}

// Méthode principale pour lancer la simulation
void GameOfLife::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Gestion de la pause
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                paused = !paused;
                std::cout << (paused 
                    ? "Simulation en pause à l'itération " + std::to_string(iterationCount) 
                    : "Simulation reprise à l'itération " + std::to_string(iterationCount)) 
                    << "." << std::endl;
            }

            // Ajustement de la vitesse
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    delay = std::max(10, delay - 10);  // Augmenter la vitesse
                    std::cout << "Vitesse augmentée : délai = " << delay << " ms." << std::endl;
                } else if (event.key.code == sf::Keyboard::Down) {
                    delay = std::min(1000, delay + 10);  // Réduire la vitesse
                    std::cout << "Vitesse réduite : délai = " << delay << " ms." << std::endl;
                }
            }
        }

        if (!paused) {
            if (maxIterations != -1 && iterationCount >= maxIterations) {
                std::cout << "Simulation terminée : max itérations (" << maxIterations << ") atteintes." << std::endl;
                break;
            }

            updateGrid();
            iterationCount++;
            utils.saveToFile("output", iterationCount, grid);  // Sauvegarde
        }

        renderer.renderGrid(grid);  // Affichage de la grille
        renderer.renderTextInfo(iterationCount, delay, paused);

        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));  // Attente
    }

    std::cout << "Simulation terminée à l'itération " << iterationCount << "." << std::endl;
}

// Méthode pour mettre à jour la grille
void GameOfLife::updateGrid() {
    std::vector<std::vector<int>> newGrid(gridWidth, std::vector<int>(gridHeight, 0));

    for (int y = 0; y < gridHeight; ++y) {
        for (int x = 0; x < gridWidth; ++x) {
            int liveNeighbors = 0;

            // Compter les voisins vivants
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dx == 0 && dy == 0) continue;

                    int nx = (x + dx + gridWidth) % gridWidth;  // Toroïdalité
                    int ny = (y + dy + gridHeight) % gridHeight;

                    liveNeighbors += grid[nx][ny];
                }
            }

            // Application des règles du Jeu de la Vie
            newGrid[x][y] = (grid[x][y] == 1) ? (liveNeighbors == 2 || liveNeighbors == 3) : (liveNeighbors == 3);
        }
    }

    grid = newGrid;
} 
