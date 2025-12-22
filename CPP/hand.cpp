#include "../HPP/hand.hpp"

void hand::render(sf::RenderWindow& window)
{
    int size = get_size();
    if(size == 0) exit(0);
    for( int i = 0; i < get_size(); i++)
    {
        heap[i]->render(window,i*38+border_x,border_y);
    }
    return;
}

bool hand::is_max_size()
{
    if( heap.size() >= MAX_SIZE)
    {
        return true;
    }
    return false;
}

hand::hand(bool is_bot)
{
    if(is_bot)
    {
        border_x = 170;
        border_y = 20;
    }
    else 
    {
        border_x = 170;
        border_y = 510;
    }
}

