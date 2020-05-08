//
// Created by sweethuman on 03.05.2020.
//

#include "Aircraft.h"
Aircraft::Aircraft(const Aircraft &other) {
    this->id = other.id;
    this->model = other.model;
    this->suitable_activity = other.suitable_activity;
    this->max_altitude = other.max_altitude;
}
Aircraft &Aircraft::operator=(const Aircraft &other) {
    if(this == &other) return *this;
    this->id = other.id;
    this->model = other.model;
    this->suitable_activity = other.suitable_activity;
    this->max_altitude = other.max_altitude;
    return *this;
}
bool Aircraft::operator==(const Aircraft &other) {
    return this->id == other.id;
}
int Aircraft::getId() const{
    return this->id;
}
std::string Aircraft::getModel() {
    return model;
}
std::string Aircraft::getSuitableActivity() {
    return suitable_activity;
}
int Aircraft::getMaxAltitude() {
    return max_altitude;
}
std::string Aircraft::toString() {
    std::string result;
    result += std::to_string(id);
    result += ",";
    result += model;
    result += ",";
    result += suitable_activity;
    result += ",";
    result += std::to_string(max_altitude);
    result += ",";
    return result;
}
Helicopter::Helicopter(const Helicopter &other) {
    this->id = other.id;
    this->model = other.model;
    this->suitable_activity = other.suitable_activity;
    this->max_altitude = other.max_altitude;
    this->isPrivate = other.isPrivate;
}
bool Helicopter::getPrivate() {
    return isPrivate;
}
std::string Helicopter::toString() {
    std::string result = Aircraft::toString();
    result += std::to_string(isPrivate);
    result += ",";
    return result;
}

Plane::Plane(const Plane &other) {
    this->id = other.id;
    this->model = other.model;
    this->suitable_activity = other.suitable_activity;
    this->max_altitude = other.max_altitude;
    this->isPrivate = other.isPrivate;
    this->wings = other.wings;
}
bool Plane::getPrivate() {
    return isPrivate;
}
std::string Plane::getWings() {
    return wings;
}
std::string Plane::toString() {
    std::string result = Aircraft::toString();
    result += std::to_string(isPrivate);
    result += ",";
    result += wings;
    result += ",";
    return result;
}

Balloon::Balloon(const Balloon &other) {
    this->id = other.id;
    this->model = other.model;
    this->suitable_activity = other.suitable_activity;
    this->max_altitude = other.max_altitude;
    this->weightLimit = other.weightLimit;
}
int Balloon::getWeightLimit() {
    return weightLimit;
}
std::string Balloon::toString() {
    std::string result = Aircraft::toString();
    result += std::to_string(weightLimit);
    result += ",";
    return result;
}
