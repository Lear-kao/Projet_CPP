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

bool board::check(std::string classe){
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