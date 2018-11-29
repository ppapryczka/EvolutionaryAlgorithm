#ifndef ABSTRACTCROSSOVERALGORITHM_HPP
#define ABSTRACTCROSSOVERALGORITHM_HPP

// ea
#include "../common.hpp"

namespace ea {
    class AbstractCrossoverAlgorithm {
    public:
        virtual void crossoverCardsVector(Population& population) const = 0;
    };
}

#endif //ABSTRACTCROSSOVERALGORITHM_HPP
