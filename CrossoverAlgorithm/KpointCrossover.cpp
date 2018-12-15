#include <algorithm>
#include <stdexcept>
#include "KpointCrossover.h"

namespace ea {
    KpointCrossover::KpointCrossover(unsigned k):
        k_(k)
    {}
    void KpointCrossover::doCrossover(const ea::CardsOwnersVector &parent1, const ea::CardsOwnersVector &parent2,
                                      ea::CardsOwnersVector &child1, ea::CardsOwnersVector &child2) const {
        bool swap = false;
        std::vector<unsigned> cutIdx;

        if (parent1.size() != parent2.size())
            throw std::runtime_error("In doCrossover parents must have the same size.");

        cutIdx.reserve(k_);
        for (unsigned i = 0; i < k_; ++i) {
            cutIdx.emplace_back((unsigned)(randFloat() * k_));
        }
        std::sort(cutIdx.begin(), cutIdx.end());
        auto &&cutIter = cutIdx.begin();
        for (unsigned i = 0; i < parent1.size(); ++i) {
            while (*cutIter == i) { // The same cut index may occur few times.
                swap = !swap;
                ++cutIter;
            }
            if (swap) {
                child1.emplace_back(parent1[i]);
                child2.emplace_back(parent2[i]);
            } else {
                child1.emplace_back(parent2[i]);
                child2.emplace_back(parent1[i]);
            }
        }
    }
}