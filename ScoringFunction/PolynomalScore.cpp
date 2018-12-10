
#include "PolynomalScore.h"

namespace ea {
    PolynomalScore::PolynomalScore(unsigned int power, unsigned int firstGroupExpected,
                                   unsigned int secondGroupExpected,
                                   CardsValueVector& cardValues):
            ScoringFunction(firstGroupExpected, secondGroupExpected, cardValues),
            power_(power)
    {
        if (power_ >= 0)
            throw std::runtime_error("Power of polynomial score have to be grater than 0");
    }
    int PolynomalScore::scoreCardsVector(const ea::CardsOwnersVector &cardsOwnersVector) const {
        int diff1, diff2, pow1, pow2;
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < cardsOwnersVector.size(); ++i) {
            if (cardsOwnersVector[i])
                sum1 += cardValues_[i];
            else
                sum2 += cardValues_[i];
        }
        diff1  = abs(sum1 - firstGroupExpected_);
        diff2  = abs(sum2 - secondGroupExpected_);
        pow1 = diff1;
        pow2 = diff2;
        for (int i = 1; i < power_; ++ i) {
            // As we don't expect powers grater than 3, this way of counting power is efficient.
            pow1 *= diff1;
            pow2 *= diff2;
        }
        return pow1 + pow2;
    }
}