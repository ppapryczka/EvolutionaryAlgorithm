
#ifndef EVOLUTIONARYALGORITHM_POLYNOMALSCORE_H
#define EVOLUTIONARYALGORITHM_POLYNOMALSCORE_H


#include "ScoringFunction.hpp"

namespace ea {
    class PolynomalScore: public ScoringFunction {
    private:
        int power_;
    public:
        PolynomalScore(unsigned int power, unsigned int firstGroupExpected, unsigned int secondGroupExpected,
                                CardsValueVector& cardValues);
        int scoreCardsVector(const CardsOwnersVector& cardsOwnersVector) const override;
    };
}


#endif //EVOLUTIONARYALGORITHM_POLYNOMALSCORE_H
