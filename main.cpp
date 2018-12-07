// std
#include <iostream>
#include <getopt.h>

//ea
#include "EvolutionaryAlgorithm.hpp"
#include "CSVFileWriter.hpp"

void csvDummyTest()
{
    ea::CSVFileWriter csvFileWriter("dummy.csv", ';');
    std::string bluesBrothers1 = "We are on a mission from God!";
    std::string bluesBrothers2 = "No ma'am. We're musicians.";
    csvFileWriter.dummyStringWrite(bluesBrothers1);
    csvFileWriter.dummyStringWrite(bluesBrothers2);
}

void printUsage(char *name) {
    std::cerr << "Usage: " << name << " -1 expected -2 expected {-r param | -t param | -h param}\n";
    std::cerr << "\t-m param -v power {-u param | -k param} -s seed -c cards -a number -b probability\n";
    std::cerr << "-1, -2 - values expected on each stack\n";
    std::cerr << "-r, -t, -p - selection algorithm: r = roulette, t = tournament, -h threshold \n";
    std::cerr << "-m - mutation probability \n";
    std::cerr << "-v - target (value) function power\n";
    std::cerr << "-u, -k - mutation algorithm: u = uniform distribution, k - k-point point \n";
    std::cerr << "-s - seed of randomness\n";
    std::cerr << "-c - cards number\n";
    std::cerr << "-a - population size\n";
    std::cerr << "-b - crossover probability\n";
    exit(EXIT_FAILURE);
}

void initPopulation(unsigned cardsNum, unsigned populationSize, std::unique_ptr<ea::CardsValueVector> &cardValuesOut,
                    std::unique_ptr<ea::Population> &populationOut) {
    ea::CardsValueVector cardValues;
    ea::Population population;

    if (cardsNum < 1 || populationSize < 1)
        throw std::runtime_error("Too small population or number of cards");
    cardValues.reserve(cardsNum);
    for (signed i = 0; i < cardsNum; i++) {
        cardValues.emplace_back((rand()%10) + 1);
    }
    population.resize(populationSize);
    for (auto &&individual : population) {
        individual.reserve(cardsNum);
        for (unsigned i = 0; i< cardsNum; i++) {
            individual.emplace_back(rand()%2);
        }
    }
    cardValuesOut = std::make_unique<ea::CardsValueVector>(std::move(cardValues));
    populationOut = std::make_unique<ea::Population>(std::move(population));
}

int main(int argc, char** argv) {
    int opt, expected1, expected2, targetPower;
    unsigned seed, cardsNum, populationSize;
    double crossoverProbability = -1;
    std::unique_ptr<ea::AbstractCrossoverAlgorithm> crossover = nullptr;
    std::unique_ptr<ea::AbstractMutation> mutation = nullptr;
    std::unique_ptr<ea::AbstractScoringFunction> scoringFunction = nullptr;
    std::unique_ptr<ea::AbstractSelectionAlgorithm> selection = nullptr;
    std::unique_ptr<ea::Population> population = nullptr;
    std::unique_ptr<ea::CardsValueVector> cardValues = nullptr;

    seed = (unsigned)time(nullptr);
    expected1 = expected2 = cardsNum = populationSize = 0;

    while ((opt = getopt(argc, argv, "1:2:r:t:h:m:v:u:k:s:c:a:b:")) != -1) {
        switch (opt) {
            case '1':
                expected1 = atoi(optarg);
                break;
            case '2':
                expected2 = atoi(optarg);
                break;
            case 'r':
                if (selection)
                    printUsage(argv[0]);
                //selection = TODO;
                break;
            case 't':
                if (selection)
                    printUsage(argv[0]);
                //selection = TODO;
                break;
            case 'h':
                if (selection)
                    printUsage(argv[0]);
                //selection = TODO;
                break;
            case 'm':
                if (mutation)
                    printUsage(argv[0]);
                //mutation = TODO;
                break;
            case 'v':
                targetPower = atoi(optarg);
                break;
            case 'u':
                if (crossover)
                    printUsage(argv[0]);
                //crossover = TODO;
                break;
            case 'k':
                if (crossover)
                    printUsage(argv[0]);
                //crossover = TODO;
                break;
            case 's':
                seed = atoi(optarg);
                break;
            case 'c':
                cardsNum = atoi(optarg);
                break;
            case 'a':
                populationSize = atoi(optarg);
                break;
            case 'b':
                crossoverProbability = atof(optarg);
            default:
                printUsage(argv[0]);
        }
    }
    // If any of parameters is not set, abort.
    if (!(selection && mutation && crossover && (targetPower > 0)))
        printUsage(argv[0]);
    //scoringFunction = TODO

    srand(seed);
    initPopulation(cardsNum,populationSize, cardValues, population);
    ea::EvolutionaryAlgorithm algorithm(std::move(cardValues), std::move(population), std::move(crossover),
                                        std::move(mutation), std::move(scoringFunction), std::move(selection));
}