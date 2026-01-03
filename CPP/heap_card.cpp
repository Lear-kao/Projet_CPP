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

/* 
Objectif : Supprime la carte passé en paramètre du vecteur la contenant.
Entrée :
    - Un pointeur vers une carte.
Sortie : 
    - void
*/
void heap_card::pop_card( card_gen* u )
{
    //parcour le vecteur jusqu'à trouver la carte et la supprime.
    for(long unsigned int i = 0;  i < heap.size(); i++)
    {
        if(u == heap[i])
        {
            heap.erase(heap.begin() + i);
            return;
        }
    }
    
}

/* 
Objectif : Supprime et déttruit la carte passé en paramètre du vecteur la contenant.
Entrée :
    - Un pointeur vers une carte.
Sortie : 
    - void
*/
void heap_card::destroy_card( card_gen* u )
{
    //parcour le vecteur jusqu'à trouver la carte et la supprime.
    for(long unsigned int i = 0;  i < heap.size(); i++)
    {
        if(u == heap[i])
        {
            delete heap[i];
            heap.erase(heap.begin() + i);
            return;
        }
    }
    
}

/* 
Objectif : Récupérer la dernière carte de la pile.
Entrée :
    - void
Sortie : 
    - Un pointeur vers une carte.
*/
card_gen* heap_card::pick_one( void )
{
    if(heap.empty()) return NULL;
    card_gen* temp = heap.back();
    heap.pop_back();
    return temp;

}

/* 
Objectif : Ajoute une carte au vecteur de la classe.
Entrée :
    - Un pointeur vers une carte.
Sortie : 
    - void
*/
void heap_card::add_one( card_gen* nc )
{
    heap.push_back(nc);
}

/* 
Objectif : Récupérer la taille du vecteur de carte de la classe.
Entrée :
    - void
Sortie : 
    - size_t un typedef de unsigned long.
*/
size_t heap_card::get_size( void )
{
    return heap.size();
}

/* 
Objectif : Récupérer la carte à l'emplacement n.
Entrée :
    - Un entier n.
Sortie : 
    - La carte à cet emplacement.
*/
card_gen* heap_card::get_card_x( int n )
{
    return heap[n];
}