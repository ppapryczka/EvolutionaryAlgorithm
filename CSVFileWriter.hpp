#ifndef CSVFILEWRITER_HPP
#define CSVFILEWRITER_HPP

// std
#include <fstream>
#include <string>

namespace ea {
    class CSVFileWriter {
    protected:
        char separator_;
        std::string fileName_;
        std::ofstream ofstreamFile_;

        void writeNextLine();

    public:
        CSVFileWriter(std::string fileName, char separator);
        void dummyStringWrite(const std::string& text);
        void writeEvalutionaryAlgorithmStats(int minDiffValue, double medianValue,
                double averageValue, double standardDeviationValue);
        void log(int x, int y);
        ~CSVFileWriter();

    };
}


#endif //EVOLUTIONARYALGORITHM_CSVFILEWRITER_HPP
