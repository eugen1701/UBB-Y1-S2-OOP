//
// Created by sweethuman on 08.05.2020.
//

#include "MainWindow.h"
#include "../DogTableModel.h"
#include "ChartWidget.h"
#include "DisplayWidget.h"
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
    dogTableView->setItemDelegateForColumn(3, new ImageDelegate());
    window.tabWidget->addTab(displayWidget, "Dogs");
    window.tabWidget->addTab(chartWidget, "Chart");
    window.tabWidget->addTab(dogTableView, "Dog Tables");
    window.tabWidget->addTab(sortedTableView, "Sorted Dog Tables");
    createActions();
    dogs.registerCallback(chartWidget, &ChartWidget::updateChart);
    dogs.registerCallback(dogTableModel, &DogTableModel::actionReaction);
    dogs.registerCallback(displayWidget, &DisplayWidget::refreshViews);
}
void MainWindow::createActions() {
    window.actionUndo->setShortcut(QKeySequence::Undo);
    window.actionUndo->setStatusTip(tr("Undo Last Action"));
    QObject::connect(window.actionUndo, &QAction::triggered, this, &MainWindow::undo);
    window.actionRedo->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));
    window.actionRedo->setStatusTip(tr("Redo Last Action"));
    QObject::connect(window.actionRedo, &QAction::triggered, this, &MainWindow::redo);
}
void MainWindow::undo() {
    if (service.executeUndo()) {
        statusBar()->showMessage(tr("Undo Successful"));
    } else {
        statusBar()->showMessage(tr("Undo Failed"));
    }
}
void MainWindow::redo() {
    if (service.executeRedo()) {
        statusBar()->showMessage(tr("Redo Successful"));
    } else {
        statusBar()->showMessage(tr("Redo Failed"));
    }
}
