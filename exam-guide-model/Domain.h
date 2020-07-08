//
// Created by sweethuman on 19.06.2020.
//
#ifndef EXAM_GUIDE_MODEL_DOMAIN_H
#define EXAM_GUIDE_MODEL_DOMAIN_H

#include <sstream>
#include <string>
#include <vector>
std::vector<std::string> split(const std::string &input, char delimiter);
class Astronomer {
  public:
    std::string name;
    std::string constellation;

    Astronomer(){};
    Astronomer(const Astronomer &other) {
        this->name = other.name;
        this->constellation = other.constellation;
    }
    Astronomer &operator=(const Astronomer &other) {
        if (this == &other)
            return *this;
        this->name = other.name;
        this->constellation = other.constellation;
        return *this;
    }

    bool operator<(const Astronomer &other) {
        return this->constellation < other.constellation;
    };

    friend std::istream &operator>>(std::istream &is, Astronomer &user) {
        std::string line{};
        getline(is, line);
        std::vector<std::string> arguments = split(line, ',');
        if (arguments.size() == 0) {
            return is;
        }

        user.name = arguments[0];
        user.constellation = arguments[1];
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, Astronomer &user) {
        return os << user.name << "," << user.constellation;
    }
};

class Star {
  public:
    std::string name;
    std::string constellation;
    int ra;
    int dec;
    int diameter;

    Star(){};
    Star(const Star &other) {
        this->name = other.name;
        this->constellation = other.constellation;
        this->ra = other.ra;
        this->dec = other.dec;
        this->diameter = other.diameter;
    }
    Star &operator=(const Star &other) {
        if (this == &other)
            return *this;
        this->name = other.name;
        this->constellation = other.constellation;
        this->ra = other.ra;
        this->dec = other.dec;
        this->diameter = other.diameter;
        return *this;
    }

    bool operator==(const Star &other) const {
        if (this == &other)
            return true;
        return this->name == other.name;
    }

    bool operator<(const Star &other) {
        return this->constellation < other.constellation;
    };

    friend std::istream &operator>>(std::istream &is, Star &star) {
        std::string line{};
        getline(is, line);
        std::vector<std::string> arguments = split(line, ',');
        if (arguments.size() == 0) {
            return is;
        }

        star.name = arguments[0];
        star.constellation = arguments[1];
        star.ra = stoi(arguments[2]);
        star.dec = stoi(arguments[3]);
        star.diameter = stoi(arguments[4]);
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, Star &issue) {
        return os << issue.name << "," << issue.constellation << "," << std::to_string(issue.ra) << ","
                  << std::to_string(issue.dec) << "," << std::to_string(issue.diameter);
    }
};

#endif // EXAM_GUIDE_MODEL_DOMAIN_H
