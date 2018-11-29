#ifndef ABSTRACTCROSSOVERALGORITHM_HPP
#define ABSTRACTCROSSOVERALGORITHM_HPP

// ea
#include "../common.hpp"

namespace ea {
    class AbstractCrossoverAlgorithm {
    public:
        virtual void crossoverCardsVector(CardsVector& cardsVector) const = 0;
    };
}

#endif //ABSTRACTCROSSOVERALGORITHM_HPP
