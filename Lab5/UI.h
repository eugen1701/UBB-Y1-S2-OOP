//
// Created by sweethuman on 23.03.2020.
//

#ifndef LAB5_UI_H
#define LAB5_UI_H
#include "Service.h"
class UI {
  private:
    Service& service;

  public:
    explicit UI(Service &service) : service(service) {}
    void run();

  private:
    static void printMenu();
    void addDog();
    void updateDog();
    void removeDog();
    void listDogs();
};
#endif // LAB5_UI_H
