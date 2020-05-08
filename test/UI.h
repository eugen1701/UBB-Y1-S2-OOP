//
// Created by sweethuman on 04.05.2020.
//

#ifndef TEST_UI_H
#define TEST_UI_H


#include "Repository.h"
class UI {
private:
    Repository &repo;
    public:
        UI(Repository &repo) : repo(repo) {};
        void run();
        void printUserMenu();
        void addNewDeparatament();
        void showAllDeparatments();
        void showAllEfficientDeparatments();
        void saveDeparatmentsToFile();
};


#endif//TEST_UI_H
