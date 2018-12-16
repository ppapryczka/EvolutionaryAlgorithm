#ifndef EVOLUTIONARYALGORITHM_THRESHOLDSELECTION_HPP
#define EVOLUTIONARYALGORITHM_THRESHOLDSELECTION_HPP


#include "AbstractSelectionAlgorithm.hpp"

namespace ea {
    class ThresholdSelection: public SelectionAlgorithm {
    private:
        using scorePair = std::pair<int, unsigned>;
        unsigned threshold_;
        mutable std::vector<scorePair> scores;
    public:
        explicit ThresholdSelection(unsigned threshold);
        void selectCandidates(const Population& oldPopul, Population &newPopul, const std::vector<int > &scoresVector) const override;
    };
}


#endif //EVOLUTIONARYALGORITHM_THRESHOLDSELECTION_HPP
