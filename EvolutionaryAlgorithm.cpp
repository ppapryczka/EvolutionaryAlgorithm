#include "EvolutionaryAlgorithm.hpp"
#include "CSVFileWriter.hpp"

namespace ea{

    // public:

    EvolutionaryAlgorithm::EvolutionaryAlgorithm(Population& population,
                                                 CardsValueVector& cardsValues,
                                                 CrossoverAlgorithm& crossoverAlgorithm,
                                                 AbstractMutation& mutation,
                                                 SelectionAlgorithm& selectionAlgorithm,
                                                 ScoringFunction& scoringFunction,
                                                 CSVFileWriter &csvFileWriter)
         :population_(population),
          cardsVaules_(cardsValues),
          crossoverAlgorithm_(crossoverAlgorithm),
          mutation_(mutation),
          selectionAlgorithm_(selectionAlgorithm),
          scoringFunction_(scoringFunction),
          csvFileWriter_(csvFileWriter)
    {}

    void EvolutionaryAlgorithm::run(unsigned iterNum) {
        Population selected;

        selected.resize(2 * population_.size());
        for (auto&& individual: selected) {
            individual.reserve(population_[0].size()); // Every individual has the same size.
        }


        scorePopulation();

        for (int i = 0; i < iterNum; ++i) {

            selectionAlgorithm_.selectCandidates(population_, selected, scoresVector_);

            for (auto&& individual: population_) {
                // Make space for new population.
                individual.clear();
            }
            crossoverAlgorithm_.crossoverCardsVector(selected, population_);
            for (auto&& individual: selected) {
                // Clear selected, but keep its memory allocated.
                individual.clear();
            }
            mutation_.mutateCardsVector(population_);

            scoringFunction_.scoreCardsVector(population_[0]);

            // log values into csv file
            scorePopulation();
            countAndLogStats();
        }
    }

    // protected:

    void EvolutionaryAlgorithm::scorePopulation() {
        scoresVector_.clear();
        for (unsigned int i = 0; i < population_.size(); ++i) {
            int score = scoringFunction_.scoreCardsVector(population_[i]);
            scoresVector_.push_back(score);
        }
    }

    void EvolutionaryAlgorithm::countAndLogStats() {
        int minDiffValue_;
        double medianValue_;
        double averageValue_;
        double standardDeviationValue_ = 0.0f;

        std::vector<int> scoresVectorCopy = scoresVector_;

        // sorting scores vector
        std::sort(scoresVectorCopy.begin(), scoresVectorCopy.end());

        // setting min value
        minDiffValue_ = scoresVectorCopy[0];

        // setting median value
        if(scoresVectorCopy.size()%2 == 1){
            medianValue_ = static_cast<double>(scoresVectorCopy[scoresVectorCopy.size()/2]);
        }
        else {
            medianValue_ = static_cast<double>((scoresVectorCopy[std::floor(scoresVectorCopy.size()/2)] + scoresVectorCopy[std::floor(scoresVectorCopy.size()/2) + 1])/2.0f);
        }

        // counting average value
        averageValue_ = std::accumulate(scoresVectorCopy.begin(), scoresVectorCopy.end(), 0)/ static_cast<double>(scoresVectorCopy.size());

        // counting standard deviation
        for(auto &score : scoresVectorCopy){
            standardDeviationValue_ += static_cast<double>((score-averageValue_)*(score-averageValue_));
        }

        standardDeviationValue_ = standardDeviationValue_/ static_cast<double>(scoresVectorCopy.size());
        standardDeviationValue_ = std::sqrt(standardDeviationValue_);


        csvFileWriter_.writeEvalutionaryAlgorithmStats(minDiffValue_, medianValue_, averageValue_, standardDeviationValue_);
    }
}