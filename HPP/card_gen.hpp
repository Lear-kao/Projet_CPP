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
        sf::Texture texture_back;
        sf::Sprite sprite_back;
        
    public:
    //setter
        void set_classe(std::string c);
        void set_categorie(std::string c);
        void set_name(std::string n);
        void set_cost(int c);
        void set_sprite(std::string path);

    //getter
        std::string get_classe(void);
        std::string get_categorie(void);
        int get_cost(void);
        bool counter(card_gen *ad);

    //lib_graph
        sf::Sprite get_sprite(void);
        virtual void render(sf::RenderWindow& window, int x, int y, bool hidden) = 0;
        bool isClicked(sf::Vector2f mouse);
};



#endif