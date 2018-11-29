#ifndef ABSTRACTMUTATION_HPP
#define ABSTRACTMUTATION_HPP

// ea
#include "../common.hpp"

namespace ea {
    class AbstractMutation {
    public:
        virtual void mutateCardsVector(CardsVector& cardsVector) = 0;
    };
}


#endif //ABSTRACTMUTATION_HPP
