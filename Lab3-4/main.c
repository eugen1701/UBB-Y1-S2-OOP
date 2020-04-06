#include "UI.h"
#include "controller.h"
#include "domain.h"
#include "repo.h"

void addTestMedication(Repo *repo) {

    Medication *medication = medication__create("BenzoCeva", 10, 30, 15);
    repo__add(repo, medication);
    medication = medication__create("BenzoCeva", 20, 30, 40);
    repo__add(repo, medication);
    medication = medication__create("BenzoCeva", 30, 30, 60);
    repo__add(repo, medication);
    medication = medication__create("PoateEBun", 100, 4, 10);
    repo__add(repo, medication);
    medication = medication__create("SolutiaTa", 90, 200, 55);
    repo__add(repo, medication);
    medication = medication__create("SolutiaTa", 80, 200, 45);
    repo__add(repo, medication);
    medication = medication__create("SolutiaTa", 70, 200, 39);
    repo__add(repo, medication);
    medication = medication__create("AuMaDoare", 19, 60, 20);
    repo__add(repo, medication);
    medication = medication__create("AuMaDoare", 39, 60, 40);
    repo__add(repo, medication);
    medication = medication__create("SolutiaTa", 50, 200, 13);
    repo__add(repo, medication);
}
int main() {
    testDomain();
    testDynamicArray();
    testRepo();
    testStack();
    Repo *repo = repo__create();
    OperationStack *undoStack = opstack__create();
    OperationStack *redoStack = opstack__create();
    addTestMedication(repo);
    Controller *controller = controller__create(repo, undoStack, redoStack);
    UI *ui = ui__create(controller);
    ui__run(ui);
    ui__destroy(ui);
    return 0;
}
