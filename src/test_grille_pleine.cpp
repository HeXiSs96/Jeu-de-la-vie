#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

void createFullGrid(const std::string& filename, int width, int height) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Erreur lors de la création du fichier : " << filename << std::endl;
        return;
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            file << 1 << " ";
        }
        file << "\n";
    }

    file.close();
    std::cout << "Fichier " << filename << " créé avec une grille pleine." << std::endl;
}

int main() {
    int gridWidth = 100; // Largeur de la grille
    int gridHeight = 100; // Hauteur de la grille
    createFullGrid("test_grille_pleine.txt", gridWidth, gridHeight);

    // Calculer la taille maximale de la fenêtre
    int cellSize = 10; // Taille des cellules
    int windowWidth = std::min(gridWidth * cellSize, 800); // Maximum 800 pixels de large
    int windowHeight = std::min(gridHeight * cellSize, 800); // Maximum 800 pixels de haut
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Grille Pleine");

    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize)); // Taille de chaque cellule
    cell.setFillColor(sf::Color::White);
    cell.setOutlineThickness(2.f); // Épaisseur de la bordure
    cell.setOutlineColor(sf::Color::Black); // Couleur de la bordure

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Dessiner la grille entière
        for (int y = 0; y < gridHeight; ++y) {
            for (int x = 0; x < gridWidth; ++x) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }

        window.display();
    }

    return 0;
}
