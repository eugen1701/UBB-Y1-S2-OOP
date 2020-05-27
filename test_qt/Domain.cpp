//
// Created by sweethuman on 24.05.2020.
//

#include "Domain.h"
#include <sstream>


std::vector<std::string> split(const std::string& input, char delimiter) {
    std::vector<std::string> result;
    std::stringstream input_stream(input);
    std::string token;
    while (getline(input_stream, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream& operator>>(std::istream& istream, BaseClass& item)
{
    std::string line;
    getline(istream, line);

    std::vector<std::string> Attributes = split(line, '|');
    if (Attributes.size() != 4)
        return istream;
    item.manufacturer = Attributes[0];
    item.model = Attributes[1];
    item.year = Attributes[2];
    item.color = Attributes[3];
    return istream;
}
std::string BaseClass::toString() {
    std::string result = "";
    result += manufacturer;
    result += " ";
    result += model;
    return result;
}
