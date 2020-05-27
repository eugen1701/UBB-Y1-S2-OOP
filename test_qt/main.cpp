#include "MainWindow.h"
#include <QApplication>
#include <QDebug>
#include <iostream>
#include "Tests.h"
int main(int argc, char *argv[]) {
    TestRepo();
    QApplication a(argc, argv);
    Repository repo{"cars.txt"};
    auto mainWindow = new MainWindow(repo);
    mainWindow->show();
    return a.exec();
}
