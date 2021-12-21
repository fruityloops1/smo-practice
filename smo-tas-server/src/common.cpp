#include <common.h>
#include <deque>

std::deque<std::string> fl::split(const std::string &str, const char delim)
{ 
    std::stringstream ss(str);
    std::string s;

    std::deque<std::string> out;

    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
    return out;
}