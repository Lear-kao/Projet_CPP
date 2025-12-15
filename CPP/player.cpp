#include "../HPP/player.hpp"

player::player(bool a)
{
    bot = a;
    hand_player = new hand;
    deck = new heap_card;
    board_player = new board;
}

void player::render_hand(sf::RenderWindow& window)
{
    hand_player->render(window,bot);
}

void player::render_board(sf::RenderWindow& window)
{
    board_player->render(window,bot);
}