#ifndef BOT_HPP
#define BOT_HPP

#include "player.hpp"

class bot : public player{
    private:
        float think_bot = 2; //le temps de réflexion du bot
    public:
        bot();
        int charge_min_hand( void );
        void reset_think( void );
        void add_to_think_bot( float delta );
        float get_think_bot( void );
        bool is_bot( void ) override {return true;}
};

#endif