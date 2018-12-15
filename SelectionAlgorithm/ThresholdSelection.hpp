#ifndef EVOLUTIONARYALGORITHM_THRESHOLDSELECTION_HPP
#define EVOLUTIONARYALGORITHM_THRESHOLDSELECTION_HPP


#include "AbstractSelectionAlgorithm.hpp"

namespace ea {
    class ThresholdSelection: public SelectionAlgorithm {
    private:
        unsigned threshold_;
    public:
        explicit ThresholdSelection(unsigned threshold);
        void selectCandidates(const Population& oldPopul, Population &newPopul) const override;
    };
}


#endif //EVOLUTIONARYALGORITHM_THRESHOLDSELECTION_HPP
