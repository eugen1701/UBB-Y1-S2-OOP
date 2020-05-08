//
// Created by sweethuman on 04.05.2020.
//

#ifndef TEST_DOMAIN_H
#define TEST_DOMAIN_H
#include <string>

class MedLab {
protected:
    int doctors;
    int patients;
    std::string hospitalName;

public:
    MedLab(std::string hospitalName, int doctors, int patients) : hospitalName(hospitalName), doctors(doctors), patients(patients){};
    virtual bool isEfficient() = 0;
    virtual std::string toString();
};

class Surgery : public MedLab {
public:
    Surgery(std::string hospitalName, int doctors, int patients) : MedLab(hospitalName, doctors, patients){};
    bool isEfficient() override;
    std::string toString() override;
};

class NeoNatal : public MedLab {
private:
    int babies;
    double avgGrade;

public:
    NeoNatal(std::string hospitalName, int doctors, int patients, int babies, double avgGrade) : MedLab(hospitalName, doctors, patients), babies(babies), avgGrade(avgGrade){};
    bool isEfficient() override;
    std::string toString() override;
};


#endif//TEST_DOMAIN_H
