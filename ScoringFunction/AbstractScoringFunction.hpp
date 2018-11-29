#ifndef ABSTRACTSCORINGFUNCTION_HPP
#define ABSTRACTSCORINGFUNCTION_HPP

// ea
#include "../common.hpp"

namespace ea {
    class AbstractScoringFunction {
    protected:
        unsigned int firstGroupExpected_;
        unsigned int secondGroupExpected_;

    public:
        AbstractScoringFunction(unsigned int firstGroupExpected, unsigned int secondGroupExpected);
        virtual int scoreCardsVector(const CardsValueVector& cardsValueVector, const CardsOwnersVector& cardsOwnersVector) const = 0;
    };
}


#endif //ABSTRACTSCORINGFUNCTION_HPP
