#ifndef ABSTRACTCROSSOVERALGORITHM_HPP
#define ABSTRACTCROSSOVERALGORITHM_HPP

// ea
#include "../common.hpp"

namespace ea {
    class CrossoverAlgorithm {
    private:
        double probability_;
    protected:
        virtual void doCrossover(const CardsOwnersVector& parent1, const CardsOwnersVector& parent2,
                         CardsOwnersVector& child1, CardsOwnersVector& child2) const = 0;
    public:
        void setProbability(double probability);
        void crossoverCardsVector(Population& selected, Population& newPopul) const;
    };
}

#endif //ABSTRACTCROSSOVERALGORITHM_HPP
