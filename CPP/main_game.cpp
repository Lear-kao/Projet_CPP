#include "../HPP/main_game.hpp"
#include <SFML/Graphics.hpp>

#include "../HPP/hand.hpp"
#include "../HPP/board.hpp"


void main_game::render( sf::RenderWindow& window)
{
    window.draw(board_);
    next_phase->render(window);
    controller->render(window);
    r_player->render_general(window);
    bot->render_general(window);
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

        // ---- clic sur hand ----
        hand* hand_p = r_player->get_hand();
        for(int i = 0; i <  hand_p->get_size(); i++) 
        {
            auto* card = hand_p->get_card_x(i);
            if(card->get_sprite().getGlobalBounds().contains(mousePos)) 
            { 
                controller->selected_card_hand(i);
                return;
            }
        }
        if(controller->get_current_phase() == 2 || controller->s_is_blocking())
        {
            board* board_p = controller->get_current_player()->get_board();
            for(int i = 0; i < board_p->get_size(); i++) 
            {
                unit* card = (unit*)board_p->get_card_x(i);
                if(card->get_sprite().getGlobalBounds().contains(mousePos))
                {
                    controller->selected_card_board(card);
                    return;
                }
            }
        }
    }
    /*
    for(auto* u : bot->board) {
        if(u->get_sprite().getGlobalBounds().contains(mousePos)) {
            controller->selected_card_board(u);
            return;
        }
    } */
}

void main_game::update(float d)
{
    delta = d;
    controller->update(delta);
}

main_game::main_game(void)
{
    next_phase->set_loc(700,300);
    set_board();
}

void main_game::set_board( void )
{
    texture.loadFromFile("assets_lib_g/board.png");
    board_.setTexture(texture);
}