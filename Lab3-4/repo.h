//
// Created by sweethuman on 03.03.2020.
//
#include "DynamicArray.h"
#include "domain.h"
#include <stdbool.h>
#ifndef LAB3_4_REPO_H
#define LAB3_4_REPO_H

// There might be an issue when using the dynamic array because the pointer will change;
typedef struct {
    DynamicArray *storage;
} Repo;

Repo *repo__create();
void repo__destroy(Repo *repo);
/// Add Medicine to storage, does no filtering, anything given is added
/// Doesn't make a copy of the medication
/// \param medicine Medicine to add
/// \return True if addition was successful
bool repo__add(Repo *repo, Medication *medicine);
/// Remove Medicine from storage
/// \param name
/// \param concentration
/// \return
bool repo__remove(Repo *repo, char *name, int concentration);
/// Get Medicine from name and concentration that matches
/// \param name Name to search for
/// \param concentration Concentration to search for
/// \return Pointer to Medicine if found, otherwise null
Medication *repo__get(Repo *repo, char *name, int concentration);
/// Return all Objects
/// \return A struct containing array and length
DynamicArray *repo__getAll(Repo *repo);
void testRepo();

#endif // LAB3_4_REPO_H
