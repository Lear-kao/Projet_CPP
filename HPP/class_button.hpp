#ifndef BUTTON_CLASS_HPP
#define BUTTON_CLASS_HPP

#include <string>
#include <SFML/Graphics.hpp>


/* 
Objectif : Représenter des bouttons dans le jeu pour plus facilement 
intéragir avec l'interface.
POint à améliorer, en faire un héritier de UI permettrais d'étendre les possibilités que la class offre.
*/
class gen_button
{
    private:
        std::string name;
        std::pair<int,int> localisation;    
    protected:
        //librairie graphique
        sf::Texture texture;
        sf::Sprite sprite;
    public: 
        gen_button(std::string path);
        void set_loc(int x, int y);
        std::pair<int,int> get_loc( void );
        void render(sf::RenderWindow& window);
        sf::Sprite get_sprite( void );
};

#endif