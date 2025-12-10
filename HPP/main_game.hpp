#include <SFML/Graphics.hpp>
#include "player.hpp"

class main_game
{
    private:
        player m_player;
        player bot;
    public:
        void handleEvent(const sf::Event& event, sf::RenderWindow& window);
        void update();
        void render(sf::RenderWindow& window);

};

