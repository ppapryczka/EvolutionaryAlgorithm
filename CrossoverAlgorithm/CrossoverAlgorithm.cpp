#include <stdexcept>
#include "CrossoverAlgorithm.hpp"

void ea::CrossoverAlgorithm::crossoverCardsVector(ea::Population &selected, ea::Population &newPopul) const {
    auto individual = selected.begin();
    Population::iterator next;

    for (int idx = 0; idx < newPopul.size(); ++idx) {
        // It there space for only one individual, it can't come form crossover.
        if (randFloat() > probability_ || idx == (newPopul.size() - 1)) {
            // Don't crossover this individual.
            newPopul[idx] = *individual;
        } else {
            next = individual;
            next++;
            if (individual->size() != next->size())
                throw std::runtime_error("Individuals must wave the same size.");
            doCrossover(*individual, *(next), newPopul[idx], newPopul[idx + 1]);
            ++individual;
            ++idx;
        }
        ++individual;
    }

}
void ea::CrossoverAlgorithm::setProbability(double probability) {
    probability_ = probability;
}
