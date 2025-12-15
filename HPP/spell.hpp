#ifndef SPELL_HPP
#define SPELL_HPP

#include "card_gen.hpp"

class sort: public card_gen
{
    private: 
        int value_effect;
    public:
        sort(int v_e);
};

#endif