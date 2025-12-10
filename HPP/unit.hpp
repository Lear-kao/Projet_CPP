#include "card_gen.hpp"

class unit: public card_gen
{
    private: 
        int strenght;
        int stamina;
    public:
        unit(int cost);
        int get_strenght(void);
        int get_stamina(void);
};