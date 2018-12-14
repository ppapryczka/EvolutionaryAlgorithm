//
// Created by michal on 14.12.18.
//

#ifndef EVOLUTIONARYALGORITHM_KPOINTCROSSOVER_H
#define EVOLUTIONARYALGORITHM_KPOINTCROSSOVER_H


#include "CrossoverAlgorithm.hpp"

namespace ea {
    class KpointCrossover: public CrossoverAlgorithm {
    private:
        unsigned k_;
        void doCrossover(const CardsOwnersVector& parrent1, const CardsOwnersVector& parrent2,
                                 CardsOwnersVector& child1, CardsOwnersVector& child2) const override;
    public:
        explicit KpointCrossover(unsigned k);
    };
}


#endif //EVOLUTIONARYALGORITHM_KPOINTCROSSOVER_H
