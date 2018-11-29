// std
#include <iostream>

//ea
#include "EvolutionaryAlgorithm.hpp"
#include "CSVFileWriter.hpp"

int main() {
    ea::CSVFileWriter csvFileWriter("dummy.csv", ';');
    std::string bluesBrothers1 = "We are on a mission from God!";
    std::string bluesBrothers2 = "No ma'am. We're musicians.";
    csvFileWriter.dummyStringWrite(bluesBrothers1);
    csvFileWriter.dummyStringWrite(bluesBrothers2);
    return 0;
}