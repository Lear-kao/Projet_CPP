#include <SFML/Graphics.hpp>
#include "../HPP/main_game.hpp"
#include "../HPP/hand.hpp"


int turn = 0;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Base");
    sf::Clock clock;
    main_game game;
    float delta;
    while (window.isOpen()) {
        sf::Event event;
        delta = clock.restart().asSeconds();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            game.handleEvent(event,window);
        }

        window.clear(sf::Color::Black);
        game.render(window);
        window.display();
        game.update(delta);
    }
}
