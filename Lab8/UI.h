//
// Created by sweethuman on 23.03.2020.
//

#ifndef LAB5_UI_H
#define LAB5_UI_H
#include "Service.h"
class UI {
  private:
    Service& service;
    bool userMode = false;

  public:
    explicit UI(Service &service) : service(service) {}
    void run();

  private:
    static void printAdminMenu();
    static void printUserMenu();
    void addDog();
    void updateDog();
    void removeDog();
    void listDogs();
    void adminUI();
    void userUI();
    void adoptDogs(const std::vector<Dog> &dogs);
    void printAdoptionMenu();
};
#endif // LAB5_UI_H
