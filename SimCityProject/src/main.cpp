
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

const int TILE_SIZE = 64;
const int MAP_WIDTH = 5;
const int MAP_HEIGHT = 5;

enum TileType { EMPTY, RESIDENTIAL, COMMERCIAL, EV, DIESEL };

struct Tile {
    TileType type = EMPTY;
    sf::RectangleShape shape;
};

sf::Color getColorForType(TileType type) {
    switch (type) {
        case RESIDENTIAL: return sf::Color::Green;
        case COMMERCIAL: return sf::Color::Blue;
        case EV: return sf::Color::Cyan;
        case DIESEL: return sf::Color(128, 64, 0);
        default: return sf::Color(200, 200, 200);
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE), "SimCity GUI Edition");
    window.setFramerateLimit(60);

    std::vector<std::vector<Tile>> grid(MAP_HEIGHT, std::vector<Tile>(MAP_WIDTH));

    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            grid[i][j].shape.setSize(sf::Vector2f(TILE_SIZE - 2, TILE_SIZE - 2));
            grid[i][j].shape.setPosition(j * TILE_SIZE + 1, i * TILE_SIZE + 1);
            grid[i][j].shape.setFillColor(getColorForType(EMPTY));
        }
    }

    TileType currentPlacement = RESIDENTIAL;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) currentPlacement = RESIDENTIAL;
                if (event.key.code == sf::Keyboard::Num2) currentPlacement = COMMERCIAL;
                if (event.key.code == sf::Keyboard::Num3) currentPlacement = EV;
                if (event.key.code == sf::Keyboard::Num4) currentPlacement = DIESEL;
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x / TILE_SIZE;
                int y = event.mouseButton.y / TILE_SIZE;
                if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
                    grid[y][x].type = currentPlacement;
                    grid[y][x].shape.setFillColor(getColorForType(currentPlacement));
                }
            }
        }

        window.clear();
        for (const auto& row : grid)
            for (const auto& tile : row)
                window.draw(tile.shape);
        window.display();
    }

    return 0;
}
