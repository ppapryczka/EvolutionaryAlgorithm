#include "CrossoverAlgorithm.hpp"

void ea::CrossoverAlgorithm::crossoverCardsVector(ea::Population &selected, ea::Population &newPopul) const {
    auto&& individual = selected.begin();

    for (int i = 0; i < newPopul.size(); ++i) {
        // It there space for only one individual, it can't come form crossover.
        if (randFloat() > probability_ || i == (newPopul.size() - 1)) {
            // Don't crossover this individual.
            newPopul[i] = *individual;
        } else {
            doCrossover(*individual, *(++individual), newPopul[i], newPopul[++i]);
        }
        ++individual;
    }

}
void ea::CrossoverAlgorithm::setProbability(double probability) {
    probability_ = probability;
}
