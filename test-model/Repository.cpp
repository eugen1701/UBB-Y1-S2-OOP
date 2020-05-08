//
// Created by sweethuman on 03.05.2020.
//

#include "Repository.h"
std::vector<Aircraft> &Repository::getAll() {
    return aircrafts;
}
bool Repository::add(Aircraft const &aircraft) {
    for(auto &air : aircrafts){
        if(air.getId() == aircraft.getId())
            return false;
    }
    aircrafts.push_back(aircraft);
    return true;
}
bool Repository::remove(int id) {
    for(auto i = aircrafts.begin(); i != aircrafts.end(); ++i){
        if(i->getId() == id){
            aircrafts.erase(i);
            return true;
        }
    }
    return false;
}
