//
// Created by sweethuman on 03.03.2020.
//

#include "repo.h"
#include "DynamicArray.h"
#include "domain.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool repo__add(Repo *repo, Medication *medicine) {
    if (repo == NULL || medicine == NULL)
        return false;
    dynamicArray__addElement(repo->storage, medicine);
    return true;
}

bool repo__remove(Repo *repo, char *name, int concentration) {
    int length = dynamicArray__getLength(repo->storage);
    for (int i = 0; i < length; i++) {
        if (strcmp(name, getMedicationName(dynamicArray__getElement(repo->storage, i))) == 0 &&
            concentration == getMedicationConcentration(dynamicArray__getElement(repo->storage, i))) {
            medication__destroy(dynamicArray__removeElement(repo->storage, i));
            return true;
        }
    }
    return false;
}

Medication *repo__get(Repo *repo, char *name, int concentration) {
    int length = dynamicArray__getLength(repo->storage);
    for (int i = 0; i < length; i++) {
        if (strcmp(name, getMedicationName(dynamicArray__getElement(repo->storage, i))) == 0 &&
            concentration == getMedicationConcentration(dynamicArray__getElement(repo->storage, i))) {
            return dynamicArray__getElement(repo->storage, i);
        }
    }
    return NULL;
}

DynamicArray *repo__getAll(Repo *repo) { return repo->storage; }
Repo *repo__create() {
    Repo *repo = (Repo *)malloc(sizeof(Repo));
    if (repo == NULL)
        return NULL;
    repo->storage = dynamicArray__create(10);
    return repo;
}
void repo__destroy(Repo *repo) {
    if (repo == NULL)
        return;
    dynamicArray__destroy(repo->storage);
    free(repo);
}
void testRepo() {
    Repo *repo = repo__create();
    Medication *med1 = medication__create("Albatros", 10, 20, 909);
    assert(repo__add(repo, med1) == true);
    assert(repo__get(repo, "Albatros", 10) == med1);
    Medication *med2 = medication__create("Baboon", 200, 20, 203);
    assert(repo__add(repo, med2) == true);
    assert(repo__get(repo, "Baboon", 200) == med2);
    assert(repo__get(repo, "bannda", 60) == NULL);
    assert(dynamicArray__getLength(repo__getAll(repo)) == 2);
    assert(repo__add(NULL, med2) == false);
    assert(repo__add(repo, NULL) == false);
    assert(repo__remove(repo, "gigel", 60) == false);
    assert(repo__remove(repo, "Baboon", 200) == true);
    assert(repo__get(repo, "Baboon", 200) == NULL);
    repo__destroy(repo);
    repo__destroy(NULL);
}
