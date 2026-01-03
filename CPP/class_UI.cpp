#include "../HPP/class_UI.hpp"

/* 
Objectif : Constructeur de la class UI.
Entrée :
    - void
Sortie : 
    - void
*/
UI::UI()
{
    // charge la police d'écriture et d'autre éléments de font
    if (!font.loadFromFile("DOC/arial.ttf")){
        return;
    }
    texte.setFont(font);
    texte.setCharacterSize(16);
    texte.setFillColor(sf::Color::White);
}

/* 
Objectif : Affiche l'élément visuel contenu dans la classe.
Entrée :
    - Une chaine de charactère à afficher.
    - L'objet sfml correspondant à la fenêtre.
Sortie : 
    - void
*/
void UI::render( std::string text_, sf::RenderWindow& window)
{
    texte.setString(text_);
    window.draw(texte);
}

/* 
Objectif : Le setter de la position de l'élément visuel.
Entrée :
    - Deux flotant x et y.
Sortie : 
    - void
*/
void UI::set_position(float x, float y)
{
    texte.setPosition(x, y);
}