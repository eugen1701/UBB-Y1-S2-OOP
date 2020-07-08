//
// Created by sweethuman on 19.06.2020.
//

#ifndef EXAM_GUIDE_MODEL_REPOSITORY_H
#define EXAM_GUIDE_MODEL_REPOSITORY_H

#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
template <class T>
class Repository {


  private:
    std::string fileName;
    std::vector<T> objects;

  public:
    Repository(const std::string &fileName) : fileName(fileName) {
        read_from_file();
    }
    /// Adds a Object to the repo, and checks if duplicate
    /// \param value object you want to add
    void add(T value) {
        for(auto &object : objects){
            if(object == value){
                throw std::exception();
            }
        }
        objects.push_back(value);
    }

    void remove(T value) {
        for (unsigned int i = 0; i < objects.size(); i++) {
            if (objects[i] == value) {
                objects.erase(objects.begin() + i);
                return;
            }
        }
    }

    std::vector<T> &getAll() {
        return objects;
    }

    void read_from_file() {
        std::ifstream objFile{fileName};
        T obj;
        while (objFile >> obj) {
            objects.push_back(obj);
        }
    }
    void write_to_file() {
        std::ofstream file{fileName};
        sort(objects.begin(), objects.end());
        for (auto &obj : objects) {
            file << obj << "\n";
        }
    }

    ~Repository() {
        write_to_file();
    }
};

#endif // EXAM_GUIDE_MODEL_REPOSITORY_H
