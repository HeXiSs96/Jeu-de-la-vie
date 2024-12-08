#ifndef ALIVECELL_HPP
#define ALIVECELL_HPP

#include "Cell.hpp"
#include <SFML/Graphics.hpp>

class AliveCell : public Cell {
public:
    void update(int x, int y, std::vector<std::vector<Cell*>>& grid) override;
    void render(int x, int y, sf::RenderWindow& window, int cellSize) override;
};

#endif // ALIVECELL_HPP

