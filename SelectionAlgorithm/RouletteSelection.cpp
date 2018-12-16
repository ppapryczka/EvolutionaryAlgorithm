#include "RouletteSelection.h"
#include "../common.hpp"

ea::RouletteSelection::RouletteSelection(double a):
        a(a)
{}

void ea::RouletteSelection::selectCandidates(const ea::Population& oldPopul, ea::Population& newPopul, const std::vector<int > &scoresVector) const {
    /*
     * This method can be implemented as a tree to reduce computational complexity,
     * but this implementation is good enough.
     */
    unsigned currIdx;
    double sum = 0;
    double random;

    scores.reserve(scoresVector.size());

    for (unsigned int i = 0; i < scoresVector.size(); ++i) {
        scores[i] = scoresVector[i] + a;
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
