#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Renderer {
public:
    Renderer(sf::RenderWindow& window, int width, int height, int cellSize);
    void renderGrid(const std::vector<std::vector<int>>& grid);
    void renderTextInfo(int iteration, int delay, bool paused);

private:
    sf::RenderWindow& window;
    int gridWidth;
    int gridHeight;
    int cellSize;
};

#endif // RENDERER_HPP
