// std
#include <iostream>
#include <getopt.h>

//ea
#include "EvolutionaryAlgorithm.hpp"
#include "CSVFileWriter.hpp"
#include "SelectionAlgorithm/RouletteSelection.h"
#include "CrossoverAlgorithm/UniformCrossover.h"
#include "ScoringFunction/PolynomalScore.h"
#include "Mutation/Mutation.h"
#include "CrossoverAlgorithm/KpointCrossover.h"
#include "SelectionAlgorithm/ThresholdSelection.hpp"
#include "SelectionAlgorithm/TournamentSelection.hpp"

void csvDummyTest(){
    ea::CSVFileWriter csvFileWriter("dummy.csv", ';');
    std::string bluesBrothers1 = "We are on a mission from God!";
    std::string bluesBrothers2 = "No ma'am. We're musicians.";
    csvFileWriter.dummyStringWrite(bluesBrothers1);
    csvFileWriter.dummyStringWrite(bluesBrothers2);
}

void printUsage(char *name) {
    std::cerr << "Usage: " << name << " -1 expected -2 expected {-r param | -t param | -h param}\n";
    std::cerr << "\t-m param -v power {-u | -k param} -s seed -c cards -a number -b probability -i iterations\n";
    std::cerr << "-1, -2 - values expected on each stack\n";
    std::cerr << "-r, -t, -p - selection algorithm: r = roulette, t = tournament, -h threshold \n";
    std::cerr << "-m - mutation probability \n";
    std::cerr << "-v - target (value) function power\n";
    std::cerr << "-u, -k - crossover algorithm: u = uniform distribution, k - k-point point \n";
    std::cerr << "-s - seed of randomness\n";
    std::cerr << "-c - cards number\n";
    std::cerr << "-a - population size\n";
    std::cerr << "-b - crossover probability\n";
    std::cerr << "-i - iterations number\n";
    std::cerr << "-f - output file name\n";
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
    try {
        int opt, expected1, expected2, targetPower;
        unsigned seed, cardsNum, populationSize, iterations;
        double crossoverProbability = -1;
        std::string fileName, commandName;
        std::unique_ptr<ea::CrossoverAlgorithm> crossover = nullptr;
        std::unique_ptr<ea::AbstractMutation> mutation = nullptr;
        std::unique_ptr<ea::ScoringFunction> scoringFunction = nullptr;
        std::unique_ptr<ea::SelectionAlgorithm> selection = nullptr;
        std::unique_ptr<ea::Population> population = nullptr;
        std::unique_ptr<ea::CardsValueVector> cardValues = nullptr;

        seed = (unsigned) time(nullptr);
        expected1 = expected2 = cardsNum = populationSize = iterations = 0;

        while ((opt = getopt(argc, argv, "1:2:r:t:h:m:v:uk:s:c:a:b:i:f:")) != -1) {
            switch (opt) {
                case '1':
                    expected1 = atoi(optarg);
                    fileName +="_-1_";
                    fileName +=optarg;
                    break;
                case '2':
                    expected2 = atoi(optarg);
                    fileName +="_-2_";
                    fileName +=optarg;
                    break;
                case 'r':
                    if (selection)
                        printUsage(argv[0]);
                    selection = std::make_unique<ea::RouletteSelection>(ea::RouletteSelection(atof(optarg)));
                    fileName +="_-r_";
                    fileName +=optarg;
                    break;
                case 't':
                    if (selection)
                        printUsage(argv[0]);
                    selection = std::make_unique<ea::TournamentSelection>(ea::TournamentSelection(atoi(optarg)));
                    fileName +="_-t_";
                    fileName +=optarg;
                    break;
                case 'h':
                    if (selection)
                        printUsage(argv[0]);
                    selection = std::make_unique<ea::ThresholdSelection>(ea::ThresholdSelection(atoi(optarg)));
                    fileName +="_-h_";
                    fileName +=optarg;
                    break;
                case 'm':
                    if (mutation)
                        printUsage(argv[0]);
                    mutation = std::make_unique<ea::Mutation>(ea::Mutation(atof(optarg)));
                    fileName +="_-m_";
                    fileName +=optarg;
                    break;
                case 'v':
                    targetPower = atoi(optarg);
                    fileName +="_-v_";
                    fileName +=optarg;
                    break;
                case 'u':
                    if (crossover)
                        printUsage(argv[0]);
                    crossover = std::make_unique<ea::UniformCrossover>(ea::UniformCrossover());
                    fileName +="_-u";
                    break;
                case 'k':
                    if (crossover)
                        printUsage(argv[0]);
                    crossover = std::make_unique<ea::KpointCrossover>(ea::KpointCrossover(atoi(optarg)));
                    fileName +="_-k_";
                    fileName +=optarg;
                    break;
                case 's':
                    seed = atoi(optarg);
                    fileName +="_-s_";
                    fileName +=optarg;
                    break;
                case 'c':
                    cardsNum = atoi(optarg);
                    fileName +="_-c_";
                    fileName +=optarg;
                    break;
                case 'a':
                    populationSize = atoi(optarg);
                    fileName +="_-a_";
                    fileName +=optarg;
                    break;
                case 'b':
                    crossoverProbability = atof(optarg);
                    fileName +="_-b_";
                    fileName +=optarg;
                    break;
                case 'i':
                    iterations = atoi(optarg);
                    fileName +="_-i_";
                    fileName +=optarg;
                    break;
                case 'f':
                    fileName = optarg + fileName;
                    break;
                default:
                    printUsage(argv[0]);
            }
        }
        srand(seed);
        initPopulation(cardsNum, populationSize, cardValues, population);
        // If any of parameters is not set, abort.
        if (!(selection && mutation && crossover && (targetPower > 0) && fileName!=""))
            printUsage(argv[0]);
        scoringFunction = std::make_unique<ea::PolynomalScore>(ea::PolynomalScore(targetPower, expected1,
                                                                                  expected2, *cardValues));

        if (crossoverProbability < 0 || crossoverProbability > 1)
            printUsage(argv[0]);
        crossover->setProbability(crossoverProbability);

        ea::CSVFileWriter csvFileWriter(fileName+".csv", ',');

        ea::EvolutionaryAlgorithm algorithm(*population, *cardValues, *crossover,
                                            *mutation, *selection, *scoringFunction, csvFileWriter);

        algorithm.run(iterations);

        std::cout<<"Done. Result stored in:\n"+fileName+".csv\n";
    }
    catch (std::exception &ex){
        std::cout<<ex.what()<<std::endl;
    }

    return 0;
}