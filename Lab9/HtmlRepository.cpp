//
// Created by sweethuman on 23.04.2020.
//

#include "HtmlRepository.h"
#include <fstream>
#include <sstream>
std::vector<Dog> HtmlRepository::readData() const {
    std::ifstream dogsFile{fileName};
    for (int i = 0; i < 14; ++i) {
        dogsFile.ignore(9999999999999999, '\n');
    }
    std::string input;
    std::vector<Dog> dogs;
    while (std::getline(dogsFile, input)) {
        if (input == "</table>")
            break;
        if(input.empty())
            continue;
        std::stringstream ss{input};
        std::string breed;
        std::string name;
        std::string age_s;
        std::string photograph;
        ss.ignore(8);
        std::getline(ss, breed, '<');
        ss.ignore(8);
        std::getline(ss, name, '<');
        ss.ignore(8);
        std::getline(ss, age_s, '<');
        ss.ignore(8);
        ss.ignore(9);
        std::getline(ss, photograph, '"');
        ss.ignore(19);
        int age = std::stoi(age_s);
        dogs.emplace_back(breed, name, age, photograph);
    }
    return dogs;
}
void HtmlRepository::writeData(const std::vector<Dog> &dogs) {
    std::ofstream dogsFile{fileName};
    std::string header = "<!DOCTYPE html>\n"
                         "<html lang=\"en\">\n"
                         "<head>\n"
                         "    <meta charset=\"UTF-8\">\n"
                         "    <title>Adopted Dogs</title>\n"
                         "</head>\n"
                         "<body>\n"
                         "<table border=\"1\">\n"
                         "    <tr>\n"
                         "        <td>Breed</td>\n"
                         "        <td>Name</td>\n"
                         "        <td>Age</td>\n"
                         "        <td>Photograph</td>\n"
                         "    </tr>\n";
    dogsFile << header;
    for (auto &dog : dogs) {
        dogsFile << "<tr>";
        dogsFile << "<td>" << dog.getBreed() << "</td>";
        dogsFile << "<td>" << dog.getName() << "</td>";
        dogsFile << "<td>" << std::to_string(dog.getAge()) << "</td>";
        dogsFile << "<td>"
                 << "<a href=\"" << dog.getPhotograph() << "\">Link</a></td>";
        dogsFile << "</tr>\n";
    }
    dogsFile << "</table>\n"
                "</body>\n"
                "</html>";
}
