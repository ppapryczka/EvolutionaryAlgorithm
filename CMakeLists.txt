cmake_minimum_required(VERSION 3.10)
project(EvolutionaryAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(EvolutionaryAlgorithm main.cpp common.hpp
        EvolutionaryAlgorithm.cpp EvolutionaryAlgorithm.hpp
        ScoringFunction/AbstractScoringFunction.cpp ScoringFunction/AbstractScoringFunction.hpp
        SelectionAlgorithm/AbstractSelectionAlgorithm.cpp SelectionAlgorithm/AbstractSelectionAlgorithm.hpp
        CrossoverAlgorithm/CrossoverAlgorithm.cpp CrossoverAlgorithm/CrossoverAlgorithm.hpp
        Mutation/AbstractMutation.cpp Mutation/AbstractMutation.hpp
        CSVFileWriter.cpp CSVFileWriter.hpp common.cpp SelectionAlgorithm/RouletteSelection.cpp SelectionAlgorithm/RouletteSelection.h CrossoverAlgorithm/UniformCrossover.cpp CrossoverAlgorithm/UniformCrossover.h)