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
        const unsigned int firstGroupValue_;
        const unsigned int secondGroupValue_;
        std::unique_ptr<AbstractCrossoverAlgorithm> crossoverAlgoritm_;
        std::unique_ptr<AbstractMutation> mutation_;
        std::unique_ptr<AbstractScoringFunction> scoringFunction_;
        std::unique_ptr<AbstractSelectionAlgorithm> selectionAlgorithm_;

    public:
        EvolutionaryAlgorithm(unsigned int firstGroupValue, unsigned int secondGroupValue,
                std::unique_ptr<AbstractCrossoverAlgorithm> crossoverAlgoritm,
                std::unique_ptr<AbstractMutation> mutation,
                std::unique_ptr<AbstractScoringFunction> scoringFunction,
                std::unique_ptr<AbstractSelectionAlgorithm> selectionAlgorithm);

    };
}


#endif //EVOLUTIONARYALGORITHM_HPP
