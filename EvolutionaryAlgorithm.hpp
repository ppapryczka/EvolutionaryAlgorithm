#ifndef EVOLUTIONARYALGORITHM_HPP
#define EVOLUTIONARYALGORITHM_HPP

// std
#include <memory>
#include <algorithm>
#include <iostream>

// ea
#include "CrossoverAlgorithm/CrossoverAlgorithm.hpp"
#include "Mutation/AbstractMutation.hpp"
#include "ScoringFunction/ScoringFunction.hpp"
#include "SelectionAlgorithm/AbstractSelectionAlgorithm.hpp"

namespace ea {
    class EvolutionaryAlgorithm {
    protected:
        Population& population_;
        CardsValueVector& cardsVaules_;
        CrossoverAlgorithm& crossoverAlgorithm_;
        AbstractMutation& mutation_;
        SelectionAlgorithm& selectionAlgorithm_;
        ScoringFunction& scoringFunction_;

        std::vector<int > scoresVector_;
        int minDiffValue_;
        int medianValue_;
        int standardDeviationValue_;

    protected:
        void scorePopulation();
        void countStats();
        void logStats();

        void findMinDiffValue();
        void findMedianValue();
        void countStandardDeviationValue();



    public:
        EvolutionaryAlgorithm(Population &population,
                              CardsValueVector &cardsValues,
                              CrossoverAlgorithm &crossoverAlgorithm,
                              AbstractMutation &mutation,
                              SelectionAlgorithm &selectionAlgorithm,
                              ScoringFunction &scoringFunction);
        void run(unsigned iterNum);

    };
}


#endif //EVOLUTIONARYALGORITHM_HPP
