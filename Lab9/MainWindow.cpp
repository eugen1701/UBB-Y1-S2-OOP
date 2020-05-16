//
// Created by sweethuman on 08.05.2020.
//

#include "MainWindow.h"
#include "ChartWidget.h"
#include "DisplayWidget.h"
#include <QDebug>
#include <QtWidgets/QListWidget>
#include <string>

void MainWindow::setup() {
    auto mainLayout = new QHBoxLayout();
    auto tabWidget = new QTabWidget();
    auto displayWidget = new DisplayWidget(service);
    auto chartWidget = new ChartWidget(service);
    QObject::connect(displayWidget, &DisplayWidget::updatedDatabaseSignal, chartWidget, &ChartWidget::updateChart);
    tabWidget->addTab(displayWidget, "Dogs");
    tabWidget->addTab(chartWidget, "Chart");
    mainLayout->addWidget(tabWidget);
    this->setLayout(mainLayout);
}
