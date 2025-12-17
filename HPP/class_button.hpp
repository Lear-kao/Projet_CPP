#ifndef BUTTON_CLASS_HPP
#define BUTTON_CLASS_HPP

#include <string>
#include <SFML/Graphics.hpp>

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
        void set_loc(int x, int y);
        std::pair<int,int> get_loc( void );
        void render(sf::RenderWindow& window);
};

#endif