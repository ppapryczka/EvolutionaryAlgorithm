#ifndef ABSTRACTSCORINGFUNCTION_HPP
#define ABSTRACTSCORINGFUNCTION_HPP

// ea
#include <bits/unique_ptr.h>
#include "../common.hpp"

namespace ea {
    class ScoringFunction {
    protected:
        int firstGroupExpected_;
        int secondGroupExpected_;
        const CardsValueVector& cardValues_;

    public:
        ScoringFunction(int firstGroupExpected, int secondGroupExpected,
                                CardsValueVector& cardValues);
        virtual int scoreCardsVector(const CardsOwnersVector& cardsOwnersVector) const = 0;
    };
}


#endif //ABSTRACTSCORINGFUNCTION_HPP
