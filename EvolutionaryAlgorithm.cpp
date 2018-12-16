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
        // sorting scores vector
        std::sort(scoresVector_.begin(), scoresVector_.end());

        // setting min value
        minDiffValue_ = scoresVector_[0];

        // setting median value
        if(scoresVector_.size()%2 == 1){
            medianValue_ = static_cast<double>(scoresVector_[scoresVector_.size()/2]);
        }
        else {
            medianValue_ = static_cast<double>((scoresVector_[scoresVector_.size()/2] + scoresVector_[scoresVector_.size()/2 - 1])/2);
        }

        // counting average value
        averageValue_ = std::accumulate(scoresVector_.begin(), scoresVector_.end(), 0)/ static_cast<double>(scoresVector_.size());

        // counting standard deviation
        for(auto &score : scoresVector_){
            standardDeviationValue_ += static_cast<double>((score-averageValue_)*(score-averageValue_));
        }

        standardDeviationValue_ = standardDeviationValue_/ static_cast<double>(scoresVector_.size());
        standardDeviationValue_ = std::sqrt(standardDeviationValue_);

        std::cout<<"Scores:"<<std::endl;
        for(auto &score : scoresVector_){
            std::cout<<score<<std::endl;
        }
        std::cout<<"Min value: "<<minDiffValue_<<std::endl;
        std::cout<<"Median: "<<medianValue_<<std::endl;
        std::cout<<"Average: "<<averageValue_<<std::endl;
        std::cout<<"Standard deviation "<<standardDeviationValue_<<std::endl;

        csvFileWriter_.writeEvalutionaryAlgorithmStats(minDiffValue_, medianValue_, averageValue_, standardDeviationValue_);
    }
}