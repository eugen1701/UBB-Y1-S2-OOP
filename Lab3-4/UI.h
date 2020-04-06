//
// Created by sweethuman on 23.03.2020.
//

#ifndef LAB3_4_UI_H
#define LAB3_4_UI_H
#include "controller.h"
typedef struct {
    Controller *controller;
} UI;
UI *ui__create(Controller *controller);
void ui__run(UI *ui);
void ui__destroy(UI *ui);
void printMenu();
void AddMedication(Controller *controller);
void RemoveMedication(Controller *controller);
void UpdateMedication(Controller *controller);
void PrintMedication(Controller *controller);
void ListMedicationContainingString(Controller *controller);
void ListMedicationInShortSupply(Controller *controller);
#endif // LAB3_4_UI_H
