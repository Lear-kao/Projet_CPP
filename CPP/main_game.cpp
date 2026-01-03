#include <SFML/Graphics.hpp>
#include <iostream>
#include "../HPP/main_game.hpp"
#include "../HPP/hand.hpp"
#include "../HPP/board.hpp"

main_game::main_game()
{
    r_player = new player(0);
    b_player = new bot();
    controller = new game_controller(r_player, b_player);
    next_phase = new gen_button("assets_lib_g/button_next_phase.png");
    next_phase->set_loc(718,402);
    set_board();
}


main_game::~main_game(void){
    delete r_player;
    delete b_player;
    delete controller;
    delete next_phase;
}

void main_game::render( sf::RenderWindow& window )
{
    window.draw(board_);
    next_phase->render(window);
    controller->render(window);
    r_player->render_general(window);
    b_player->render_general(window);
}

void main_game::handleEvent( const sf::Event& event, sf::RenderWindow& window )
/* 
Appelle les différents fonctions pour que le joueurs puisse intéragir avec la fenêtre
*/
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2f mousePos = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});

        // ----- clic sur le prochain tour -----
        if (next_phase->get_sprite().getGlobalBounds().contains(mousePos))
        {
            controller->next_phase();
        }

        // ----- clic sur hand -----
        click_on_hand(mousePos);

        // ----- clic sur le board -----
        click_on_board(mousePos);

        // ----- clic sur les attaquants -----
        click_on_current_attacker(mousePos);
    }
}

void main_game::click_on_hand( sf::Vector2f mousePos )
{

    card_gen* t_card = r_player->card_clicked_hand(mousePos);
    if(t_card!=nullptr)
    {
        controller->selected_card_hand(t_card, r_player);
        return;
    }
    t_card = b_player->card_clicked_hand(mousePos);
    if(t_card!=nullptr)
    {
        controller->selected_card_hand(t_card, b_player);
        return;
    }

}

void main_game::click_on_current_attacker( sf::Vector2f mousePos )
{
    controller->clicked_attacker(mousePos);
}

void main_game::click_on_board( sf::Vector2f mousePos )
{
    unit* t_unit = r_player->card_clicked_board(mousePos);
    if(t_unit != nullptr)
    {
        controller->selected_card_board(t_unit, r_player);
        return;
    }

    t_unit = b_player->card_clicked_board(mousePos);
    if(t_unit != nullptr)
    {
        controller->selected_card_board(t_unit, b_player);
        return;
    }
}

bool main_game::update( float delta )
{
    controller->update(delta);
    if(r_player->is_dead()) 
    {
        std::cout << "Pas de chance vous avez perdu!\n Si vous avez du mal avec les règles n'ésitez pas à les relir et sinon il faudra pratiquer ;) \n";
        return true;
    }
    if(b_player->is_dead()) 
    {
        std::cout << "Félicitation vous avez gagné!\n Continuer de pratiquer et si le \n coeur des developpers leurs en dit \nils feront un jour un mode joueur contre joueur!";
        return true;
    }
    return false;
}

<<<<<<< HEAD
=======
player* main_game::who_s_dead( void )
{
    if(r_player->is_dead()) return r_player;
    if(b_player->is_dead()) return b_player;
    return nullptr;
}
>>>>>>> cb4a8a6 (destructeurs)

void main_game::set_board( void )
{
    texture.loadFromFile("assets_lib_g/board.png");
    board_.setTexture(texture);
}