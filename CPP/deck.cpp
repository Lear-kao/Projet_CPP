#include "../HPP/deck.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <random>

/* 
Objectif : Constructeur de la classe deck hérité de heap_card
Entrée :
    - Un boléen qui nous indique si le joueur et un bot ou non.
Sortie : 
    - void
*/
deck::deck( bool bot ) : is_bot(bot)
{
    //charger et récupérer les informations du fichiers texte contenant les cartes
    std::ifstream f("DOC/cards.txt");

    std::string chemin, categorie, classe;
    int charge;

    while (f >> chemin >> categorie >> classe >> charge)
    {
        card_gen* c = nullptr;

        if (categorie == "unite")
            c = new unit(charge);
        else
            c = new spell(charge);

        c->set_categorie(categorie);
        c->set_classe(classe);
        c->set_sprite(chemin);

        heap.push_back(c);
    }
    //mélange le paquet nouvellement crée
    shuffle();

    //récupère la texture de dos de carte
    if (!texture.loadFromFile("assets_lib_g/back_card.png"))
        throw std::runtime_error("texture back_card manquante");

    sprite.setTexture(texture);
    if (!is_bot)
        sprite.setPosition(128, 515);
    else
    {
        sprite.setPosition(631, 20);
    }
}

/* 
Objectif : Calculer la position et afficher un sprite du dos d'un carte lambda.
Entrée :
    - L'objet d'affichage de sfml
    - Un booléen qui sert a savoir si il faut afficher le dos ou la face des cartes.
        (inutilisé, obligatoire car méthode virtuelle hérité)
Sortie :
    - void
*/


void deck::render( sf::RenderWindow& window, [[maybe_unused]] bool hidden )
{
    window.draw(sprite);
}

/* 
Objectif : Mélanger le paquet de carte.
Entrée :
    - void
Sortie : 
    - void
*/
void deck::shuffle( void )
{
    //utilisation de la librairie standard
    std::mt19937 rng{std::random_device{}()};
    std::shuffle(heap.begin(),heap.end(),rng);
}