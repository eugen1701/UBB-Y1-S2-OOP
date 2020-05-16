#include "Domain.h"
#include "FileDialogBox.h"
#include "FileRepository.h"
#include "HtmlRepository.h"
#include "MainWindow.h"
#include "Service.h"
#include "Tests.h"
#include "UI.h"
#include <QApplication>
#include <QDebug>
#include <QtWidgets/QLabel>
#include <iostream>
#include <regex>
#include <yaml-cpp/yaml.h>

int main(int argc, char *argv[]) {
    TestDomain();
    TestRepository();
    TestFileRepository();
    TestHtmlRepository();
    TestService();
    TestServiceAdoptionModule();
//    std::string file;
//    FileRepository* adoptedRepo;
//    std::cout<< "Tests passed!" <<std::endl;
//    std::cout<< "What type of file do you want for the adoption list?\n";
//    std::cout<< "1. CSV\n";
//    std::cout<< "2. HTML\n";
//    std::string input;
//    while(input != "1" && input != "2"){
//        std::cin>>input;
//    }
//    if(input == "1"){
//        file = "adopteddogs.txt";
//        adoptedRepo = new FileRepository(file);
//    }
//    if(input == "2"){
//        file = "index.html";
//        adoptedRepo = new HtmlRepository(file);
//    }
//    FileRepository repo{"dogs.txt"};
//    Service service{repo, *adoptedRepo};
//    UI ui{service, file};
//    ui.run();
//    delete adoptedRepo;
    auto config = YAML::LoadFile("config.yml");
    QApplication a(argc, argv);
    Repository *adoptedRepo;
    if(config["fileRepo"] && config["fileRepo"].as<bool>()){
        auto fileDialog = new FileDialogBox();
        auto result = fileDialog->exec();
        if(result == 0){
            delete fileDialog;
            return 0;
        }
        auto fileName = fileDialog->getFileName();
        delete fileDialog;
        if(std::regex_match(fileName, std::regex(".*\\.txt$"))){
            adoptedRepo = new FileRepository(fileName);
        }else if(std::regex_match(fileName, std::regex(".*\\.html$"))){
            adoptedRepo = new HtmlRepository(fileName);
        }
        else{
            QMessageBox::critical(nullptr, "Wrong extension!", "File type and extension is not supported!");
            return 1;
        }
    }else{
        adoptedRepo = new Repository();
    }
    int res;
    {
        FileRepository repo{"dogs.txt"};
        Service service{repo, *adoptedRepo};
        MainWindow *window = new MainWindow(service);
        window->show();
        res = a.exec();
        delete adoptedRepo;
    }
    return res;
}
