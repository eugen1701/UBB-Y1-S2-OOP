//
// Created by sweethuman on 24.05.2020.
//

#ifndef TEST_QT_REPOSITORY_H
#define TEST_QT_REPOSITORY_H

#include "Domain.h"
#include <algorithm>
#include <string>
#include <vector>

class Repository {
  private:
    std::vector<BaseClass> elems;
    std::string filename;

  public:
    Repository(std::string filename) : filename{filename} {
        read_from_file();
    }
    std::vector<BaseClass> &list();
    int numberOfCarsforManufacturer(std::string manufacturer);
    ~Repository(){};

  private:
    void write_to_file();
    void read_from_file();
};

#endif // TEST_QT_REPOSITORY_H
