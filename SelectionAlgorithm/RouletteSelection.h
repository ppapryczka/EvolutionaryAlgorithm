#ifndef EVOLUTIONARYALGORITHM_RULETTESELECTION_H
#define EVOLUTIONARYALGORITHM_RULETTESELECTION_H

#include "AbstractSelectionAlgorithm.hpp"

namespace ea {
    class RouletteSelection : public SelectionAlgorithm {
    private:
        double a;
        mutable std::vector<double> scores;

    public:
        explicit RouletteSelection(double a);
        void selectCandidates(const Population& oldPopul, Population &newPopul, const std::vector<int > &scoresVector) const override;
    };
}


#endif //EVOLUTIONARYALGORITHM_RULETTESELECTION_H
