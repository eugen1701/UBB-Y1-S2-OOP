#include "Domain.h"
#include "Repository.h"
#include "FileRepository.h"
#include "Service.h"
#include "UI.h"
#include "Tests.h"
#include <iostream>

int main() {
    TestDomain();
    TestRepository();
    TestService();
    TestServiceAdoptionModule();
    std::cout<< "Tests passed!" <<std::endl;
    FileRepository repo{"dogs.txt"};
    FileRepository adoptedRepo{"adopteddogs.txt"};
    Service service{repo, adoptedRepo};
    UI ui{service};
    ui.run();
    return 0;
}
