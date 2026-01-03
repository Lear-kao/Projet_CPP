#ifndef BOT_HPP
#define BOT_HPP

#include "player.hpp"

class bot : public player{
    private:
        float think_bot = 2; //le temps de réflexion du bot
        std::vector<card_gen*> carte_prioritaire;
    public:
        bot();
        void reset_think();
        void add_to_think_bot(float delta);
        float get_think_bot();
        bool is_bot() override {return true;}
};

#endif