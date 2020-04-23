//
// Created by sweethuman on 12.04.2020.
//

#ifndef LAB8_FILEREPOSITORY_H
#define LAB8_FILEREPOSITORY_H
#include "Repository.h"
#include <utility>
#include <vector>
class FileRepository : public Repository {
  private:
    std::string fileName;
    virtual std::vector<Dog> readData() const;
    virtual void writeData(const std::vector<Dog> &dogs);

  public:
    explicit FileRepository(std::string fileName) : fileName(std::move(fileName)) {}
    void addDog(Dog &dog) override;
    Dog getDog(const std::string &breed, const std::string &name) override;
    bool removeDog(const std::string &breed, const std::string &name) override;
    bool isDog(const std::string &breed, const std::string &name) override;
    virtual std::vector<Dog> getDogs() const override;
};

#endif // LAB8_FILEREPOSITORY_H
