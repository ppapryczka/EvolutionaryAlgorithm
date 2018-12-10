#include "AbstractSelectionAlgorithm.hpp"

void ea::SelectionAlgorithm::setScoring(std::unique_ptr<ea::AbstractScoringFunction> &&scoringFunction) {
    scoringFunction_ = std::move(scoringFunction);
}