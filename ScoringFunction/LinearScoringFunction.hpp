#ifndef LINEARSCORINGFUNCTION_HPP
#define LINEARSCORINGFUNCTION_HPP

// ea
#include "AbstractScoringFunction.hpp"

namespace ea {
    class LinearScoringFunction : public AbstractScoringFunction {
    public:
        LinearScoringFunction(unsigned int firstGroupExpected, unsigned int secondGroupExpected);
        int scoreCardsVector(const CardsValueVector& cardsValueVector, const CardsOwnersVector& cardsOwnersVector) const;
    };
}


#endif //LINEARSCORINGFUNCTION_HPP
