#include "Domain.h"
#include "Repository.h"
#include "Service.h"
#include "UI.h"
#include "Tests.h"

int main() {
    TestDomain();
    TestDynamicVector();
    TestRepository();
    TestService();
    TestServiceAdoptionModule();
    Repository repo{};
    Repository adoptedRepo{};
    Dog d1{"Labrador", "Gigel", 7, "poza"};
    Dog d2{"Labrador", "Andrei", 8, "poza"};
    Dog d3{"Poodle", "Ana", 13, "poza"};
    Dog d4{"Pechinez", "Zus", 2, "poza"};
    Dog d5{"Chuuaua", "Min", 10, "poza"};
    Dog d6{"Husky", "Maxi", 5, "poza"};
    Dog d7{"Beagle", "Joynny", 3, "poza"};
    Dog d8{"Bulldog", "Pufulete", 10, "poza"};
    Dog d9{"Terrier", "Stick", 5, "poza"};
    Dog d10{"Pomeranian","Pufi", 3, "poza"};
    repo.addDog(d1);
    repo.addDog(d2);
    repo.addDog(d3);
    repo.addDog(d4);
    repo.addDog(d5);
    repo.addDog(d6);
    repo.addDog(d7);
    repo.addDog(d8);
    repo.addDog(d9);
    repo.addDog(d10);
    Service service{repo, adoptedRepo};
    UI ui{service};
    ui.run();
    return 0;
}
