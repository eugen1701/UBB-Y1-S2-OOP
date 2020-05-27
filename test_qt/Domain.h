//
// Created by sweethuman on 24.05.2020.
//

#ifndef TEST_QT_DOMAIN_H
#define TEST_QT_DOMAIN_H

#include <string>
#include <vector>
class BaseClass {
  public:
    std::string manufacturer;
    std::string model;
    std::string year;
    std::string color;

    virtual std::string toString();
    virtual bool operator==(const BaseClass *other) const {return false;};
    friend std::istream& operator>>(std::istream& istream, BaseClass& item);
};

#endif // TEST_QT_DOMAIN_H
