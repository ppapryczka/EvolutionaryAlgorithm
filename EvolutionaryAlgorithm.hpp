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
#include "CSVFileWriter.hpp"

namespace ea {
    class EvolutionaryAlgorithm {
    protected:
        Population& population_;
        CardsValueVector& cardsVaules_;
        CrossoverAlgorithm& crossoverAlgorithm_;
        AbstractMutation& mutation_;
        SelectionAlgorithm& selectionAlgorithm_;
        ScoringFunction& scoringFunction_;
        CSVFileWriter& csvFileWriter_;

        std::vector<int > scoresVector_;
        int minDiffValue_;
        double medianValue_;
        double averageValue_;
        double standardDeviationValue_;

    protected:
        void scorePopulation();
        void countAndLogStats();

    public:
        EvolutionaryAlgorithm(Population &population,
                              CardsValueVector &cardsValues,
                              CrossoverAlgorithm &crossoverAlgorithm,
                              AbstractMutation &mutation,
                              SelectionAlgorithm &selectionAlgorithm,
                              ScoringFunction &scoringFunction,
                              CSVFileWriter &csvFileWriter);
        void run(unsigned iterNum);

    };
}


#endif //EVOLUTIONARYALGORITHM_HPP
