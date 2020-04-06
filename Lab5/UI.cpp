//
// Created by sweethuman on 23.03.2020.
//

#include "UI.h"
#include <iostream>
using namespace std;

void UI::addDog() {
    std::string breed;
    std::string name;
    int age;
    std::string photograph;
    cout << "Dog Breed: ";
    cin >> breed;
    cout << "Dog Name: ";
    cin >> name;
    cout << "Dog Age: ";
    cin >> age;
    if (!cin.good()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Age is not a number!" << endl;
        return;
    }
    cout << "Dog Photograph: ";
    cin >> photograph;
    if (service.addDog(breed, name, age, photograph)) {
        cout << "Dog added successfully" << endl;
    } else {
        cout << "Dog could not be added, already exists!" << endl;
    }
}

void UI::run() {
    while (1) {
        printMenu();
        int option;
        cout << "Selection: ";
        cin >> option;
        switch (option) {
        case 1:
            addDog();
            break;
        case 2:
            removeDog();
            break;
        case 3:
            updateDog();
            break;
        case 4:
            listDogs();
            break;
        case 5:
            return;
        default:
            break;
        }
    }
}
void UI::removeDog() {
    std::string breed;
    std::string name;
    cout << "Dog breed: ";
    cin >> breed;
    cout << "Dog Name: ";
    cin >> name;
    if (service.removeDog(breed, name)) {
        cout << "Dog removed successfully" << endl;
    } else {
        cout << "Dog could not be removed, doesn't exist!\n";
    }
}
void UI::updateDog() {
    std::string breed;
    std::string name;
    int age;
    std::string photograph;
    cout << "Dog Breed: ";
    cin >> breed;
    cout << "Dog Name: ";
    cin >> name;
    cout << "Dog Age: ";
    cin >> age;
    if (!cin.good()) {
        cin.clear();
        cout << "Age is not a number!" << endl;
        return;
    }
    cout << "Dog Photograph: ";
    cin >> photograph;
    if (service.updateDog(breed, name, age, photograph)) {
        cout << "Dog updated successfully" << endl;
    } else {
        cout << "Dog could not be updated, doesn't exit!\n";
    }
}
void UI::listDogs() { cout << service.listDogs(); }
void UI::printMenu() {
    cout << "1. Add dog \n";
    cout << "2. Remove dog \n";
    cout << "3. Update dog \n";
    cout << "4. List dog \n";
    cout << "5. Exit \n";
}
