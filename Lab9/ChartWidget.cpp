//
// Created by sweethuman on 10.05.2020.
//

#include "ChartWidget.h"
#include <QtWidgets/QHBoxLayout>
#include <QtCharts>
#include <map>

void ChartWidget::setup() {
    auto mainLayout = new QHBoxLayout();
    auto chart = buildChart();
    chartView = new QChartView(chart);
    mainLayout->addWidget(chartView);
    this->setLayout(mainLayout);
}

QBarSet *ChartWidget::getBarSet(int number, std::string breed) {
    auto barSet = new QBarSet(QString::fromStdString(breed));
    *barSet << number;
    return barSet;
}

std::map<std::string, int> ChartWidget::getStatistics(std::vector<Dog> dogs){
    std::map<std::string, int> breedCount{};
    for(auto &dog : dogs){
        auto it = breedCount.find(dog.getBreed());
        if(it != breedCount.end()){
            //TODO test iterator second add
            breedCount[dog.getBreed()]++;
        }else{
            breedCount[dog.getBreed()] = 1;
        }
    }
    return breedCount;
}

QChart *ChartWidget::buildChart() {
    auto barSeries = new QBarSeries();
    auto statistics = getStatistics(service.getDogs());
    int max = 0;
    for(auto &value : statistics) {
        if(value.second > max){
            max = value.second;
        }
        barSeries->append(getBarSet(value.second, value.first));
    }
    auto chart = new QChart();
    chart->addSeries(barSeries);
    chart->setTitle("Number of dogs for each breed");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    auto axis = new QValueAxis();
    axis->setRange(0,max);
    chart->addAxis(axis,Qt::AlignLeft);
    return chart;
}
void ChartWidget::updateChart() {
    auto chart = chartView->chart();
    chartView->setChart(buildChart());
    delete chart;
}
