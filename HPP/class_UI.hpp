#ifndef UI_HPP
#define UI_HPP
#include <SFML/Graphics.hpp>
#include <string.h>

class UI
{
    private:
        sf::Font font;
        sf::Text texte;
    public:
        UI();
        void set_position(float x, float y);
        void render(std::string text_, sf::RenderWindow& window);
};


#endif