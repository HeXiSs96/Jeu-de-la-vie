#include "DeadCell.hpp"
#include "AliveCell.hpp"

void DeadCell::update(int x, int y, std::vector<std::vector<Cell*>>& grid) {
    int liveNeighbors = 0;
    // Compte les voisins vivants
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;
            int nx = (x + dx + grid.size()) % grid.size();
            int ny = (y + dy + grid[0].size()) % grid[0].size();
            if (dynamic_cast<AliveCell*>(grid[nx][ny])) {
                liveNeighbors++;
            }
        }
    }

    // Règles du jeu de la vie
    if (liveNeighbors == 3) {
        delete grid[x][y];  // La cellule devient vivante
        grid[x][y] = new AliveCell();
    }
}

void DeadCell::render(int x, int y, sf::RenderWindow& window, int cellSize) {
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    cell.setPosition(x * cellSize, y * cellSize);
    cell.setFillColor(sf::Color::Black);
    window.draw(cell);
}
