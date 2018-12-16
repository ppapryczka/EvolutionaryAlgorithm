#ifndef ABSTRACTSELECTIONALGORITHM_HPP
#define ABSTRACTSELECTIONALGORITHM_HPP

// ea
#include <bits/unique_ptr.h>
#include "../common.hpp"
#include "../ScoringFunction/ScoringFunction.hpp"

namespace ea {
    class SelectionAlgorithm {

    public:
        virtual void selectCandidates(const Population& oldPopul, Population &newPopul, const std::vector<int > &scoresVector) const = 0;
    };
}

#endif //ABSTRACTSELECTIONALGORITHM_HPP
