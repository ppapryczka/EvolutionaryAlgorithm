#include "RouletteSelection.h"
#include "../common.hpp"

ea::RouletteSelection::RouletteSelection(double a):
        a(a)
{}

void ea::RouletteSelection::selectCandidates(const ea::Population& oldPopul, ea::Population& newPopul) const {
    /*
     * This method can be implemented as a tree to reduce computational complexity,
     * but this implementation is good enough.
     */
    unsigned currIdx;
    double sum = 0;
    double random, score;

    for (auto &&individual: oldPopul) {
        score = scoringFunction_->scoreCardsVector(individual) + a;
        sum += score;
        scores.emplace_back(score);
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
