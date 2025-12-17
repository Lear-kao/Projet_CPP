#include "../HPP/player.hpp"

#include "hand.hpp"
#include "board.hpp"

player::player(bool a)
{
    bot = a;
    hand_player = new hand(bot);
    deck = new heap_card;
    board_player = new board(bot);
}

void player::render_hand(sf::RenderWindow& window)
{
    hand_player->render(window);
}

void player::render_board(sf::RenderWindow& window)
{
    board_player->render(window,bot);
}

void player::draw_card(void)
{
    hand_player -> add_one(deck->pick_one());
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