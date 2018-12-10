#include "EvolutionaryAlgorithm.hpp"

namespace ea{
    EvolutionaryAlgorithm::EvolutionaryAlgorithm(std::unique_ptr<CardsValueVector> cardsValueVector,
                                                 std::unique_ptr<Population> population,
                                                 std::unique_ptr<AbstractCrossoverAlgorithm> crossoverAlgorithm,
                                                 std::unique_ptr<AbstractMutation> mutation,
                                                 std::unique_ptr<AbstractScoringFunction> scoringFunction,
                                                 std::unique_ptr<AbstractSelectionAlgorithm> selectionAlgorithm)
        :cardsValueVector_(std::move(cardsValueVector)),
         population_(std::move(population)),
         crossoverAlgorithm_(std::move(crossoverAlgorithm)),
         mutation_(std::move(mutation)),
         scoringFunction_(std::move(scoringFunction)),
         selectionAlgorithm_(std::move(selectionAlgorithm))
    {}
    void EvolutionaryAlgorithm::run(unsigned iterNum) {
        Population selected;

        selected.resize(2 * population_->size());
        for (auto&& individual: selected) {
            individual.reserve((*population_)[0].size()); // Every individual has the same size.
        }
        for (int i = 0; i < iterNum; ++i) {
            selectionAlgorithm_->selectCandidates(*population_, selected);
            crossoverAlgorithm_->crossoverCardsVector(selected, *population_);
            for (auto &&individual: selected) {
                // Clear selected, but keep its memory allocated.
                individual.clear();
            }
            mutation_->mutateCardsVector(*population_);
            // TODO: log values into csv file
        }
    }

}