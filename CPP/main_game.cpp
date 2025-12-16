#include "../HPP/main_game.hpp"
#include <SFML/Graphics.hpp>


void main_game::render( sf::RenderWindow& window)
{
    sf::Texture texture;
    texture.loadFromFile("/home/axel/Projet_CPP/assets_lib_g/maison.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(100, 100);
    window.draw(sprite);
}



void main_game::handleEvent(const sf::Event& event, sf::RenderWindow& window)
/* 
!!!
fonction à moddifier pour respecter l'encapsulation des données !!!
*/
{
    /* if(event.type != sf::Event::MouseButtonPressed || event.mouseButton.button != sf::Mouse::Left)
        return;

    sf::Vector2f mousePos =
        window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});

    // ---- clic sur hand ----
    for(auto* card : m_player->hand) 
    {
        if(u->get_sprite().getGlobalBounds().contains(mousePos)) 
        { 
            controller->selected_card_hand(card);
            return;
        }
    }

    // ---- clic sur board ----
    for(auto* u : m_player->board) 
    {
        if(u->get_sprite().getGlobalBounds().contains(mousePos))
        {
            controller->selected_card_board(u);
            return;
        }
    }

    for(auto* u : bot->board) {
        if(u->get_sprite().getGlobalBounds().contains(mousePos)) {
            controller->selected_card_board(u);
            return;
        }
    } */
}
