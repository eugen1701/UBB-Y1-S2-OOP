//
// Created by sweethuman on 03.05.2020.
//

#include "UI.h"
#include <fstream>
using namespace std;

void UI::run() {
    while (1) {
        printUserMenu();
        int selection;
        cout << "Option: ";
        cin >> selection;
        switch (selection) {
            case 1:
                addAircraft();
                break;
            case 2:
                displayAircraftForActivity();
                break;
            case 3:
                displayAircraftForAltitude();
                break;
            case 4:
                return;
            default:
                break;
        }
    }
}

void UI::printUserMenu() {
    cout << "1. Add Aircraft\n";
    cout << "2. Display Aircraft for Activity\n";
    cout << "3. Display all Aircraft for Altitude\n";
    cout << "4. Exit\n";
}

void UI::printAircraftMenu() {
    cout << "1. Helicopter\n";
    cout << "2. Airplane\n";
    cout << "3. Hot Balloon\n";
}

void UI::addAircraft() {
    printAircraftMenu();
    int selection;
    int id;
    std::string suitable_activity;
    int max_altitude;
    cout << "Aircraft: ";
    cin >> selection;
    cout << "Id: ";
    cin >> id;
    cout << "Suitable activity: ";
    suitable_activity = readSuitableActivity();
    if (suitable_activity == "unknown") {
        cout << "Wrong activity type selected\n";
        return;
    }
    cout << "Max altitude: ";
    cin >> max_altitude;
    if (selection == 1) {
        if (max_altitude > 12) {
            cout << "Exceeds maximum altitude of 12 km\n";
            return;
        }
        bool isPrivate;
        cout << "Is Private(0,1): ";
        cin >> isPrivate;
        if (!isPrivate && suitable_activity == "leisure") {
            cout << "Leisure only for private\n";
            return;
        }
        if (!repo.add(Helicopter(id, "helicopter", suitable_activity, max_altitude, isPrivate))) {
            cout << "DUPLICATE ID\n";
        } else {
            cout << "SUCCESS\n";
        }
        return;
    }
    if (selection == 2) {
        if (max_altitude > 26) {
            cout << "Exceeds maximum altitude of 26 km\n";
            return;
        }
        if (suitable_activity == "medical") {
            cout << "Airplane cannot be for medical purposes\n";
            return;
        }
        bool isPrivate;
        cout << "Is Private(0,1): ";
        cin >> isPrivate;
        std::string wings = readWings();
        if (wings == "unknown") {
            cout << "Wrong wings selected\n";
            return;
        }
        if (wings == "monoplane" && suitable_activity == "leisure") {
            cout << "Monoplane cannot be for leisure\n";
            return;
        }
        if (!repo.add(Plane(id, "plane", suitable_activity, max_altitude, isPrivate, wings))) {
            cout << "DUPLICATE ID\n";
        } else {
            cout << "SUCCESS\n";
        }
        return;
    }
    if (selection == 3) {
        if (max_altitude > 21) {
            cout << "Exceeds maximum altitude of 21 km\n";
            return;
        }
        if (suitable_activity != "leisure") {
            cout << "Hot Balloon only for leisure time\n";
            return;
        }
        int max_weight;
        cout << "Max Weight: ";
        cin >> max_weight;
        if (!repo.add(Balloon(id, "balloon", suitable_activity, max_altitude, max_weight))) {
            cout << "DUPLICATE ID\n";
        } else {
            cout << "SUCCESS\n";
        }
        return;
    }
    cout << "No aircraft selected\n";
    cout << "Returning...\n";
}
void UI::displayAircraftForActivity() {
    std::string activity = readSuitableActivity();
    if (activity == "unknown"){
        cout << "WHY U KNO SELECT CORRECT OPTION! STUPID!\n";
        return;
    }
    ofstream file{activity};
    auto crafts = repo.getAll();
    for(auto &craft : crafts) {
        if(craft.getSuitableActivity() == activity){
            cout << craft.toString() << "\n";
            file << craft.toString() << "\n";
        }
    }
}
void UI::displayAircraftForAltitude() {
    int altitude;
    cout << "Altitude: ";
    cin >> altitude;
    auto crafts = repo.getAll();
    for(auto &craft : crafts) {
        if(craft.getMaxAltitude() >= altitude){
            cout << craft.toString() << "\n";
        }
    }
}
std::string UI::readSuitableActivity() {
    cout << "Suitable Activity: \n";
    cout << "1. Military\n";
    cout << "2. Public Transportation\n";
    cout << "3. Medical Emergency\n";
    cout << "4. Leisure time\n";
    int option;
    cout << "Option: ";
    cin >> option;
    if (option == 1) {
        return "military";
    }
    if (option == 2) {
        return "transportation";
    }
    if (option == 3) {
        return "medical";
    }
    if (option == 4) {
        return "leisure";
    }
    return "unknown";
}
std::string UI::readWings() {
    cout << "Wings: \n";
    cout << "1. Monoplane\n";
    cout << "2. Biplane\n";
    int option;
    cout << "Option: ";
    cin >> option;
    if (option == 1) {
        return "monoplane";
    }
    if (option == 2) {
        return "biplane";
    }
    return "unknown";
}
