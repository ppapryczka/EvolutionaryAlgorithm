#include "ScoringFunction.hpp"

ea::ScoringFunction::ScoringFunction(unsigned int firstGroupExpected, unsigned int secondGroupExpected,
                                     CardsValueVector& cardValues):
        firstGroupExpected_(firstGroupExpected),
        secondGroupExpected_(secondGroupExpected),
        cardValues_(cardValues)
{}