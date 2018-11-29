#ifndef ABSTRACTSCORINGFUNCTION_HPP
#define ABSTRACTSCORINGFUNCTION_HPP

// ea
#include "../common.hpp"

namespace ea {
    class AbstractScoringFunction {
    public:
        virtual int scoreCardsVector(const CardsVector& cardsVector) const = 0;
    };
}


#endif //ABSTRACTSCORINGFUNCTION_HPP
