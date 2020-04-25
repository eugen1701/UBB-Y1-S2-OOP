#include "Domain.h"
#include "FileRepository.h"
#include "HtmlRepository.h"
#include "Service.h"
#include "Tests.h"
#include "UI.h"
#include <iostream>

int main() {
    TestDomain();
    TestRepository();
    TestFileRepository();
    TestHtmlRepository();
    TestService();
    TestServiceAdoptionModule();
    std::string file;
    FileRepository* adoptedRepo;
    std::cout<< "Tests passed!" <<std::endl;
    std::cout<< "What type of file do you want for the adoption list?\n";
    std::cout<< "1. CSV\n";
    std::cout<< "2. HTML\n";
    std::string input;
    while(input != "1" && input != "2"){
        std::cin>>input;
    }
    if(input == "1"){
        file = "adopteddogs.txt";
        adoptedRepo = new FileRepository(file);
    }
    if(input == "2"){
        file = "index.html";
        adoptedRepo = new HtmlRepository(file);
    }
    FileRepository repo{"dogs.txt"};
    Service service{repo, *adoptedRepo};
    UI ui{service, file};
    ui.run();
    delete adoptedRepo;
    return 0;
}
