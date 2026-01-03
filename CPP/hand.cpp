#include "../HPP/hand.hpp"

<<<<<<< Updated upstream
void hand::render(sf::RenderWindow& window)
{
    const int spacing = 43;
    int total_width = (heap.size() - 1) * spacing;
    int start_x = border_x - total_width / 2;

    for(int i = 0; i < heap.size(); i++)
    {
        heap[i]->render(window, start_x + i * spacing, border_y);
    }
    return;
}
=======
>>>>>>> Stashed changes

/* 
Objectif : Constructeur de la class hand
Entrée :
    - un booléen qui sert à savoir si le joueur est un bot.
Sortie :
    - void
*/
hand::hand( bool is_bot )
{
    // determine la position de la main en fonction de si le joueur est un bot ou non
    if(is_bot)
    {
        border_x = MIDDLE_X;
        border_y = 20;
    }
    else 
    {
        border_x = MIDDLE_X;
        border_y = 510;
    }
}

/* 
Objectif : Calculer la position et appeller les méthodes d'affichages de chaques cartes.
Entrée :
    - l'objet d'affichage de sfml
    - un booléen qui sert a savoir si il faut afficher le dos ou la face des cartes.
Sortie :
    - void
*/
void hand::render(sf::RenderWindow& window, bool hidden)
{
    const int spacing = 43;
    int total_width = (heap.size() - 1) * spacing;
    int start_x = border_x - total_width / 2;
    for(int i = 0; i < heap.size(); i++)
    {
        heap[i]->render(window, start_x + i * spacing, border_y, hidden);
    }
    return;
}

/* 
Objectif : Calcule et renvoie si oui ou non la taille maximale de la main est atteinte.
Entrée :
    - void
Sortie :
    - un booléen qui indique si la taille maximale de la main est atteinte.
*/
bool hand::is_max_size( void )
{
    if( heap.size() >= MAX_SIZE )
    {
        return true;
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
void hand::update( void )
{
    //si la taille maximale de la main est atteinte on supprime la dernière carte de la main.
    if(is_max_size())
    {
        heap.erase(heap.begin());
    }
}

