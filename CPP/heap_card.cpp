#include "../HPP/heap_card.hpp"

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

heap_card::heap_card(){}