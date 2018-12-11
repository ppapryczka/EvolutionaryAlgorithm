#include "AbstractSelectionAlgorithm.hpp"

void ea::SelectionAlgorithm::setScoring(std::unique_ptr<ea::ScoringFunction> &&scoringFunction) {
    scoringFunction_ = std::move(scoringFunction);
}