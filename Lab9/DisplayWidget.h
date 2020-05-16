//
// Created by sweethuman on 10.05.2020.
//

#ifndef LAB9_DISPLAYWIDGET_H
#define LAB9_DISPLAYWIDGET_H

#include "Service.h"
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
class DisplayWidget : public QWidget {
    Q_OBJECT
  public:
    DisplayWidget(Service &service) : service(service) {
        setup();
    };

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
    QPushButton *adopt_button;
    QPushButton *unadopt_button;
    QListWidget *all_dogs;
    QListWidget *all_adopted_dogs;

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
    DogListWidgetItem(Dog &dog) : QListWidgetItem(QString::fromStdString(dog.toString())), Dog(dog) {
    }
};

#endif // LAB9_DISPLAYWIDGET_H
