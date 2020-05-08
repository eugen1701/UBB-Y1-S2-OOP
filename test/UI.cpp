//
// Created by sweethuman on 04.05.2020.
//

#include "UI.h"
#include <iostream>
#include <fstream>
using namespace std;
void UI::run() {
    while (true) {
        printUserMenu();
        int option;
        cout << "Option: ";
        cin >> option;
        switch (option) {
            case 1:
                addNewDeparatament();
                break;
            case 2:
                showAllDeparatments();
                break;
            case 3:
                showAllEfficientDeparatments();
                break;
            case 4:
                saveDeparatmentsToFile();
                break;
            case 5:
                return;
            default:
                break;
        }
    }
}

void UI::printUserMenu() {
    cout << "1. Add New Department" << endl;
    cout << "2. Show All Departments" << endl;
    cout << "3. Show All Efficient Departments" << endl;
    cout << "4. Save All Departments to a File" << endl;
    cout << "5. Exit" << endl;
}
void UI::addNewDeparatament() {
    cout << "Select Department\n";
    cout << "1. Surgery\n";
    cout << "2. NeoNatal\n";
    int option;
    cout << "Option: ";
    cin >> option;
    std::string hospitalName;
    cout << "Hospital Name: ";
    cin >> hospitalName;
    int doctors;
    cout << "Nr. of Doctors: ";
    cin >> doctors;
    if (option == 1) {
        int patients;
        cout << "Nr. of Patients: ";
        cin >> patients;
        repo.add(new Surgery(hospitalName, doctors, patients));
    } else if (option == 2) {
        int mothers;
        cout << "Nr. of mothers: ";
        cin >> mothers;
        int babies;
        cout << "Nr. of babies: ";
        cin >> babies;
        double avgGrade;
        cout << "Average Grade of babies(ex: 9.3): ";
        cin >> avgGrade;
        repo.add(new NeoNatal(hospitalName, doctors, mothers, babies, avgGrade));
    } else {
        cout << "Wrong selection.\n";
        cout << "Returning...\n";
        return;
    }
}
void UI::showAllDeparatments() {
    for (auto &dep : repo.getAll()) {
        cout << dep->toString() << endl;
    }
}
void UI::showAllEfficientDeparatments() {
    for (auto &dep : repo.getAll()) {
        if (dep->isEfficient()) {
            cout << dep->toString() << endl;
        }
    }
}
void UI::saveDeparatmentsToFile() {
    cout << "File Name: ";
    std::string fileName;
    cin >> fileName;
    ofstream file{fileName};
    for (auto &dep : repo.getAll()) {
        file << dep->toString() << endl;
    }
    file.close();
}
