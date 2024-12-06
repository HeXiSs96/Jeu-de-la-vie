#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Cell {
public:
    virtual void update(int x, int y, const std::vector<std::vector<Cell*>>& grid) = 0;
    virtual void render(int x, int y, sf::RenderWindow& window, int cellSize) = 0;
    virtual ~Cell() = default;  // Destructeur virtuel pour garantir la destruction correcte des objets dérivés
};

#endif // CELL_HPP
