#include <SFML/Graphics.hpp>
#include <unistd.h>

#include "../HPP/main_game.hpp"


int turn = 0;

int main() 
{
    int pid = fork();
    if(pid == 0)
    {
        execlp("xdg-open", "xdg-open", "Regle_du_jeu.pdf", (char*)nullptr);
        return 0;
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Base");
    sf::Clock clock;
    main_game game;
    float delta;
    while (window.isOpen()) 
    {
        sf::Event event;
        delta = clock.restart().asSeconds();
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
            game.handleEvent(event,window);
        }

        window.clear(sf::Color::Black);
        game.render(window);
        window.display();
        if(game.update(delta) == true) window.close();
    }
}
