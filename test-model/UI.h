//
// Created by sweethuman on 03.05.2020.
//

#ifndef TEST_MODEL_UI_H
#define TEST_MODEL_UI_H


#include "Repository.h"
#include "Aircraft.h"
#include <iostream>
class UI {
    Repository &repo;
    public:
        UI(Repository &repo): repo(repo) {};
        void run();
        void printUserMenu();
        void addAircraft();
        void displayAircraftForActivity();
        void displayAircraftForAltitude();
        void printAircraftMenu();
        std::string readSuitableActivity();
        std::string readWings();
};


#endif//TEST_MODEL_UI_H
