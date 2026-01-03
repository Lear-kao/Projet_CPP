#include "../HPP/board.hpp"

/* 
Objectif : Constructeur de la class board hérité de la class heap_card.
Entrée :
    - Un booléen représentant si le propriétaire de l'objet est un bot ou non.
Sortie : 
    - void
*/
board::board( bool is_bot )
{
    //définis l'emplacement du terrain du joueur en fonction de quel joueur il s'agit.
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

/* 
Objectif : Calculer la position et appeller les méthodes d'affichages de chaques cartes.
Entrée :
    - L'objet d'affichage de sfml
    - Un booléen qui sert a savoir si il faut afficher le dos ou la face des cartes.
Sortie :
    - void
*/
void board::render( sf::RenderWindow& window, [[maybe_unused]] bool hidden )
{
    const int spacing = 43;
    int total_width = (heap.size() - 1) * spacing;
    int start_x = border_x - total_width / 2;

    for(size_t i = 0; i < heap.size(); i++)
    {
        heap[i]->render(window, start_x + i * spacing, border_y, false);
    }
    return;
}

/* 
Objectif : Désengager toute les créatures sur le terrain.
Entrée :
    - void
Sortie : 
    - void
*/
void board::untap_all( void )
{
    //parcour chaques cartes et appelle les méthodes pour les désengager
    for( long unsigned int i = 0; i < heap.size(); i++)
    {
        unit* u = (unit*)heap[i];
        u->untap();
    }
}

/* 
Objectif : Vérifie si dans le board d'un joueur il y a une unité d'une certaine classe. 
            (utile pour le calcul des coûts en charge)
Entrée :
    - Une chaine de charactère correspondant au nom de la classe recherchée.
Sortie : 
    - Un booléen.
*/
bool board::check( std::string classe )
{
    size_t i;
    for(i=0; i < heap.size(); i++) 
    {
        if(heap[i]->get_classe() == classe) return true;
    }
    return false;
}

/* 
Objectif : méthode appellé à chaque tic qui sert a executer les méthodes devant être activée automatiquement.
Entrée :
    - void
Sortie :
    - void
*/
void board::update( void )
{
    //supprime les unités mortes après les combats
    for(long unsigned int i = 0; i < heap.size(); i++ )
    {
        unit* t_unit = (unit*)heap[i];
        if(t_unit->is_dead())
        {
            destroy_card(t_unit);
        }
    }
}

