#include "../HPP/heap_card.hpp"
#include "../HPP/spell.hpp"
#include "../HPP/unit.hpp"
#include <fstream>


void heap_card::pop_i(int i)
{
    heap.erase(heap.begin() + i);
}

void heap_card::pop_i(unit* u)
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

int heap_card::get_size(void)
{
    return heap.size();
}


card_gen* heap_card::get_card_x(int n)
{
    return heap[n];
}