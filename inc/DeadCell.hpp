#ifndef DEADCELL_HPP
#define DEADCELL_HPP

#include "Cell.hpp"
#include <SFML/Graphics.hpp>

class DeadCell : public Cell {
public:
    void update(int x, int y, const std::vector<std::vector<Cell*>>& grid) override;
    void render(int x, int y, sf::RenderWindow& window, int cellSize) override;
};

#endif // DEADCELL_HPP
