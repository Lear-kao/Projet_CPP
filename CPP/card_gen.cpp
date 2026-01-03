#include "../HPP/card_gen.hpp"


/* 
Objectif : Setter de la variable catégorie.
Entrée :
    - Un string correspondant à la catégorie de la carte.
Sortie : 
    - void
*/
void card_gen::set_categorie(std::string c)
{
    categorie = c;
}

/* 
Objectif : Getter de la variable categorie.
Entrée :
    - void
Sortie : 
    - Un string correspondant à la catégorie de la carte.
*/
std::string card_gen::get_categorie(void)
{
    return categorie;
}

/* 
Objectif : Setter de la variable cost.
Entrée :
    - Un entier correspondant au coût de la carte.
Sortie : 
    - void
*/
void card_gen::set_cost(int c)
{
    cost = c;
}

/* 
Objectif : Getter de la variable cost.
Entrée :
    - void
Sortie : 
    - Un entier correspondant au coût de la carte.
*/
int card_gen::get_cost()
{
    return cost;
}

/* 
Objectif : Setter de la variable classe.
Entrée :
    - Un string correspondant à la classe de la carte.
Sortie : 
    - void
*/
void card_gen::set_classe(std::string c)
{
    classe = c;
}

/* 
Objectif : Getter de la variable classe.
Entrée :
    - void
Sortie : 
    - Un string correspondant à la classe de la carte.
*/
std::string card_gen::get_classe(void)
{
    return classe;
}

/* 
Objectif : Setter de la variable name.
Entrée :
    - Un string correspondant au nom de la carte.
Sortie : 
    - void
*/
void card_gen::set_name(std::string n)
{
    name = n;
}

/* 
Objectif : setter de l'objet sprite et texture de sfml.
Entrée :
    - Un string correspondant au chemin vers l'image de la carte.
Sortie : 
    - void
*/
void card_gen::set_sprite(std::string path)
{
    texture.loadFromFile(path);
    sprite.setTexture(texture);
    
    texture_back.loadFromFile("assets_lib_g/back_card.png");
    sprite_back.setTexture(texture_back);
}

/* 
Objectif : Getter de l'objet sprite de sfml.
Entrée :
    - void
Sortie : 
    - L'objet sprite de sfml de la carte.
*/
sf::Sprite card_gen::get_sprite(void)
{
    return sprite;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
bool card_gen::counter(card_gen *ad){
    std::string classe_opposant = ad->get_classe();
    
    if(classe == "guerrier"){
        if(classe_opposant=="voleur"){
            return true;
        }
        return false;
    }
    else if(classe == "voleur"){
        if(classe_opposant=="mage"){
            return true;
        }
        return false;
    }
    else{
        if(classe_opposant=="guerrier"){
            return true;
        }
        return false;
    }
    
}

