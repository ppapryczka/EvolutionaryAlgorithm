
#include <stdexcept>
#include "UniformCrossover.h"

void ea::UniformCrossover::doCrossover(const ea::CardsOwnersVector &parent1, const ea::CardsOwnersVector &parent2,
                                         ea::CardsOwnersVector &child1, ea::CardsOwnersVector &child2) const {
    auto&& parent1iter = parent1.begin();
    auto&& parent2iter = parent2.begin();
    for (; parent1iter != parent1.end() && parent2iter != parent2.end(); ++parent1iter, ++parent2iter) {
        if (randFloat() > 0.5) {
            child1.emplace_back(*parent1iter);
            child2.emplace_back(*parent2iter);
        } else {
            child1.emplace_back(*parent2iter);
            child2.emplace_back(*parent1iter);
        }
    }
    if (!(parent1iter == parent1.end() && parent2iter == parent2.end()))
        throw std::runtime_error("Wrong parent sizes in crossover.");
}
