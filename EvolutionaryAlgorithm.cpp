#include "EvolutionaryAlgorithm.hpp"

namespace ea{
    EvolutionaryAlgorithm::EvolutionaryAlgorithm(unsigned int firstGroupValue, unsigned int secondGroupValue,
                                                 std::unique_ptr<AbstractCrossoverAlgorithm> crossoverAlgoritm,
                                                 std::unique_ptr<AbstractMutation> mutation,
                                                 std::unique_ptr<AbstractScoringFunction> scoringFunction,
                                                 std::unique_ptr<AbstractSelectionAlgorithm> selectionAlgorithm)
        :firstGroupValue_(firstGroupValue), secondGroupValue_(secondGroupValue), crossoverAlgoritm_(std::move(crossoverAlgoritm)),
        mutation_(std::move(mutation)), scoringFunction_(std::move(scoringFunction)), selectionAlgorithm_(std::move(selectionAlgorithm))
    {}

}