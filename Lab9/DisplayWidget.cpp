//
// Created by sweethuman on 10.05.2020.
//

#include "DisplayWidget.h"
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>

void DisplayWidget::setup() {
    QHBoxLayout *layout = new QHBoxLayout(this);
    QVBoxLayout *dogs_layout = new QVBoxLayout();
    QVBoxLayout *adopted_layout = new QVBoxLayout();
    QVBoxLayout *middle_layout = new QVBoxLayout();
    layout->addLayout(dogs_layout, 3);
    layout->addLayout(middle_layout, 1);
    layout->addLayout(adopted_layout, 3);
    setupDogsLayout(dogs_layout);
    setupMiddleLayout(middle_layout);
    setupAdoptedLayout(adopted_layout);
    initializeConnections();
    populateViews();
    this->setLayout(layout);
}
void DisplayWidget::setupDogsLayout(QVBoxLayout *layout) {
    QLabel *label = new QLabel("All Dogs");
    all_dogs = new QListWidget();
    all_dogs->setSelectionMode(QAbstractItemView::SingleSelection);
    QFormLayout *form = new QFormLayout();
    dog_breed = new QLineEdit();
    dog_breed->setClearButtonEnabled(true);
    dog_name = new QLineEdit();
    dog_name->setClearButtonEnabled(true);
    dog_age = new QLineEdit();
    dog_age->setClearButtonEnabled(true);
    dog_age->setValidator(new QIntValidator());
    dog_photograph = new QLineEdit();
    dog_photograph->setClearButtonEnabled(true);
    form->addRow(*(new QString("Breed")), dog_breed);
    form->addRow(*(new QString("Name")), dog_name);
    form->addRow(*(new QString("Age")), dog_age);
    form->addRow(*(new QString("Photograph")), dog_photograph);
    QGridLayout *grid = new QGridLayout();
    add_button = new QPushButton("Add");
    delete_button = new QPushButton("Delete");
    update_button = new QPushButton("Update");
    filter_button = new QPushButton("Filter");
    grid->addWidget(add_button, 0, 0);
    grid->addWidget(delete_button, 0, 1);
    grid->addWidget(update_button, 0, 2);
    grid->addWidget(filter_button, 1, 1);
    layout->addWidget(label);
    layout->addWidget(all_dogs);
    layout->addLayout(form);
    layout->addLayout(grid);
}
void DisplayWidget::setupAdoptedLayout(QVBoxLayout *layout) {
    QLabel *label = new QLabel("Adoption Queue");
    layout->addWidget(label);
    all_adopted_dogs = new QListWidget();
    layout->addWidget(all_adopted_dogs);
    QHBoxLayout *h_layout = new QHBoxLayout();
    layout->addLayout(h_layout);
    h_layout->addWidget(new QPushButton("Save"));
    h_layout->addWidget(new QPushButton("Clear"));
}

