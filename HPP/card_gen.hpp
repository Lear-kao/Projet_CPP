#ifndef CARD_GEN
#define CARD_GEN
#include <SFML/Graphics.hpp>
#include <string.h>

class card_gen
{
    private:
        std::string classe;
        std::string categorie;
        int cost;
        std::string name;

        //librairie graphique
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        void set_classe(std::string c);
        void set_categorie(std::string c);
        void set_name(std::string n);
        bool counter(card_gen ad);
        bool support(card_gen fr);

        //lib_graph
        virtual void render(sf::RenderWindow& window);
        virtual void update();
};

#endif