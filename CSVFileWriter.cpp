#include "CSVFileWriter.hpp"

namespace ea{

    // public

    CSVFileWriter::CSVFileWriter(std::string fileName, char separator)
        :fileName_(fileName), separator_(separator)
    {
        ofstreamFile_.open(fileName_, std::ios::app);
    }

    void CSVFileWriter::dummyStringWrite(const std::string &text) {
        ofstreamFile_<<text;
        writeNextLine();
    }

    void CSVFileWriter::writeEvalutionaryAlgorithmStats(int minDiffValue, double medianValue,
            double averageValue, double standardDeviationValue) {
        ofstreamFile_<<minDiffValue;
        ofstreamFile_<<separator_;
        ofstreamFile_<<medianValue;
        ofstreamFile_<<separator_;
        ofstreamFile_<<averageValue;
        ofstreamFile_<<separator_;
        ofstreamFile_<<standardDeviationValue;
        writeNextLine();
    }

    CSVFileWriter::~CSVFileWriter() {
        ofstreamFile_.close();
    }

    // protected

    void CSVFileWriter::writeNextLine() {
        ofstreamFile_<<"\n";
    }
}