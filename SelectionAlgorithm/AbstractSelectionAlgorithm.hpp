#ifndef ABSTRACTSELECTIONALGORITHM_HPP
#define ABSTRACTSELECTIONALGORITHM_HPP

// ea
#include "../common.hpp"

namespace ea {
    class AbstractSelectionAlgorithm {
    public:
        virtual Population selectCandidates(const Population& population) const = 0;
    };
}

#endif //ABSTRACTSELECTIONALGORITHM_HPP
