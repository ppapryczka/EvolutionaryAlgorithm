#ifndef ABSTRACTSELECTIONALGORITHM_HPP
#define ABSTRACTSELECTIONALGORITHM_HPP

// ea
#include "../common.hpp"

namespace ea {
    class AbstractSelectionAlgorithm {
    public:
        virtual void selectCandidates(const Population& oldPopul, Population &newPopul) const = 0;
    };
}

#endif //ABSTRACTSELECTIONALGORITHM_HPP
