#include <climits>
#include "TournamentSelection.hpp"

namespace ea {
    TournamentSelection::TournamentSelection(unsigned tournamentSize):
        tournamentSize_(tournamentSize)
    {}
    void TournamentSelection::selectCandidates(const ea::Population &oldPopul, ea::Population &newPopul) const {
        unsigned currIdx, bestIdx;
        int currScore, bestScore;

        if (2 * oldPopul.size() != newPopul.size())
            throw std::runtime_error("Wrong size of at least one population in selection.");
        for (auto& individual : newPopul) {
            bestIdx = 0;
            bestScore = INT_MIN;
            for (int i = 0; i < tournamentSize_; ++i) {
                currIdx = (unsigned) (randFloat() * (oldPopul.size() - 1));
                currScore = scoringFunction_->scoreCardsVector(oldPopul[currIdx]);
                if (currScore > bestScore) {
                    bestIdx = currIdx;
                    bestScore = currScore;
                }
            }
            individual = oldPopul[bestIdx];
        }
    }
}