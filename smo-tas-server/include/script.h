#pragma once

#include <fstream>
#include <tas.h>
#include <string>

namespace fl::script
{
    TasScript fromText(std::stringstream& file);
    TasScript fromText(std::ifstream& file);
    TasScript fromText(const std::string& file);
    std::string toText(const TasScript& script);
}