#include "../HPP/class_UI.hpp"

UI::UI()
{
    if (!font.loadFromFile("DOC/arial.ttf")){
        return;
    }
    texte.setFont(font);
    texte.setCharacterSize(25);
    texte.setFillColor(sf::Color::Black);
}

void UI::render( std::string text_, sf::RenderWindow& window)
{
    texte.setString(text_);
    window.draw(texte);
}

void UI::set_position(float x, float y)
{
    texte.setPosition(x, y);
}