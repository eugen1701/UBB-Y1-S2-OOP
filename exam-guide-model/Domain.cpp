//
// Created by sweethuman on 19.06.2020.
//
#include <sstream>
#include <string>
#include <vector>
std::vector<std::string> split(const std::string &input, char delimiter) {
    std::vector<std::string> result;
    std::stringstream input_stream(input);
    std::string token;
    while (getline(input_stream, token, delimiter))
        result.push_back(token);

    return result;
}