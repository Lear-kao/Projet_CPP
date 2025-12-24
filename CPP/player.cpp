#include "../HPP/player.hpp"
#include <iostream>
#include <string.h>
#include "hand.hpp"
#include "board.hpp"
#include "deck.hpp"
#include "unit.hpp"


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
    sf::Font font;
    if (!font.loadFromFile("assets_lib_g/arial.ttf")){
        return;
    }  
    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(life));
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Black);
    text.setPosition(700, 500);
    window.draw(text);
}

void player::render_charge(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("assets_lib_g/arial.ttf")){
        return;
    }  
    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(charge));
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Black);
    text.setPosition(700, 400);
    window.draw(text);
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

hand* player::get_hand( void )
{
    return hand_player;
}


board* player::get_board(){
    return board_player;
}

void player::summon_card(unit* unite)
{
    board_player->add_one(unite);
}

void player::set_charge(int c){
    charge = c;
}

int player::get_charge(){
    return charge;
}
