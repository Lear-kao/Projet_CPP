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



player::player(bool a)
{
    bot = a;
    hand_player = new hand(bot);
    deck_player = new deck(bot);
    board_player = new board(bot);
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

void player::new_turn(int n_charge)
{
    draw_card();
    board_player->untap_all();
    charge = n_charge;
}

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

void player::render_hand(sf::RenderWindow& window)
{
    hand_player->render(window);
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

void player::draw_card(void)
{
    hand_player -> add_one(deck_player->pick_one());
    return;
}

void player::healled(int heal)
{
    life += heal;
}

void player::hitted(int damage)
{
    life -= damage;
}

void player::summon_card(unit* unite)
{
    board_player->add_one(unite);
}

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

void player::add_board(card_gen* card)
{
    board_player->add_one(card);
    return;
}

void player::set_charge(int c)
{
    charge = c;
}

int player::get_charge( void )
{
    return charge;
}

unit* player::card_clicked_board(sf::Vector2f mousePos)
{
    for( int i = 0; i < board_player->get_size(); i++) 
    {
        unit* card = (unit*)board_player->get_card_x(i);
        if(card->get_sprite().getGlobalBounds().contains(mousePos))
        {
            return card;
        }
    }
    return nullptr;
}

card_gen* player::card_clicked_hand(sf::Vector2f mousePos)
{
    for( int i = 0; i < hand_player->get_size(); i++) 
    {
        card_gen* card = hand_player->get_card_x(i);
        if(card->get_sprite().getGlobalBounds().contains(mousePos))
        {
            return card;
        }
    }
    return nullptr;
}

bool player::is_dead( void )
{
    if( life <= 0 ) return true;
    return false;
}

void player::update( float delta )
{
    hand_player->update();
    board_player->update();
}