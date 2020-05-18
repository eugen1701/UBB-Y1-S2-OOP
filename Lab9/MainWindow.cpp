//
// Created by sweethuman on 08.05.2020.
//

#include "MainWindow.h"
#include "ChartWidget.h"
#include "DisplayWidget.h"
#include "DogTableModel.h"
#include <QDebug>
#include <QtWidgets/QListWidget>
#include <string>

void MainWindow::setup() {
    auto mainLayout = new QHBoxLayout();
    auto tabWidget = new QTabWidget();
    auto displayWidget = new DisplayWidget(service);
    auto chartWidget = new ChartWidget(service);
    auto dogTableView = new QTableView();
    auto dogTableModel = new DogTableModel(service);
    dogTableView->setModel(dogTableModel);
    QObject::connect(displayWidget, &DisplayWidget::updatedDatabaseSignal, chartWidget, &ChartWidget::updateChart);
    QObject::connect(displayWidget, &DisplayWidget::dogAddSignal, dogTableModel, &DogTableModel::addDog);
    QObject::connect(displayWidget, &DisplayWidget::dogRemoveSignal, dogTableModel, &DogTableModel::removeDog);
    tabWidget->addTab(displayWidget, "Dogs");
    tabWidget->addTab(chartWidget, "Chart");
    tabWidget->addTab(dogTableView, "Dog Tables");
    mainLayout->addWidget(tabWidget);
    this->setLayout(mainLayout);
}
