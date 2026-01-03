#include "../HPP/class_UI.hpp"

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
UI::UI()
{
    if (!font.loadFromFile("DOC/arial.ttf")){
        return;
    }
    texte.setFont(font);
    texte.setCharacterSize(16);
    texte.setFillColor(sf::Color::White);
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void UI::render( std::string text_, sf::RenderWindow& window)
{
    texte.setString(text_);
    window.draw(texte);
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void UI::set_position(float x, float y)
{
    texte.setPosition(x, y);
}