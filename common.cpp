#include <cstdlib>
#include "common.hpp"

double ea::randFloat() {
    return (rand()) / static_cast <double> (RAND_MAX);
}
