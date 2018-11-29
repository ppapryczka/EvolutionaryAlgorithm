#ifndef ABSTRACTSELECTIONALGORITHM_HPP
#define ABSTRACTSELECTIONALGORITHM_HPP

// ea
#include "../common.hpp"

namespace ea {
    class AbstractSelectionAlgorithm {
    public:
        virtual CardsVector selectCandidates(const CardsVector& cardsVector) const = 0;
    };
}

#endif //ABSTRACTSELECTIONALGORITHM_HPP
