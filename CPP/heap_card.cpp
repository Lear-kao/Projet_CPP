#include "../HPP/heap_card.hpp"
#include "../HPP/spell.hpp"
#include "../HPP/unit.hpp"
#include <fstream>


heap_card::~heap_card(){
    for(size_t  i = 0 ; i < heap.size() ; ++i){
        delete heap[i];
    }
    heap.clear();
}

void heap_card::pop_card(card_gen* u)
{
    for(long unsigned int i = 0;  i < heap.size(); i++)
    {
        if(u == heap[i])
        {
            heap.erase(heap.begin() + i);
            return;
        }
    }
    
}

card_gen* heap_card::pick_one()
{
    if(heap.empty()) return NULL;
    card_gen* temp = heap.back();
    heap.pop_back();
    return temp;

}


void heap_card::add_one( card_gen* nc)
{
    heap.push_back(nc);
}

size_t heap_card::get_size(void)
{
    return heap.size();
}


card_gen* heap_card::get_card_x(int n)
{
    return heap[n];
}