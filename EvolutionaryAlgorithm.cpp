#include "EvolutionaryAlgorithm.hpp"

namespace ea{

    // public:

    EvolutionaryAlgorithm::EvolutionaryAlgorithm(Population& population,
                                                 CardsValueVector& cardsValues,
                                                 CrossoverAlgorithm& crossoverAlgorithm,
                                                 AbstractMutation& mutation,
                                                 SelectionAlgorithm& selectionAlgorithm,
                                                 ScoringFunction& scoringFunction)
         :population_(population),
          cardsVaules_(cardsValues),
          crossoverAlgorithm_(crossoverAlgorithm),
          mutation_(mutation),
          selectionAlgorithm_(selectionAlgorithm),
          scoringFunction_(scoringFunction)
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
            for(int i = 0; i < population_.size(); ++i){
                for(int k = 0; k<population_[i].size(); ++k){
                    if(population_[i][k] == true){
                        std::cout<<1;
                    }
                    else{
                        std::cout<<0;
                    }
                }
                std::cout<<std::endl;
            }


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

            // TODO: log values into csv file
            //scorePopulation();
            //std::cout<<"ggg";
            //findMinDiffValue();
            findMinDiffValue();
            std::cout<<minDiffValue_<<std::endl;
            std::cout<<"---------------------"<<std::endl;
            scorePopulation();
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

    void EvolutionaryAlgorithm::findMinDiffValue() {
        std::sort(scoresVector_.begin(), scoresVector_.end());
        minDiffValue_ = scoresVector_[0];
    }

    void EvolutionaryAlgorithm::findMedianValue() {
        if(scoresVector_.size()%2 == 1){
            medianValue_ = scoresVector_[scoresVector_.size()/2];
        }
        else {
            medianValue_ = scoresVector_[scoresVector_.size()/2] - scoresVector_[scoresVector_.size()/2 - 1];
        }
    }

    void EvolutionaryAlgorithm::countStandardDeviationValue() {
        double average = std::accumulate(scoresVector_.begin(), scoresVector_.end(), 0)/scoresVector_.size();

    }
}