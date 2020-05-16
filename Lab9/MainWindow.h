//
// Created by sweethuman on 08.05.2020.
//

#ifndef LAB9_MAINWINDOW_H
#define LAB9_MAINWINDOW_H

#include "Service.h"
#include <QtWidgets/QErrorMessage>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <limits>
class MainWindow : public QWidget {
    Q_OBJECT
  public:
    MainWindow(Service &service, QWidget *parent = nullptr) : service(service) {
        setup();
    }
    ~MainWindow() {
    }

  private:
    Service &service;
    void setup();
};

#endif // LAB9_MAINWINDOW_H
