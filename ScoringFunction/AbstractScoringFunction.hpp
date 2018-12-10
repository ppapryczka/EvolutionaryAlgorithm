#ifndef ABSTRACTSCORINGFUNCTION_HPP
#define ABSTRACTSCORINGFUNCTION_HPP

// ea
#include <bits/unique_ptr.h>
#include "../common.hpp"

namespace ea {
    class AbstractScoringFunction {
    protected:
        unsigned int firstGroupExpected_;
        unsigned int secondGroupExpected_;
        const std::unique_ptr<CardsValueVector> cardValues_;

    public:
        AbstractScoringFunction(unsigned int firstGroupExpected, unsigned int secondGroupExpected,
                                std::unique_ptr<CardsValueVector>&& cardValues);
        virtual int scoreCardsVector(const CardsOwnersVector& cardsOwnersVector) const = 0;
    };
}


#endif //ABSTRACTSCORINGFUNCTION_HPP
