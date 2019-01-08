#include <algorithm>
#include "ThresholdSelection.hpp"

namespace ea {


    ThresholdSelection::ThresholdSelection(unsigned threshold):
            threshold_(threshold)
    {}
    void ThresholdSelection::selectCandidates(const ea::Population &oldPopul, ea::Population &newPopul, const std::vector<int > &scoresVector) const {
        unsigned selectedIdx, selectedScoreIdx;

        if (2 * oldPopul.size() != newPopul.size())
            throw std::runtime_error("Wrong size of at least one population in selection.");

        scores.reserve(oldPopul.size());
        for (unsigned i = 0; i < oldPopul.size(); ++i) {
            scores.emplace_back(std::make_pair(scoresVector[i], i));
            //scores.emplace_back(scoringFunction_->scoreCardsVector(oldPopul[i]), i);
        }
        std::sort(scores.begin(), scores.end(), std::less<>());// Sort in decreasing order.
        for (unsigned i = 0; i < newPopul.size(); ++i) {
            selectedScoreIdx = (unsigned)(randFloat() * (threshold_ - 1));
            selectedIdx = scores[scores.size() - selectedScoreIdx - 1].second;
            newPopul[i] = oldPopul[selectedIdx];
        }
        scores.clear();
    }
}
