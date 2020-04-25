//
// Created by sweethuman on 23.04.2020.
//

#ifndef LAB9_HTMLREPOSITORY_H
#define LAB9_HTMLREPOSITORY_H

#include "FileRepository.h"
class HtmlRepository : public FileRepository {
  private:
    std::vector<Dog> readData() const override;
    void writeData(const std::vector<Dog> &dogs) override;

  public:
    [[maybe_unused]] explicit HtmlRepository(std::string fileName) : FileRepository(fileName) {
    }
};

#endif // LAB9_HTMLREPOSITORY_H
