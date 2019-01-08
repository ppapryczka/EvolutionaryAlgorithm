#ifndef EVOLUTIONARYALGORITHM_RULETTESELECTION_H
#define EVOLUTIONARYALGORITHM_RULETTESELECTION_H

#include "AbstractSelectionAlgorithm.hpp"

#include <algorithm>

namespace ea {
    class RouletteSelection : public SelectionAlgorithm {
    private:
        double beta;
        mutable std::vector<double> scores;

    public:
        explicit RouletteSelection(double beta);
        void selectCandidates(const Population& oldPopul, Population &newPopul, const std::vector<int > &scoresVector) const override;
    };
}


#endif //EVOLUTIONARYALGORITHM_RULETTESELECTION_H
