//
// Created by sweethuman on 23.03.2020.
//

#include "UI.h"
#include "controller.h"
#include "domain.h"
#include "repo.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
UI *ui__create(Controller *controller) {
    UI *ui = (UI *)malloc(sizeof(UI));
    ui->controller = controller;
    return ui;
}
void ui__destroy(UI *ui) {
    controller__destroy(ui->controller);
    free(ui);
}
void ui__run(UI *ui) {
    while (1) {
        printMenu();
        char option;
        char stuff[10];
        scanf(" %c", &option);
        fgets(stuff, sizeof(stuff), stdin);
        switch (option) {
        case '1':
            AddMedication(ui->controller);
            break;
        case '2':
            RemoveMedication(ui->controller);
            break;
        case '3':
            UpdateMedication(ui->controller);
            break;
        case '4':
            PrintMedication(ui->controller);
            break;
        case '5':
            ListMedicationContainingString(ui->controller);
            break;
        case '6':
            ListMedicationInShortSupply(ui->controller);
            break;
        case '7':
            if (controller__undo(ui->controller) == false) {
                printf("Nothing more to Undo!");
            } else {
                printf("Undo Successful!");
            }
            break;
        case '8':
            if (controller__redo(ui->controller) == false) {
                printf("Nothing more to Redo!");
            } else {
                printf("Redo Successful!");
            }
            break;
        case '9':
            return;
        default:
            break;
        }
    }
}

void printMenu() {
    printf("\n1. Add Medication\n"
           "2. Remove Medication\n"
           "3. Update Medication\n"
           "4. List all Medication\n"
           "5. List Medication Containing a given string\n"
           "6. List Medication in Short Supply\n"
           "7. Undo\n"
           "8. Redo\n"
           "9. Exit\n");
}

void AddMedication(Controller *controller) {
    char *name = (char *)malloc(100 * sizeof(char));
    int concentration;
    int quantity;
    int price;
    printf("Medication Name: ");
    scanf("%s", name);
    printf("Medication Concentration: ");
    scanf("%d", &concentration);
    printf("Medication Quantity: ");
    scanf("%d", &quantity);
    printf("Medication Price: ");
    scanf("%d", &price);
    Medication *medication = medication__create(name, concentration, quantity, price);
    if (controller__add(controller, medication) == 0) {
        printf("Medication added successfully");
    } else {
        printf("Medication already exists, quantity increased");
    }
    medication__destroy(medication);
    free(name);
}
void RemoveMedication(Controller *controller) {
    char name[100];
    int concentration;
    printf("Medication Name: ");
    scanf("%s", name);
    printf("Medication Concentration: ");
    scanf("%d", &concentration);
    if (controller__remove(controller, name, concentration) == true) {
        printf("Medication removed successfully");
    } else {
        printf("Medication remove failed");
    }
}
void UpdateMedication(Controller *controller) {
    char name[100];
    int concentration;
    int quantity;
    int price;
    printf("Medication Name: ");
    scanf("%s", name);
    printf("Medication Concentration: ");
    scanf("%d", &concentration);
    printf("Medication Quantity: ");
    scanf("%d", &quantity);
    printf("Medication Price: ");
    scanf("%d", &price);
    if (controller__update(controller, name, concentration, quantity, price) == 1) {
        printf("Medication Updated successfully");
    } else {
        printf("Medication doesn't exist");
    }
}
void PrintMedication(Controller *controller) {
    DynamicArray *objects = controller__getAll(controller);
    Medication **medicates = (Medication **)malloc(objects->length * sizeof(Medication *));
    memcpy(medicates, objects->elems, objects->length * sizeof(Medication *));
    int length = dynamicArray__getLength(objects);
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (getMedicationConcentration(medicates[i]) > getMedicationConcentration(medicates[j])) {
                Medication *med = medicates[i];
                medicates[i] = medicates[j];
                medicates[j] = med;
            }
        }
    }
    for (int i = 0; i < length; i++) {
        printf("Name: %s, concentration: %d, quantity: %d, price: %d \n", getMedicationName(medicates[i]),
               getMedicationConcentration(medicates[i]), getMedicationQuantity(medicates[i]),
               getMedicationPrice(medicates[i]));
        medication__destroy(medicates[i]);
    }
    free(medicates);
    dynamicArray__destroy(objects);
}

void ListMedicationContainingString(Controller *controller) {
    char substring[100];
    printf("Medication containing: ");
    fgets(substring, sizeof(substring), stdin);
    strtok(substring, "\n");
    DynamicArray *objects = controller__nameFilter(controller, substring);
    Medication **medicates = (Medication **)malloc(objects->length * sizeof(Medication *));
    memcpy(medicates, objects->elems, objects->length * sizeof(Medication *));
    int length = dynamicArray__getLength(objects);
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (strcmp(getMedicationName(medicates[i]), getMedicationName(medicates[j])) > 0) {
                Medication *med = medicates[i];
                medicates[i] = medicates[j];
                medicates[j] = med;
            }
        }
    }
    for (int i = 0; i < length; i++) {
        printf("Name: %s, concentration: %d, quantity: %d, price: %d \n", getMedicationName(medicates[i]),
               getMedicationConcentration(medicates[i]), getMedicationQuantity(medicates[i]),
               getMedicationPrice(medicates[i]));
        medication__destroy(medicates[i]);
    }
    free(medicates);
    dynamicArray__destroy(objects);
}

void ListMedicationInShortSupply(Controller *controller) {
    int number;
    printf("Medication Lower than Quantity: ");
    scanf("%d", &number);
    DynamicArray *objects = controller__quantityFilter(controller, number);
    int length = dynamicArray__getLength(objects);
    for (int i = 0; i < length; i++) {
        Medication *medication = dynamicArray__getElement(objects, i);
        printf("Name: %s, concentration: %d, quantity: %d, price: %d \n", getMedicationName(medication),
               getMedicationConcentration(medication), getMedicationQuantity(medication),
               getMedicationPrice(medication));
    }
    dynamicArray__destroy(objects);
}
