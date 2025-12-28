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
        click_on_hand(mousePos);

        // -- click sur le board -
        click_on_board(mousePos);
        click_on_current_attacker(mousePos);

        
    }
}

void main_game::click_on_hand(sf::Vector2f mousePos)
{

    card_gen* t_card = r_player->card_clicked_hand(mousePos);
    if(t_card!=nullptr)
    {
        controller->selected_card_hand(t_card, r_player);
        return;
    }
    t_card = bot->card_clicked_hand(mousePos);
    if(t_card!=nullptr)
    {
        controller->selected_card_hand(t_card, bot);
        return;
    }

}

void main_game::click_on_current_attacker(sf::Vector2f mousePos)
{
    //unit* t_unit = controller->is_attacker_clicker(sf::Vector2f mousePos);
    std::vector<fight> l_fighter = controller->get_current_attacker();
    for(long unsigned int i = 0; i < l_fighter.size(); i++) 
    {
        unit* card = (unit*)l_fighter[i].attacker;
        if(card->get_sprite().getGlobalBounds().contains(mousePos))
        {
            controller->select_blocker_target(card);
            return;
        }
    }
}

void main_game::click_on_board(sf::Vector2f mousePos)
{
    unit* t_unit = r_player->card_clicked_board(mousePos);
    if(t_unit != nullptr)
    {
        controller->selected_card_board(t_unit, r_player);
        return;
    }

    t_unit = bot->card_clicked_board(mousePos);
    if(t_unit != nullptr)
    {
        controller->selected_card_board(t_unit, bot);
        return;
    }
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