#ifndef COMMON_HPP
#define COMMON_HPP

// std
#include<utility>
#include<vector>

namespace ea{
    using CardsValueVector = std::vector<unsigned int>;
    using CardsOwnersVector = std::vector<bool>;
    using Population = std::vector<CardsOwnersVector>;

    double randFloat();
}

#endif //COMMON_HPP
