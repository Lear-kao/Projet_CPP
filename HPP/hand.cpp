#include "../HPP/hand.hpp"

void hand::render(sf::RenderWindow& window, bool is_bot)
{
    if(!is_bot)
    {
        for( int i = 0; i < get_size(); i++)
        {
            heap[i]->render(window,i*100,500);
        }
    }
    return;
}