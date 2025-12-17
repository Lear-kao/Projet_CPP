#include "../HPP/main_game.hpp"
#include <SFML/Graphics.hpp>


void main_game::render( sf::RenderWindow& window)
{
    next_phase->render(window);
}



void main_game::handleEvent(const sf::Event& event, sf::RenderWindow& window)
/* 
!!!
fonction à moddifier pour respecter l'encapsulation des données !!!
*/
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2f mousePos = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});

    if (next_phase->get_sprite().getGlobalBounds().contains(mousePos))
    {
        controller->next_phase();
    }
    }

    /*

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

main_game::main_game(void)
{
    next_phase->set_loc(100,100);
}