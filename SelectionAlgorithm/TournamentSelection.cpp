#include <climits>
#include "TournamentSelection.hpp"

namespace ea {
    TournamentSelection::TournamentSelection(unsigned tournamentSize):
        tournamentSize_(tournamentSize)
    {}
    void TournamentSelection::selectCandidates(const ea::Population &oldPopul, ea::Population &newPopul, const std::vector<int > &scoresVector) const {
        unsigned currIdx, bestIdx;
        int currScore, worstScore;

        if (2 * oldPopul.size() != newPopul.size())
            throw std::runtime_error("Wrong size of at least one population in selection.");
        for (auto& individual : newPopul) {
            bestIdx = 0;
            worstScore = INT_MAX;
            for (int i = 0; i < tournamentSize_; ++i) {
                currIdx = (unsigned) (randFloat() * (oldPopul.size() - 1));
                currScore = scoresVector[currIdx];
                if (currScore < worstScore) {
                    bestIdx = currIdx;
                    worstScore = currScore;
                }
            }
            individual = oldPopul[bestIdx];
        }
    }
}