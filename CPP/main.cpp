#include <SFML/Graphics.hpp>
#include "../HPP/main_game.hpp"
#include "../HPP/hand.hpp"


int turn = 0;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Base");
    main_game game;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        game.render(window);
        window.display();
    }
}
