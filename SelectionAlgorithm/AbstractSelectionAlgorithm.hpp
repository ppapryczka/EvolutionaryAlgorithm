#ifndef ABSTRACTSELECTIONALGORITHM_HPP
#define ABSTRACTSELECTIONALGORITHM_HPP

// ea
#include <bits/unique_ptr.h>
#include "../common.hpp"
#include "../ScoringFunction/ScoringFunction.hpp"

namespace ea {
    class SelectionAlgorithm {
    protected:
        std::unique_ptr<ScoringFunction> scoringFunction_;
    public:
        virtual void selectCandidates(const Population& oldPopul, Population &newPopul) const = 0;
        void setScoring(std::unique_ptr<ScoringFunction> &&scoringFunction);
    };
}

#endif //ABSTRACTSELECTIONALGORITHM_HPP
