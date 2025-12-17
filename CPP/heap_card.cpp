#include "../HPP/heap_card.hpp"

heap_card::heap_card(){
    FILE* f = fopen("../DOC/cards.txt","r");
    char* chemin=nullptr;
    char* categorie=nullptr;
    char* classe=nullptr;
    int charge;

    while(fscanf(f,"%s %s %s %d",chemin,categorie,classe,&charge) == 4) 
    //renvoie 4 s'il a bien lu 4 composantes,sinon ça veut dire que c'est la fin du fichier
    {
        if(strcmp(categorie,"unite")){
            unit *u;
            u->set_categorie(categorie);
            u->set_classe(classe);
            //u.set_sprite(chemin);
            heap.push_back(u);
        }
        else{
            spell *s;
            s->set_categorie(categorie);
            s->set_classe(classe);
            //s.set_sprite(chemin);
            heap.push_back(s);
        }
    }
    
    fclose(f);
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
