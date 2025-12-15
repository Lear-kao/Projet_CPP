#ifndef CARD_GEN
#define CARD_GEN
#include <SFML/Graphics.hpp>
#include <string.h>

class card_gen
{
    private:
        std::string classe;
        std::string categorie;
        std::string name;
        int cost;

    protected:
        //librairie graphique
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        void set_classe(std::string c);//fait
        void set_categorie(std::string c);//fait
        void set_name(std::string n);//fait
        void set_cost(int c);//fait
        bool counter(card_gen *ad);//a faire (Noah)
        bool support(card_gen *fr);//a faire (Noah)

        //lib_graph
        void set_sprite(std::string path);//fait
        virtual void render(sf::RenderWindow& window, int x, int y) = 0;//en cours
        virtual void update() = 0;//a faire(Non attribué)
};

#endif