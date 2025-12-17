#include "../HPP/heap_card.hpp"
#include "../HPP/spell.hpp"
#include "../HPP/unit.hpp"
#include <fstream>

heap_card::heap_card(){
    std::ifstream f("../DOC/cards.txt");
    std::string chemin, categorie, classe;
    int charge;

    while(f >> chemin >> categorie >> classe >> charge) 
    //renvoie 4 s'il a bien lu 4 composantes,sinon ça veut dire que c'est la fin du fichier
    {
        if(categorie == "unite"){
            unit *u = new unit(charge);
            u->set_categorie(categorie);
            u->set_classe(classe);
            //u.set_sprite(chemin);
            heap.push_back(u);
        }
        else{
            spell *s = new spell(charge);
            s->set_categorie(categorie);
            s->set_classe(classe);
            //s.set_sprite(chemin);
            heap.push_back(s);
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
