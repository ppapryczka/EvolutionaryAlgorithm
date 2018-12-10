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
        std::unique_ptr<Population> population_;
        std::unique_ptr<AbstractCrossoverAlgorithm> crossoverAlgorithm_;
        std::unique_ptr<AbstractMutation> mutation_;
        std::unique_ptr<SelectionAlgorithm> selectionAlgorithm_;

    public:
        EvolutionaryAlgorithm(std::unique_ptr<Population> population,
                              std::unique_ptr<AbstractCrossoverAlgorithm> crossoverAlgorithm,
                              std::unique_ptr<AbstractMutation> mutation,
                              std::unique_ptr<SelectionAlgorithm> selectionAlgorithm);
        void run(unsigned iterNum);

    };
}


#endif //EVOLUTIONARYALGORITHM_HPP
