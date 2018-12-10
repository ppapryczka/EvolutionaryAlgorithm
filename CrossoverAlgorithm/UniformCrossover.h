
#ifndef EVOLUTIONARYALGORITHM_UNIFORMCROSSOVER_H
#define EVOLUTIONARYALGORITHM_UNIFORMCROSSOVER_H


#include "CrossoverAlgorithm.hpp"

namespace ea {
    class UniformCrossover: public CrossoverAlgorithm {
    private:
        void doCrossover(const CardsOwnersVector& parent1, const CardsOwnersVector& parent2,
                         CardsOwnersVector& child1, CardsOwnersVector& child2) const override ;
    };
}


#endif //EVOLUTIONARYALGORITHM_UNIFORMCROSSOVER_H
