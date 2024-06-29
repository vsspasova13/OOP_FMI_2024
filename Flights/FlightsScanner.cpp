#include "FlightsScanner.h"
#include "Utils.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>

void FlightsScanner::handleAirport(char* airport) const
{
    if (strlen(airport) != 3)
        throw std::length_error("The airport size should be exactly 3");
    toUpper(airport);
}

void FlightsScanner::parseLine(const char* line, FlightRecord& record) const
{
    std::stringstream curr(line);
    curr >> record.origin;

    if (strlen(record.origin) != 3)
        throw std::length_error("The origin size should be exactly 3");
    try
    {
        handleAirport(record.origin);
    }


}

bool FlightsScanner::readAndExportData(std::ifstream& input)
{
    return false;
}

void FlightsScanner::saveRecord(std::ofstream& ofs, const FlightRecord& record) const
{
}

FlightsScanner::FlightsScanner(const char* input, const char* output, int scanInterval)
{
    strcpy(inputFile, input);
    strcpy(outputFile, output);
    sec = scanInterval;
}

void FlightsScanner::run()
{
}
