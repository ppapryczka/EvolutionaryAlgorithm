#ifndef ABSTRACTMUTATION_HPP
#define ABSTRACTMUTATION_HPP

// ea
#include "../common.hpp"

namespace ea {
    class AbstractMutation {
    public:
        virtual void mutateCardsVector(Population& population) = 0;
    };
}


#endif //ABSTRACTMUTATION_HPP
