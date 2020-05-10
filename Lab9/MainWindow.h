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
    void addHandler();
    void deleteHandler();
    void updateHandler();
    void filterHandler();
    void adoptHandler();
    void unadoptHandler();
    QLineEdit *dog_breed;
    QLineEdit *dog_name;
    QLineEdit *dog_age;
    QLineEdit *dog_photograph;
    QPushButton *add_button;
    QPushButton *update_button;
    QPushButton *delete_button;
    QPushButton *filter_button;
    QListWidget *all_dogs;
    QListWidget *all_adopted_dogs;
    QPushButton *adopt_button;
    QPushButton *unadopt_button;

    Service &service;
    void setup();
    void setupDogsLayout(QVBoxLayout *layout);
    void setupAdoptedLayout(QVBoxLayout *layout);
    void setupMiddleLayout(QVBoxLayout *layout);
    void initializeConnections();
  signals:
    void dogAddSignal(std::string breed, std::string name, int age, std::string photograph);
    void updatedDatabaseSignal(std::string breed = "", int age = INT_MAX);
  public slots:
    void dogAddSlot(std::string breed, std::string name, int age, std::string photograph);
    void updatedDatabaseSlot(std::string breed, int age);
    void populateViews();
};

class DogListWidgetItem : public QListWidgetItem, public Dog {
  public:
    DogListWidgetItem(Dog &dog): QListWidgetItem(QString::fromStdString(dog.toString())), Dog(dog){}
};


#endif // LAB9_MAINWINDOW_H
