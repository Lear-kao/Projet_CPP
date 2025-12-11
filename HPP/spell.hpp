#include "card_gen.hpp"

class sort: public card_gen
{
    private: 
        int value_effect;
    public:
        sort(int v_e);
};