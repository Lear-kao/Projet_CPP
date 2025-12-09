#ifndef CARD_GEN
#define CARD_GEN
#include <SFML/Graphics.hpp>
#include <string.h>

class card_gen
{
    private:
        bool type;
        bool d_o_a;
        int cost;
        std::string name;

        //librairie graphique
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        void set_type(bool t)
        {
            type = t;
        }
        void set_name(std::string n)
        {
            name.append(n);
        }

        virtual void render(sf::RenderWindow& window);
};

#endif