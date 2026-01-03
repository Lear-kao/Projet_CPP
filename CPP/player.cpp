#include <iostream>
#include "player.hpp"
#include <iostream>
#include <string.h>
#include "card_gen.hpp"
#include "hand.hpp"
#include "board.hpp"
#include "deck.hpp"
#include "unit.hpp"
#include "spell.hpp"


<<<<<<< Updated upstream
<<<<<<< Updated upstream

player::player(bool a)
=======
=======
>>>>>>> Stashed changes
/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
player::player(bool side)
>>>>>>> Stashed changes
{
    hand_player = new hand(side);
    deck_player = new deck(side);
    board_player = new board(side);

    for( int i = 0; i< 5; i ++)
    {
        hand_player->add_one(deck_player->pick_one());
    }
    if(bot)
    {
        UI_charge.set_position(40, 80);
        UI_life.set_position(50,30);
    }
    else
    {
        UI_charge.set_position(750, 500);
        UI_life.set_position(720,550);
    }
}


/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::render_hand(sf::RenderWindow& window)
{
    hand_player->render(window,is_bot());
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::render_board(sf::RenderWindow& window)
{
    board_player->render(window);
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::render_deck(sf::RenderWindow& window)
{
    deck_player->render(window);
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::render_life(sf::RenderWindow& window)
{
    UI_life.render(std::to_string(life),window);
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::render_charge(sf::RenderWindow& window)
{
    UI_charge.render(std::to_string(charge),window);
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::render_general(sf::RenderWindow& window)
{
    render_charge(window);
    render_deck(window);
    render_hand(window);
    render_board(window);
    render_life(window);
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::new_turn(int n_charge)
{
    draw_card();
    board_player->untap_all();
    charge = n_charge;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::pop_from(int from, card_gen* who)
{
    if(from == HAND)
    {
        hand_player->pop_card(who);
    }
    else if(from == BOARD)
    {
        board_player->pop_card(who);
    }
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
void player::render_hand(sf::RenderWindow& window)
{
    hand_player->render(window,is_bot());
}

void player::render_board(sf::RenderWindow& window)
{
    board_player->render(window);
}

void player::render_deck(sf::RenderWindow& window)
{
    deck_player->render(window);
}

void player::render_life(sf::RenderWindow& window)
{
    UI_life.render(std::to_string(life),window);
}

void player::render_charge(sf::RenderWindow& window)
{
    UI_charge.render(std::to_string(charge),window);
}

void player::render_general(sf::RenderWindow& window)
{
    render_charge(window);
    render_deck(window);
    render_hand(window);
    render_board(window);
    render_life(window);
}

=======
=======
>>>>>>> Stashed changes
/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
size_t player::get_player_hand_size(){
    return hand_player->get_size();
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
card_gen* player::get_card_from_hand(int i){
    return hand_player->get_card_x(i);
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
size_t player::get_player_board_size(){
    return board_player->get_size();
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
card_gen* player::get_card_from_board(int i){
    return board_player->get_card_x(i);
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
int player::charge_min_hand(){
    int charge_min = 10;
    for(size_t i = 0; i < get_player_hand_size() ; ++i){
        card_gen * card = get_card_from_hand(i);
        if(card->get_cost() < charge_min){
            charge_min = card->get_cost();
        }
    }
    return charge_min;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
void player::draw_card(void)
{
    hand_player -> add_one(deck_player->pick_one());
    return;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::healled(int heal)
{
    life += heal;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::hitted(int damage)
{
    life -= damage;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::summon_card(unit* unite)
{
    board_player->add_one(unite);
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::cast_spell(spell* casted, unit* target)
{
    std::string classe = casted->get_classe();
    int cout_reel = casted->get_cost();
    if(board_player->check(classe) == true)
    {
        cout_reel = 1;
    }
    if( charge >= cout_reel)
    {
        casted->resolve(target);
        set_charge(charge-cout_reel);
        pop_from(HAND,(card_gen*)casted);
    }
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::cast_spell(spell* casted, player* target)
{
    std::string classe = casted->get_classe();
    int cout_reel = casted->get_cost();
    if(board_player->check(classe) == true)
    {
        cout_reel = 1;
    }
    if( charge >= cout_reel)
    {
        casted->resolve(target);
        set_charge(charge-cout_reel);
        pop_from(HAND,(card_gen*)casted);
    }
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::add_board(card_gen* card)
{
    board_player->add_one(card);
    return;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::set_charge(int c)
{
    charge = c;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
int player::get_charge( void )
{
    return charge;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
unit* player::card_clicked_board(sf::Vector2f mousePos)
{
    for( long unsigned int i = 0; i < board_player->get_size(); i++) 
    {
        unit* card = (unit*)board_player->get_card_x(i);
        if(card->get_sprite().getGlobalBounds().contains(mousePos))
        {
            return card;
        }
    }
    return nullptr;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
card_gen* player::card_clicked_hand(sf::Vector2f mousePos)
{
    for( long unsigned int i = 0; i < hand_player->get_size(); i++) 
    {
        card_gen* card = hand_player->get_card_x(i);
        if(card->get_sprite().getGlobalBounds().contains(mousePos))
        {
            return card;
        }
    }
    return nullptr;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
bool player::is_dead( void )
{
    if( life <= 0 ) return true;
    return false;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
void player::update( float delta )
=======
=======
>>>>>>> Stashed changes
/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void player::update( [[maybe_unused]] float delta )
>>>>>>> Stashed changes
{
    hand_player->update();
    board_player->update();
}