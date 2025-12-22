#include "../HPP/player.hpp"
#include <iostream>
#include "hand.hpp"
#include "board.hpp"
#include "deck.hpp"

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

void player::render_general(sf::RenderWindow& window)
{
    render_board(window);
    render_deck(window);
    render_hand(window);
}