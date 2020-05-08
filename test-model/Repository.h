//
// Created by sweethuman on 03.05.2020.
//

#ifndef TEST_MODEL_REPOSITORY_H
#define TEST_MODEL_REPOSITORY_H
#include "Aircraft.h"
#include <vector>

class Repository {
private:
        std::vector<Aircraft> aircrafts;
    public:
        bool add(Aircraft const &aircraft);
        bool remove(int id);
        std::vector<Aircraft> &getAll();
};


#endif//TEST_MODEL_REPOSITORY_H
