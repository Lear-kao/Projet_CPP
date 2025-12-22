#include "../HPP/board.hpp"

void board::render(sf::RenderWindow& window )
{
    for( int i = 0; i < get_size(); i++)
    {
        heap[i]->render(window,i*40,border_y);
    }
    return;
}

board::board(bool is_bot)
{
    if(is_bot)
    {
        border_x = 20;
        border_y = 80;
    }
    else 
    {
        border_x = 20;
        border_y = 380;
    }
}

void board::untap_all( void )
{
    for( int i = 0; i < heap.size(); i++)
    {
        unit *a = (unit*)heap[i];
        if(a->is_tapped())
        {
            a->untap();
        }
    }
}