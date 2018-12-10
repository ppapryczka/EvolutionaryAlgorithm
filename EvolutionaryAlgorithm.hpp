#ifndef EVOLUTIONARYALGORITHM_HPP
#define EVOLUTIONARYALGORITHM_HPP

// std
#include <memory>

// ea
#include "CrossoverAlgorithm/CrossoverAlgorithm.hpp"
#include "Mutation/AbstractMutation.hpp"
#include "ScoringFunction/AbstractScoringFunction.hpp"
#include "SelectionAlgorithm/AbstractSelectionAlgorithm.hpp"

namespace ea {
    class EvolutionaryAlgorithm {
    protected:
        Population& population_;
        CardsValueVector& cardsVaules_;
        CrossoverAlgorithm& crossoverAlgorithm_;
        AbstractMutation& mutation_;
        SelectionAlgorithm& selectionAlgorithm_;

    public:
        EvolutionaryAlgorithm(Population &population,
                              CardsValueVector &cardsValues,
                              CrossoverAlgorithm &crossoverAlgorithm,
                              AbstractMutation &mutation,
                              SelectionAlgorithm &selectionAlgorithm);
        void run(unsigned iterNum);

    };
}


#endif //EVOLUTIONARYALGORITHM_HPP
