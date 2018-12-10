#ifndef EVOLUTIONARYALGORITHM_HPP
#define EVOLUTIONARYALGORITHM_HPP

// std
#include <memory>

// ea
#include "CrossoverAlgorithm/AbstractCrossoverAlgorithm.hpp"
#include "Mutation/AbstractMutation.hpp"
#include "ScoringFunction/AbstractScoringFunction.hpp"
#include "SelectionAlgorithm/AbstractSelectionAlgorithm.hpp"

namespace ea {
    class EvolutionaryAlgorithm {
    protected:
        Population& population_;
        CardsValueVector& cardsVaules_;
        AbstractCrossoverAlgorithm& crossoverAlgorithm_;
        AbstractMutation& mutation_;
        SelectionAlgorithm& selectionAlgorithm_;

    public:
        EvolutionaryAlgorithm(Population &population,
                              CardsValueVector &cardsValues,
                              AbstractCrossoverAlgorithm &crossoverAlgorithm,
                              AbstractMutation &mutation,
                              SelectionAlgorithm &selectionAlgorithm);
        void run(unsigned iterNum);

    };
}


#endif //EVOLUTIONARYALGORITHM_HPP
