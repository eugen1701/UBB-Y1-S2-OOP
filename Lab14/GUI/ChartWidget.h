//
// Created by sweethuman on 10.05.2020.
//

#ifndef LAB9_CHARTWIDGET_H
#define LAB9_CHARTWIDGET_H

#include "../Service.h"
#include <QtCharts>
#include <QtWidgets/QWidget>
class ChartWidget : public QWidget {
    Q_OBJECT
  public:
    ChartWidget(Service &service) : service(service) {
        setup();
    }

  private:
    QChartView *chartView;

    Service &service;
    void setup();
    QtCharts::QBarSet *getBarSet(int number, std::string breed);
    std::map<std::string, int> getStatistics(std::vector<Dog> dogs);
    QChart* buildChart();

  public slots:
    void updateChart();
};

#endif // LAB9_CHARTWIDGET_H
