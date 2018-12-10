
#include "Mutation.h"

namespace ea{
    Mutation::Mutation(double probability):
            probability_(probability)
    {}
    void Mutation::mutateCardsVector(ea::Population &population) {
        for (auto&& individual: population) {
            for (auto &&cardOwnership: individual) {
                if (randFloat() < probability_)
                    cardOwnership = !cardOwnership;
            }
        }
    }
}
