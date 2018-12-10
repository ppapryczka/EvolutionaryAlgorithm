#ifndef EVOLUTIONARYALGORITHM_RULETTESELECTION_H
#define EVOLUTIONARYALGORITHM_RULETTESELECTION_H

#include "AbstractSelectionAlgorithm.hpp"

namespace ea {
    class RouletteSelection : public SelectionAlgorithm {
    private:
        double a;

        mutable std::vector<double> scores; //This one exist only to avoid reallocating memory.
    public:
        explicit RouletteSelection(double a);
        void selectCandidates(const Population& oldPopul, Population &newPopul) const override;
    };
}


#endif //EVOLUTIONARYALGORITHM_RULETTESELECTION_H
