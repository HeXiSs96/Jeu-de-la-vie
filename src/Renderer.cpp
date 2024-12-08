#include "Renderer.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>  


Renderer::Renderer(sf::RenderWindow& window, int width, int height, int cellSize)
    : window(window), gridWidth(width), gridHeight(height), cellSize(cellSize) {}

void Renderer::renderGrid(const std::vector<std::vector<int>>& grid) {
    for (int y = 0; y < gridHeight; ++y) {
        for (int x = 0; x < gridWidth; ++x) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(x * cellSize, y * cellSize);
            cell.setFillColor(grid[x][y] ? sf::Color::Green : sf::Color::Black);
            cell.setOutlineThickness(1);
            cell.setOutlineColor(sf::Color::Black);
            window.draw(cell);
        }
    }
}

void Renderer::renderTextInfo(int iteration, int delay, bool paused) {
    sf::Font font;
    sf::Text text("Itérations: " + std::to_string(iteration) + " | Vitesse: " + std::to_string(delay) + "ms | " + (paused ? "Pause" : "En cours"), font, 20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(10, gridHeight * cellSize + 10);
    window.draw(text);
}
 
