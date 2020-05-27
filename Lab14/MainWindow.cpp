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
    auto displayWidget = new DisplayWidget(service);
    auto chartWidget = new ChartWidget(service);
    auto dogTableView = new QTableView();
    auto sortedTableView = new QTableView();
    auto dogTableModel = new DogTableModel(service);
    auto sortedTableModel = new QSortFilterProxyModel();
    sortedTableModel->setSourceModel(dogTableModel);
    sortedTableView->setModel(sortedTableModel);
    sortedTableView->setSortingEnabled(true);
    dogTableView->setModel(dogTableModel);
    QObject::connect(displayWidget, &DisplayWidget::updatedDatabaseSignal, chartWidget, &ChartWidget::updateChart);
    QObject::connect(displayWidget, &DisplayWidget::dogAddSignal, dogTableModel, &DogTableModel::addDog);
    QObject::connect(displayWidget, &DisplayWidget::dogRemoveSignal, dogTableModel, &DogTableModel::removeDog);
    window.tabWidget->addTab(displayWidget, "Dogs");
    window.tabWidget->addTab(chartWidget, "Chart");
    window.tabWidget->addTab(dogTableView, "Dog Tables");
    window.tabWidget->addTab(sortedTableView, "Sorted Dog Tables");
}
