#ifndef EVOLUTIONARYALGORITHM_TOURNAMENTSELECTION_HPP
#define EVOLUTIONARYALGORITHM_TOURNAMENTSELECTION_HPP

#include "AbstractSelectionAlgorithm.hpp"

namespace ea {
    class TournamentSelection: public SelectionAlgorithm {
    private:
        unsigned tournamentSize_;
    public:
        explicit TournamentSelection(unsigned tournamentSize);
        void selectCandidates(const Population& oldPopul, Population &newPopul) const override;
    };
}


#endif //EVOLUTIONARYALGORITHM_TOURNAMENTSELECTION_HPP
