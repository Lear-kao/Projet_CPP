#include <iostream>
#include "../HPP/hand.hpp"

void hand::render(sf::RenderWindow& window, bool hidden)
{
    const int spacing = 43;
    int total_width = (heap.size() - 1) * spacing;
    int start_x = border_x - total_width / 2;
    for(int i = 0; i < heap.size(); i++)
    {
        heap[i]->render(window, start_x + i * spacing, border_y, hidden);
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

void hand::update( void )
{
    if(is_max_size())
    {
        heap.erase(heap.begin());
    }
}

hand::hand(bool is_bot)
{
    if(is_bot)
    {
        border_x = MIDDLE_X;
        border_y = 20;
    }
    else 
    {
        border_x = MIDDLE_X;
        border_y = 510;
    }
}

