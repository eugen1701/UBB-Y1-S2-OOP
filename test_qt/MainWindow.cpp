//
// Created by sweethuman on 24.05.2020.
//

#include "MainWindow.h"
void MainWindow::setup() {
    QObject::connect(window.showButton, &QPushButton::clicked, this, &MainWindow::showNrOfCars);
}
void MainWindow::showNrOfCars() {
    if (window.manufacturerInput->text().isEmpty()) {
        QMessageBox::critical(nullptr, "Wrong Input!", "No manufacturer name specified!");
        return;
    }
    auto carNumber = repo.numberOfCarsforManufacturer(window.manufacturerInput->text().toStdString());
    window.carNumberOutput->setText(QString::number(carNumber));
}

bool sortFunc(BaseClass o1, BaseClass o2)
{
    return strcmp(o1.manufacturer.c_str(), o2.manufacturer.c_str()) < 0;
}

void MainWindow::displayCars() {
    auto listings = repo.list();
    std::sort(listings.begin(), listings.end(), sortFunc);
    for (int i = 0; i < listings.size(); i++) {
        QString cars = QString::fromStdString(listings[i].toString());
        window.carsList->addItem(cars);
        window.carsList->item(i)->setForeground(QBrush(QColor(QString::fromStdString(listings[i].color))));
    }
}
