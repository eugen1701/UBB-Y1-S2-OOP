//
// Created by sweethuman on 03.03.2020.
//

#include "domain.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

Medication *medication__create(char *model_name, int concentration, int quantity, int price) {
    char *name = (char *)malloc(100 * sizeof(char));
    strcpy(name, model_name);
    Medication *med = malloc(sizeof(Medication));
    med->name = name;
    med->concentration = concentration;
    med->quantity = quantity;
    med->price = price;
    return med;
}

Medication *medication__copy(Medication *medication) {
    char *name = (char *)malloc(100 * sizeof(char));
    strcpy(name, medication->name);
    Medication *copy_med = (Medication *)malloc(sizeof(Medication));
    copy_med->name = name;
    copy_med->concentration = medication->concentration;
    copy_med->quantity = medication->quantity;
    copy_med->price = medication->price;
    return copy_med;
}

void medication__destroy(Medication *medication) {
    free(medication->name);
    free(medication);
}
char *getMedicationName(Medication *medication) {
    if (medication == NULL) {
        return NULL;
    }
    return medication->name;
}
int getMedicationPrice(Medication *medication) {
    if (medication == NULL) {
        return -1;
    }
    return medication->price;
}
int getMedicationConcentration(Medication *medication) {
    if (medication == NULL) {
        return -1;
    }
    return medication->concentration;
}
int getMedicationQuantity(Medication *medication) {
    if (medication == NULL) {
        return -1;
    }
    return medication->quantity;
}

void testDomain() {
    Medication *med1 = medication__create("Alabama", 10, 20, 60);
    assert(strcmp(getMedicationName(med1), "Alabama") == 0);
    assert(getMedicationQuantity(med1) == 20);
    assert(getMedicationConcentration(med1) == 10);
    assert(getMedicationPrice(med1) == 60);

    Medication *med2 = medication__copy(med1);
    assert(strcmp(med1->name, med2->name) == 0);
    assert(med1->name != med2->name);
    assert(med1->quantity == med2->quantity);
    assert(med1->concentration == med2->concentration);
    assert(med1->price == med2->price);
    assert(med1 != med2);
    medication__destroy(med1);
    medication__destroy(med2);
}
