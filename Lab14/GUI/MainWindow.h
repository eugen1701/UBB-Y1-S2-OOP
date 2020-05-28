//
// Created by sweethuman on 08.05.2020.
//

#ifndef LAB9_MAINWINDOW_H
#define LAB9_MAINWINDOW_H

#include "../Service.h"
#include <QtWidgets/QErrorMessage>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <limits>
#include <ui_mainWindow.h>
class MainWindow : public QMainWindow {
    Q_OBJECT
  public:
    MainWindow(Service &service, QWidget *parent = nullptr) : service(service) {
        window.setupUi(this);
        setup();
    }
    ~MainWindow() {
    }

  private:
    Ui::MainWindow window;
    Service &service;
    void setup();
};

#endif // LAB9_MAINWINDOW_H
