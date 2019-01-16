#include "ScoringFunction.hpp"

ea::ScoringFunction::ScoringFunction(int firstGroupExpected, int secondGroupExpected,
                                     CardsValueVector& cardValues):
        firstGroupExpected_(firstGroupExpected),
        secondGroupExpected_(secondGroupExpected),
        cardValues_(cardValues)
{}