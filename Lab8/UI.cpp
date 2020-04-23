//
// Created by sweethuman on 23.03.2020.
//

#include "UI.h"
#include <cstdlib>
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
    cout << "Choose Mode: " << endl;
    cout << "0. Administrator" << endl;
    cout << "1. User" << endl;
    int mode;
    cin >> mode;
    if (mode == 0) {
        adminUI();
    } else {
        userUI();
    }
}

void UI::adminUI() {
    while (true) {
        printAdminMenu();
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

void UI::userUI() {
    while (true) {
        printUserMenu();
        int option;
        cout << "Selection: ";
        cin >> option;
        switch (option) {
        case 1:
            adoptDogs(service.getDogs());
            break;
        case 2: {
            std::string breed;
            int age;
            cout << "Breed: ";
            getline(cin, breed);
            cout << "Age: ";
            cin >> age;
            adoptDogs(service.filterDogs(breed, age));
        } break;
        case 3: {
            auto dogs = service.getAdoptedDogs();
            for (auto &dog : dogs) {
                cout << dog.toString() << "\n";
            }
        } break;
        case 4:
            return;
        default:
            break;
        }
    }
}

void UI::adoptDogs(const std::vector<Dog> &dogs) {
    auto i = dogs.begin();
    while (true) {
        if (i == dogs.end()) {
            int option;
            cout << "You have reached the end. Want to start over?\n";
            cout << "1. Yes\n";
            cout << "2. No\n";
            cout << "Selection: ";
            cin >> option;
            if (option == 1) {
                i = dogs.begin();
            } else {
                break;
            }
        }
        bool ok = true;
        while (ok) {
            cout << i->toString() << "\n";
            printAdoptionMenu();
            if (service.isDogAdopted(i->getBreed(), i->getName())) {
                cout << "ADOPTED\n";
            } else {
                cout << "NOT ADOPTED\n";
            }
            int option;
            cout << "Selection: ";
            cin >> option;
            switch (option) {
            case 1:
                service.adoptDog(*i);
                break;
            case 2:
                service.unadoptDog(i->getBreed(), i->getName());
                break;
            case 3:
                ok = false;
                break;
            case 4:
                return;
            default:
                break;
            }
        }
        ++i;
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

void UI::printAdminMenu() {
    cout << "1. Add dog \n";
    cout << "2. Remove dog \n";
    cout << "3. Update dog \n";
    cout << "4. List dog \n";
    cout << "5. Exit \n";
}

void UI::printUserMenu() {
    cout << "1. Adopt Dogs\n";
    cout << "2. Filter dogs based on Breed and Age\n";
    cout << "3. View Adoption List\n";
    cout << "4. Exit\n";
}

void UI::printAdoptionMenu() {
    cout << "1. Adopt Dog\n";
    cout << "2. Don't Adopt\n";
    cout << "3. Next\n";
    cout << "4. Exit\n";
}