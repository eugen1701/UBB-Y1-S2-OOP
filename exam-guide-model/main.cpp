#include "AstronomerWindow.h"
#include "Domain.h"
#include "StarTableModel.h"
#include <QtCore/QSortFilterProxyModel>
#include <QtWidgets/QApplication>
#include <iostream>
#include "tests.h"

int main(int argc, char *argv[]) {
    testRepo();
    QApplication a(argc, argv);
    Repository<Astronomer> astrons{"astron.txt"};
    Repository<Star> stars{"stars.txt"};
    StarTableModel model{stars};
    std::vector<AstronomerWindow*> windows;
    for(auto &user : astrons.getAll()) {
        auto temp = new AstronomerWindow(user, &model, stars);
        QObject::connect(temp, &AstronomerWindow::starAdded, &model, &StarTableModel::addStar);
        windows.push_back(temp);
        temp->show();
    }
    return a.exec();
}
