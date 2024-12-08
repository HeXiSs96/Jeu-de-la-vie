#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

void createEmptyGrid(const std::string& filename, int width, int height) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Erreur lors de la création du fichier : " << filename << std::endl;
        return;
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            file << 0 << " ";
        }
        file << "\n";
    }

    file.close();
    std::cout << "Fichier " << filename << " créé avec une grille vide." << std::endl;
}

int main() {
    int gridWidth = 100;  // Largeur de la grille
    int gridHeight = 100; // Hauteur de la grille
    createEmptyGrid("test_grille_vide.txt", gridWidth, gridHeight);

    // Calcul de la taille des cellules pour ajuster l'affichage
    int maxWindowSize = 800; // Taille maximale de la fenêtre
    float cellSize = static_cast<float>(maxWindowSize) / std::max(gridWidth, gridHeight);

    // Dimensions de la fenêtre
    int windowWidth = static_cast<int>(gridWidth * cellSize);
    int windowHeight = static_cast<int>(gridHeight * cellSize);
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Grille Vide");

    // Rectangle représentant une cellule
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    cell.setFillColor(sf::Color::Black);
    cell.setOutlineThickness(1.f);
    cell.setOutlineColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Dessiner la grille
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
 
