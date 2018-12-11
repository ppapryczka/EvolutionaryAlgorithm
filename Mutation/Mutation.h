
#ifndef EVOLUTIONARYALGORITHM_MUTATION_H
#define EVOLUTIONARYALGORITHM_MUTATION_H


#include "AbstractMutation.hpp"

namespace ea {
    class Mutation: public AbstractMutation {
    private:
        double probability_;
    public:
        Mutation(double probability);
        void mutateCardsVector(Population& population) override;
    };
}


#endif //EVOLUTIONARYALGORITHM_MUTATION_H
