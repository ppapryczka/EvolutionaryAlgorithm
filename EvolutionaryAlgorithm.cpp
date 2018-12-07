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

}