void DisplayWidget::setupMiddleLayout(QVBoxLayout *layout) {
    adopt_button = new QPushButton(" > ");
    unadopt_button = new QPushButton(" < ");
    layout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(unadopt_button, 1);
    layout->addWidget(adopt_button, 1);
    layout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

void DisplayWidget::initializeConnections() {
    QObject::connect(add_button, &QPushButton::clicked, this, &DisplayWidget::addHandler);
    QObject::connect(this, &DisplayWidget::dogAddSignal, this, &DisplayWidget::dogAddSlot);
    QObject::connect(this, &DisplayWidget::updatedDatabaseSignal, this, &DisplayWidget::updatedDatabaseSlot);
    QObject::connect(delete_button, &QPushButton::clicked, this, &DisplayWidget::deleteHandler);
    QObject::connect(update_button, &QPushButton::clicked, this, &DisplayWidget::updateHandler);
    QObject::connect(filter_button, &QPushButton::clicked, this, &DisplayWidget::filterHandler);
    QObject::connect(adopt_button, &QPushButton::clicked, this, &DisplayWidget::adoptHandler);
    QObject::connect(unadopt_button, &QPushButton::clicked, this, &DisplayWidget::unadoptHandler);
}

void DisplayWidget::populateViews() {
    auto dogs = service.getDogs();
    for (auto &dog : dogs) {
        all_dogs->addItem(new DogListWidgetItem(dog));
    }
    auto adopted_dogs = service.getAdoptedDogs();
    for (auto &dog : adopted_dogs) {
        all_adopted_dogs->addItem(new DogListWidgetItem(dog));
    }
}

void DisplayWidget::addHandler() {
    std::string breed = dog_breed->text().toStdString();
    std::string name = dog_name->text().toStdString();
    QString age_str = dog_age->text();
    std::string photograph = dog_photograph->text().toStdString();
    if (breed.empty()) {
        QMessageBox::critical(nullptr, "Empty Breed", "Empty Breed");
        return;
    }
    if (name.empty()) {
        QMessageBox::critical(nullptr, "Empty Name", "Empty Name");
        return;
    }
    if (age_str.isEmpty()) {
        QMessageBox::critical(nullptr, "Empty Age", "Empty Age");
        return;
    }
    if (photograph.empty()) {
        QMessageBox::critical(nullptr, "Empty Photograph", "Empty Photograph");
        return;
    }
    int age = age_str.toInt();
    emit dogAddSignal(breed, name, age, photograph);
}

void DisplayWidget::deleteHandler() {
    if (all_dogs->selectedItems().isEmpty()) {
        QMessageBox::critical(nullptr, "Wrong Selection", "You haven't selected a dogs!");
        return;
    }
    auto item = (DogListWidgetItem *)all_dogs->selectedItems().at(0);
    service.removeDog(item->getBreed(), item->getName());
    emit updatedDatabaseSignal();
}

void DisplayWidget::updateHandler() {
    std::string breed = dog_breed->text().toStdString();
    std::string name = dog_name->text().toStdString();
    QString age_str = dog_age->text();
    std::string photograph = dog_photograph->text().toStdString();
    if (breed.empty()) {
        QMessageBox::critical(nullptr, "Empty Breed", "Empty Breed");
        return;
    }
    if (name.empty()) {
        QMessageBox::critical(nullptr, "Empty Name", "Empty Name");
        return;
    }
    if (age_str.isEmpty()) {
        QMessageBox::critical(nullptr, "Empty Age", "Empty Age");
        return;
    }
    if (photograph.empty()) {
        QMessageBox::critical(nullptr, "Empty Photograph", "Empty Photograph");
        return;
    }
    int age = age_str.toInt();
    try {
        if (!service.updateDog(breed, name, age, photograph)) {
            QMessageBox::critical(nullptr, "Dupliacte!",
                                  "Another Dog with the same identifiers is already in the database!");
        }
    } catch (const std::exception &e) {
        QMessageBox::critical(nullptr, "Error!", e.what());
    }
    emit updatedDatabaseSignal();
}

void DisplayWidget::filterHandler() {
    std::string breed = dog_breed->text().toStdString();
    QString age_str = dog_age->text();
    int age = INT_MAX;
    if (!age_str.isEmpty()) {
        age = age_str.toInt();
    }
    emit updatedDatabaseSignal(breed, age);
}

void DisplayWidget::dogAddSlot(std::string breed, std::string name, int age, std::string photograph) {
    try {
        if (!service.addDog(breed, name, age, photograph)) {
            QMessageBox::critical(nullptr, "Dupliacte!",
                                  "Another Dog with the same identifiers is already in the database!");
        }
    } catch (const std::exception &e) {
        QMessageBox::critical(nullptr, "Error!", e.what());
    }
    emit updatedDatabaseSignal();
}
void DisplayWidget::updatedDatabaseSlot(std::string breed, int age) {
    all_dogs->clear();
    auto dogs = service.filterDogs(breed, age);
    for (auto dog : dogs) {
        all_dogs->addItem(new DogListWidgetItem(dog));
    }
    all_adopted_dogs->clear();
    auto adopted_dogs = service.getAdoptedDogs();
    for (auto dog : adopted_dogs) {
        all_adopted_dogs->addItem(new DogListWidgetItem(dog));
    }
}
void DisplayWidget::adoptHandler() {
    if (all_dogs->selectedItems().isEmpty()) {
        QMessageBox::critical(nullptr, "Wrong Selection", "You haven't selected a dogs!");
    }
    auto item = (DogListWidgetItem *)all_dogs->selectedItems().at(0);
    if (!service.adoptDog(*item)) {
        QMessageBox::information(nullptr, "Duplicate!", "Dog already in Adoption");
        return;
    }
    emit updatedDatabaseSignal();
}
void DisplayWidget::unadoptHandler() {
    if (all_adopted_dogs->selectedItems().isEmpty()) {
        QMessageBox::critical(nullptr, "Wrong Selection", "You haven't selected any dogs in adoption!");
    }
    auto item = (DogListWidgetItem *)all_adopted_dogs->selectedItems().at(0);
    if (!service.unadoptDog(item->getBreed(), item->getName())) {
        QMessageBox::information(nullptr, "Wrong Selection", "Dog not in adoption queue!");
        return;
    }
    emit updatedDatabaseSignal();
}