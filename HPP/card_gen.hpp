#ifndef CARD_GEN
#define CARD_GEN

#include <SFML/Graphics.hpp>
#include <string>
#include <cstring> //Pour utiliser strcomp

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
        std::string get_classe(void);
        void set_classe(std::string c);//fait
        void set_categorie(std::string c);//fait
        std::string get_categorie(void);
        void set_name(std::string n);//fait
        void set_cost(int c);//fait
        int get_cost(void);//fait
        bool counter(card_gen *ad);//a faire (Noah)
        bool support(card_gen *fr);//a faire (Noah)

        //lib_graph
        void set_sprite(std::string path);//fait
        sf::Sprite get_sprite(void);
        virtual void render(sf::RenderWindow& window, int x, int y) = 0;//en cours
        //virtual void update() = 0;//a faire(Non attribué)
        bool isClicked(sf::Vector2f mouse);
};



#endif