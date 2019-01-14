#include "RouletteSelection.h"
#include "../common.hpp"

ea::RouletteSelection::RouletteSelection(double beta):
        beta(beta)
{}

void ea::RouletteSelection::selectCandidates(const ea::Population& oldPopul, ea::Population& newPopul, const std::vector<int > &scoresVector) const {
    /*
     * This method can be implemented as a tree to reduce computational complexity,
     * but this implementation is good enough.
     */
    unsigned currIdx;
    double sum = 0;
    double random;
    double maxScore = 0;

    scores.reserve(scoresVector.size());

    for (unsigned int i = 0; i < scoresVector.size(); ++i) {
        if (scoresVector[i] > maxScore)
            maxScore = scoresVector[i];
    }
    for (unsigned int i = 0; i < scoresVector.size(); ++i) {
        double sc = std::exp(-beta * (double)scoresVector[i] / maxScore);
        scores[i] = sc;
        sum += scores[i];
    }

    for (int i = 0; i < 2 * oldPopul.size(); ++i) {
        random = randFloat() * sum;
        currIdx = 0;
        do {
            random -= scores[currIdx];
            ++currIdx;
        } while (random > 0);
        newPopul[i] = oldPopul[currIdx - 1];
    }
    scores.clear();
}
