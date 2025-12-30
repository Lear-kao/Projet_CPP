#include "../HPP/board.hpp"

void board::render(sf::RenderWindow& window )
{
    const int spacing = 43;
    int total_width = (heap.size() - 1) * spacing;
    int start_x = border_x - total_width / 2;

    for(int i = 0; i < heap.size(); i++)
    {
        heap[i]->render(window, start_x + i * spacing, border_y);
    }
    return;
}

board::board(bool is_bot)
{
    if(is_bot)
    {
        border_x = MIDDLE_X;
        border_y = 115;
    }
    else 
    {
        border_x = MIDDLE_X;
        border_y = 420;
    }
}

void board::untap_all( void )
{
    for( long unsigned int i = 0; i < heap.size(); i++)
    {
        unit* u = (unit*)heap[i];
        u->untap();
    }
}

bool board::check(std::string classe)
{
    //vérifie si dans le board d'un joueur il y a une unité d'une certaine classe
    //sert pour le calcul du coût d'un sort
    size_t i = 0;
    while(i < heap.size() && (heap[i]->get_classe() != classe)){
        i++;
    }
    if(i < heap.size()){
        return true;
    }
    return false;
}

void board::update( void )
{
    for(long unsigned int i = 0; i < heap.size(); i++ )
    {
        unit* t_unit = (unit*)heap[i];
        if(t_unit->is_dead())
        {
            pop_card(t_unit);
        }
    }
}

