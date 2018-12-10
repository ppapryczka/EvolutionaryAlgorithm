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
        const std::unique_ptr<CardsValueVector> cardsValueVector_;
        std::unique_ptr<Population> population_;
        std::unique_ptr<AbstractCrossoverAlgorithm> crossoverAlgorithm_;
        std::unique_ptr<AbstractMutation> mutation_;
        std::unique_ptr<AbstractScoringFunction> scoringFunction_; //TODO: remove it, it should be part of selection
        std::unique_ptr<AbstractSelectionAlgorithm> selectionAlgorithm_;

    public:
        EvolutionaryAlgorithm(std::unique_ptr<CardsValueVector> cardsValueVector,
                              std::unique_ptr<Population> population,
                              std::unique_ptr<AbstractCrossoverAlgorithm> crossoverAlgorithm,
                              std::unique_ptr<AbstractMutation> mutation,
                              std::unique_ptr<AbstractScoringFunction> scoringFunction,
                              std::unique_ptr<AbstractSelectionAlgorithm> selectionAlgorithm);
        void run(unsigned iterNum);

    };
}


#endif //EVOLUTIONARYALGORITHM_HPP
