//
// Created by sweethuman on 24.05.2020.
//

#ifndef TEST_QT_MAINWINDOW_H
#define TEST_QT_MAINWINDOW_H

#include "Repository.h"
#include <QtWidgets/QErrorMessage>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <limits>
#include <ui_MainWindow.h>

class MainWindow : public QMainWindow {
    Q_OBJECT
  public:
    MainWindow(Repository& repo, QWidget *parent = nullptr): repo(repo) {
        window.setupUi(this);
        setup();
        displayCars();
    }
    ~MainWindow() {
    }

  private:
    Repository& repo;
    Ui::MainWindow window;
    void setup();
    void displayCars();
  public slots:
    void showNrOfCars();
};

#endif // TEST_QT_MAINWINDOW_H
