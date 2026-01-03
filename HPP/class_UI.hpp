#ifndef UI_HPP
#define UI_HPP
#include <SFML/Graphics.hpp>
#include <string.h>

/* 
Objectif : UI = User Interface, l'ojectif est de servir de support pour communiquer avec le joueurs
des informations.
Point à améliorer, en faire le parent de boutton ou d'autre objet serait un bon point de départ.
*/
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