#include "GameOfLife.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

// Planeur initial standard
const std::vector<std::pair<int, int>> PLANEUR_SHAPE = {
    {0, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}
};

// Grille contenant l'état des cellules
using Grid = std::vector<std::vector<bool>>;

// Initialiser la grille avec un planeur
void initializeGrid(Grid& grid, int startX, int startY) {
    for (const auto& cell : PLANEUR_SHAPE) {
        int x = (startX + cell.first) % grid.size();
        int y = (startY + cell.second) % grid[0].size();
        grid[x][y] = true;
    }
}

// Calculer le nombre de voisins vivants d'une cellule
int countLiveNeighbors(const Grid& grid, int x, int y) {
    int liveNeighbors = 0;
    int gridWidth = grid.size();
    int gridHeight = grid[0].size();

    // Parcourir les 8 voisins
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Ignorer la cellule centrale

            int nx = (x + dx + gridWidth) % gridWidth;
            int ny = (y + dy + gridHeight) % gridHeight;

            if (grid[nx][ny]) ++liveNeighbors;
        }
    }
    return liveNeighbors;
}

// Appliquer les règles du jeu de la vie pour mettre à jour la grille
void updateGrid(Grid& grid) {
    Grid nextGrid = grid; // Copie temporaire de la grille

    for (int x = 0; x < grid.size(); ++x) {
        for (int y = 0; y < grid[0].size(); ++y) {
            int liveNeighbors = countLiveNeighbors(grid, x, y);

            if (grid[x][y]) {
                // Une cellule vivante survit si elle a 2 ou 3 voisins vivants
                nextGrid[x][y] = (liveNeighbors == 2 || liveNeighbors == 3);
            } else {
                // Une cellule morte devient vivante si elle a exactement 3 voisins vivants
                nextGrid[x][y] = (liveNeighbors == 3);
            }
        }
    }

    grid = nextGrid; // Mise à jour de la grille
}

// Afficher la grille avec SFML
void drawGrid(const Grid& grid, int cellSize, sf::RenderWindow& window) {
    window.clear();

    for (int x = 0; x < grid.size(); ++x) {
        for (int y = 0; y < grid[0].size(); ++y) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(x * cellSize, y * cellSize);

            if (grid[x][y]) {
                cell.setFillColor(sf::Color::White); // Cellule vivante
            } else {
                cell.setFillColor(sf::Color::Black); // Cellule morte
            }

            cell.setOutlineThickness(1);
            cell.setOutlineColor(sf::Color::Black);
            window.draw(cell);
        }
    }

    window.display();
}

void testPlaneur(int gridWidth, int gridHeight, int cellSize) {
    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Test Grille Torique");

    // Initialiser la grille
    Grid grid(gridWidth, std::vector<bool>(gridHeight, false));
    initializeGrid(grid, gridWidth / 2, gridHeight / 2); // Planeur au centre

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Mettre à jour la grille selon les règles du jeu de la vie
        updateGrid(grid);

        // Afficher la grille
        drawGrid(grid, cellSize, window);

        // Délai constant pour une vitesse uniforme
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

int main(int argc, char** argv) {
    int gridWidth = 50;
    int gridHeight = 50;
    int cellSize = 10;

    if (argc == 3) {
        gridWidth = std::atoi(argv[1]);
        gridHeight = std::atoi(argv[2]);
    }

    testPlaneur(gridWidth, gridHeight, cellSize);

    return 0;
}
