//
// Created by sweethuman on 04.05.2020.
//

#include "Domain.h"
bool Surgery::isEfficient() {
    return doctors*2 <= patients;
}
std::string Surgery::toString() {
    auto result = MedLab::toString();
    result += "Surgery";
    result += ",";
    if(isEfficient()){
        result += "Efficient";
    }else{
        result += "Not Efficient";
    }
    return result;
}
bool NeoNatal::isEfficient() {
    return avgGrade > 8.5 && babies >= patients;
}
std::string NeoNatal::toString() {
    std::string result = MedLab::toString();
    result += "Babies: ";
    result += std::to_string(babies);
    result += ",";
    result += "Average grade: ";
    result += std::to_string(avgGrade);
    result += ",";
    result += "NeoNatal";
    result += ",";
    if(isEfficient()){
        result += "Efficient";
    }else{
        result += "Not Efficient";
    }
    return result;
}

std::string MedLab::toString() {
    std::string result;
    result += "Hospital: ";
    result += hospitalName;
    result += ",";
    result += "Doctor: ";
    result += std::to_string(doctors);
    result += ",";
    result += "Patient: ";
    result += std::to_string(patients);
    result += ",";
    return result;
}
