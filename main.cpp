// std
#include <iostream>
#include <getopt.h>
#include <list>

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

std::vector<bool> decimalToBinaryNumber(int x, int n)
{
    int* binaryNumber = new int(x);
    int i = 0;
    std::vector<bool> ret;

    while (x > 0) {
        binaryNumber[i] = x % 2;
        x = x / 2;
        i++;
    }

    // leftmost digits are filled with 0
    for (int j = 0; j < n - i; j++)
        ret.emplace_back(false);
 //       std::cout << '0';

    for (int j = i - 1; j >= 0; j--) {
        if (binaryNumber[j] > 0) {
            ret.emplace_back(true);
        } else {
            ret.emplace_back(false);
        }
    }
    return ret;
//        std::cout << binaryNumber[j];
}

void generateGrayarr(ea::CardsValueVector& scoresVector, ea::ScoringFunction* sf)
{
    int n = scoresVector.size();
    int N = 1 << n;
    int min = INT32_MAX;
    std::vector<bool> ret;

    for (int i = 0; i < N; i++) {

        // generate gray code of corresponding
        // binary number of integer i.
        int x = i ^ (i >> 1);

        // printing gray code
        ret = decimalToBinaryNumber(x, n);

        {
            min = std::min(min, sf->scoreCardsVector(ret));

        }

        for (auto k : ret) {
            std::cout << k << " ";
        }
        std::cout << std::endl;
    }
    std::cout<<min<<std::endl;
}

void findMin(ea::CardsValueVector& scoresVector, ea::ScoringFunction* sf){
    std::vector<bool> ownersVector;

    int min = INT32_MAX;

    for(int i =0; i<scoresVector.size(); ++i) {
        ownersVector.emplace_back(false);
    }

    min = std::min(min, sf->scoreCardsVector(ownersVector));

    for(int i = 0; i<scoresVector.size(); ++i) {
        ownersVector[i] = true;

        std::vector<uint8_t > tmpV;
        for(auto own :ownersVector){
            tmpV.emplace_back(own);
        }

        do{
            std::vector<bool> tmp2;
            for(auto own: tmpV){
                tmp2.emplace_back(own);
            }
            min = std::min(min, sf->scoreCardsVector(tmp2));
        }while(std::next_permutation(tmpV.begin(), tmpV.end()));
    }

    std::cout<<min<<std::endl;
}

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
        cardValues.emplace_back((rand()%1000) + 1);
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

        //generateGrayarr(*cardValues, scoringFunction.get());
 //       findMin(*cardValues, scoringFunction.get());

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