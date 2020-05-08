//
// Created by sweethuman on 04.05.2020.
//

#ifndef TEST_REPOSITORY_H
#define TEST_REPOSITORY_H
#include "Domain.h"
#include <vector>

class Repository {
private:
    std::vector<MedLab*> labs;
public:
    Repository () {};
    bool add(MedLab *lab);
    std::vector<MedLab*> &getAll();
};


#endif//TEST_REPOSITORY_H
