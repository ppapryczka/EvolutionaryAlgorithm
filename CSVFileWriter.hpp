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
        /* TODO - not sure which stats that will be for now empty function without arguments */
        void writeEvalutionaryAlgorithmStats();
        ~CSVFileWriter();

    };
}


#endif //EVOLUTIONARYALGORITHM_CSVFILEWRITER_HPP
