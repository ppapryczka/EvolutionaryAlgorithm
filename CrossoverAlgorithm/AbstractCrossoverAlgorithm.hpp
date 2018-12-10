#ifndef ABSTRACTCROSSOVERALGORITHM_HPP
#define ABSTRACTCROSSOVERALGORITHM_HPP

// ea
#include "../common.hpp"

namespace ea {
    class AbstractCrossoverAlgorithm {
    public:
        virtual void crossoverCardsVector(Population& selected, Population &newPopul) const = 0;
    };
}

#endif //ABSTRACTCROSSOVERALGORITHM_HPP
