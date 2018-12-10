#include "EvolutionaryAlgorithm.hpp"

namespace ea{
    EvolutionaryAlgorithm::EvolutionaryAlgorithm(Population& population,
                                                 CardsValueVector& cardsValues,
                                                 CrossoverAlgorithm& crossoverAlgorithm,
                                                 AbstractMutation& mutation,
                                                 SelectionAlgorithm& selectionAlgorithm)
         :population_(population),
          cardsVaules_(cardsValues),
          crossoverAlgorithm_(crossoverAlgorithm),
          mutation_(mutation),
          selectionAlgorithm_(selectionAlgorithm)
    {}
    void EvolutionaryAlgorithm::run(unsigned iterNum) {
        Population selected;

        selected.resize(2 * population_.size());
        for (auto&& individual: selected) {
            individual.reserve(population_[0].size()); // Every individual has the same size.
        }
        for (int i = 0; i < iterNum; ++i) {
            selectionAlgorithm_.selectCandidates(population_, selected);
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
            // TODO: log values into csv file
        }
    }

}