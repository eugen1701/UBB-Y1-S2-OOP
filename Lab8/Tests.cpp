//
// Created by sweethuman on 23.03.2020.
//

#include "Tests.h"
#include "Domain.h"
#include "Repository.h"
#include "Service.h"
#include <cassert>
void TestDomain() {
    Dog emptyDog{};
    assert(emptyDog.getName().empty());
    assert(emptyDog.getBreed().empty());
    assert(emptyDog.getPhotograph().empty());
    assert(emptyDog.getAge() == 0);

    Dog dog{"Labrador", "Anusca", 3, "photo"};
    assert(dog.getBreed() == "Labrador");
    assert(dog.getName() == "Anusca");
    assert(dog.getAge() == 3);
    assert(dog.getPhotograph() == "photo");
    auto dogRef = &dog;
    dog = dog;
    assert(&dog == dogRef);
    assert(dog.toString() == "Labrador Anusca 3 photo");
    dog.setAge(4);
    assert(dog.getAge() == 4);
    dog.setPhotograph("ceapa cu mere");
    assert(dog.getPhotograph() == "ceapa cu mere");
    emptyDog = dog;
    assert(emptyDog.getBreed() == "Labrador");
    assert(emptyDog.getName() == "Anusca");
    assert(emptyDog.getAge() == 4);
    assert(emptyDog.getPhotograph() == "ceapa cu mere");
    Dog copiedDog{dog};
    assert(copiedDog.getBreed() == "Labrador");
    assert(copiedDog.getName() == "Anusca");
    assert(copiedDog.getAge() == 4);
    assert(copiedDog.getPhotograph() == "ceapa cu mere");
}
void TestRepository() {
    Dog dog1{"Labrador", "Aniona", 5, "photome"};
    Dog dog2{"Pomerian", "Pufi", 3, "cevapoza"};
    Repository repo{};
    repo.addDog(dog1);
    repo.addDog(dog2);
    Dog gottenDog = repo.getDog("Rottveiler", "Anion");
    assert(gottenDog.getName().empty());
    assert(gottenDog.getBreed().empty());
    assert(gottenDog.getPhotograph().empty());
    assert(gottenDog.getAge() == 0);
    Dog gottenDog2 = repo.getDog("Labrador", "Aniona");
    assert(gottenDog2.getBreed() == "Labrador");
    assert(gottenDog2.getName() == "Aniona");
    assert(gottenDog2.getAge() == 5);
    assert(gottenDog2.getPhotograph() == "photome");
    assert(repo.isDog("Pomerian", "Pufi"));
    assert(!repo.isDog("Pomerian", "Pufion"));
    assert(repo.removeDog("Pomerian", "Pufi"));
    assert(!repo.removeDog("Pomerian", "Pufi"));
    Dog dog3 = repo.getDogs()[0];
    assert(dog3.getBreed() == dog1.getBreed());
    assert(dog3.getName() == dog1.getName());
    assert(dog3.getAge() == dog1.getAge());
    assert(dog3.getPhotograph() == dog1.getPhotograph());
}
void TestService() {
    Repository repo{};
    Repository repo2{};
    Service service{repo, repo2};
    assert(service.addDog("Labrador", "Balan", 30, "photoa"));
    assert(!service.addDog("Labrador", "Balan", 78, "phtoa"));
    Dog gottenDog = repo.getDog("Labrador", "Balan");
    assert(gottenDog.getBreed() == "Labrador");
    assert(gottenDog.getName() == "Balan");
    assert(gottenDog.getAge() == 30);
    assert(gottenDog.getPhotograph() == "photoa");
    assert(service.addDog("Bulldog", "Buffy", 3, "ahap"));
    assert(service.removeDog("Labrador", "Balan"));
    assert(!service.removeDog("Labrador", "Balan"));
    assert(!service.updateDog("Labrador", "Balan", 89, "aba"));
    assert(service.updateDog("Bulldog", "Buffy", 7, "abap"));
    Dog gottenDog2 = repo.getDog("Bulldog", "Buffy");
    assert(gottenDog2.getBreed() == "Bulldog");
    assert(gottenDog2.getName() == "Buffy");
    assert(gottenDog2.getAge() == 7);
    assert(gottenDog2.getPhotograph() == "abap");
}

void TestServiceAdoptionModule(){
    Repository repo{};
    Repository adoptRepo{};
    Service service{repo, adoptRepo};
    Dog dog1{"Lab", "Ionica", 3, "poza_ioni"};
    Dog dog2{"Chiuaua", "Andrei", 6, "poza_andrei"};
    Dog dog3{"Lab", "Matei", 10, "poza_matei"};
    service.addDog(dog1.getBreed(), dog1.getName(), dog1.getAge(), dog1.getPhotograph());
    service.addDog(dog2.getBreed(), dog2.getName(), dog2.getAge(), dog2.getPhotograph());
    service.addDog(dog3.getBreed(), dog3.getName(), dog3.getAge(), dog3.getPhotograph());
    auto dogs = service.filterDogs("", 10);
    assert(dogs[0].getBreed() == dog1.getBreed() && dogs[0].getName() == dog1.getName());
    assert(dogs[1].getBreed() == dog2.getBreed() && dogs[1].getName() == dog2.getName());
    assert(dogs.size() == 2);
    dogs = service.filterDogs("Lab", 12);
    assert(dogs[0].getBreed() == dog1.getBreed() && dogs[0].getName() == dog1.getName());
    assert(dogs[1].getBreed() == dog3.getBreed() && dogs[1].getName() == dog3.getName());
    assert(dogs.size() == 2);
    assert(service.adoptDog(dog1));
    assert(!service.adoptDog(dog1));
    assert(service.isDogAdopted(dog1.getBreed(), dog1.getName()));
    assert(!service.isDogAdopted(dog2.getBreed(), dog2.getName()));
    service.adoptDog(dog2);
    assert(service.unadoptDog(dog1.getBreed(), dog1.getName()));
    assert(!service.unadoptDog(dog1.getBreed(), dog1.getName()));
    assert(!service.isDogAdopted(dog1.getBreed(), dog1.getName()));
    assert(service.isDogAdopted(dog2.getBreed(), dog2.getName()));
    service.adoptDog(dog3);
    dogs = service.getAdoptedDogs();
    assert(dogs[0].getBreed() == dog2.getBreed() && dogs[0].getName() == dog2.getName());
    assert(dogs[1].getBreed() == dog3.getBreed() && dogs[1].getName() == dog3.getName());
}
