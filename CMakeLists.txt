cmake_minimum_required(VERSION 3.12)
project(EvolutionaryAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(EvolutionaryAlgorithm main.cpp common.hpp
        EvolutionaryAlgorithm.cpp EvolutionaryAlgorithm.hpp
        ScoringFunction/AbstractScoringFunction.cpp ScoringFunction/AbstractScoringFunction.hpp
        SelectionAlgorithm/AbstractSelectionAlgorithm.cpp SelectionAlgorithm/AbstractSelectionAlgorithm.hpp
        SelectionAlgorithm/LinearScoringFunction.cpp SelectionAlgorithm/LinearScoringFunction.hpp
        CrossoverAlgorithm/AbstractCrossoverAlgorithm.cpp CrossoverAlgorithm/AbstractCrossoverAlgorithm.hpp
        Mutation/AbstractMutation.cpp Mutation/AbstractMutation.hpp
        CSVFileWriter.cpp CSVFileWriter.hpp)