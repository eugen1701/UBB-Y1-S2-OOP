//
// Created by sweethuman on 20.06.2020.
//

#include "AstronomerWindow.h"
#include <QtWidgets/QMessageBox>
AstronomerWindow::AstronomerWindow(Astronomer &astron, QAbstractTableModel *model, Repository<Star> &repo,
                                   QWidget *parent)
    : astron(astron), model(model), repo(repo) {
    window.setupUi(this);
    setup();
}
void AstronomerWindow::setup() {
    this->setWindowTitle(QString::fromStdString(astron.name));
    window.raEdit->setValidator(new QIntValidator());
    window.decEdit->setValidator(new QIntValidator());
    window.diameterEdit->setValidator(new QIntValidator());
    filterModel = new ConstellationFilter();
    filterModel->setSourceModel(model);
    QObject::connect(window.viewCheckBox, &QCheckBox::clicked, this, &AstronomerWindow::checkClick);
    QObject::connect(window.addButton, &QPushButton::clicked, this, &AstronomerWindow::addClick);
    QObject::connect(window.searchEdit, &QLineEdit::textChanged, this, &AstronomerWindow::modifiedSearch);
    window.tableView->setModel(filterModel);
    modifiedSearch();
}
void AstronomerWindow::checkClick() {
    if (window.viewCheckBox->isChecked()) {
        filterModel->setConstellationFilter(QString::fromStdString(astron.constellation));
    } else {
        filterModel->setConstellationFilter(QString(""));
    }
}
void AstronomerWindow::addClick() {
    if (window.nameEdit->text().isEmpty()) {
        QMessageBox::critical(nullptr, "Wrong Input", "Name Field is empty!");
        return;
    }
    if (window.diameterEdit->text().isEmpty() || window.diameterEdit->text().toInt() <= 0) {
        QMessageBox::critical(nullptr, "Wrong Input", "Invalid Diameter");
        return;
    }
    Star star{};
    star.name = window.nameEdit->text().toStdString();
    star.constellation = astron.constellation;
    star.ra = window.raEdit->text().toInt();
    star.dec = window.decEdit->text().toInt();
    star.diameter = window.diameterEdit->text().toInt();
    try{
        repo.add(star);
    }catch (std::exception& e) {
        QMessageBox::critical(nullptr, "Wrong Input", "An Object with the same name already exists.");
        return;
    }
    emit starAdded();
}
void AstronomerWindow::modifiedSearch() {
    this->window.searchWidget->clear();
    std::vector<Star> fragments = repo.getAll();
    std::string searchCrit = this->window.searchEdit->text().toStdString();
    for (auto &star : repo.getAll()) {
        std::string name = star.name;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if (name.find(searchCrit) != std::string::npos)
            this->window.searchWidget->addItem(
                QString::fromStdString(star.name + ", " + star.constellation + ", " + std::to_string(star.ra) + ", " +
                                       std::to_string(star.dec) + ", " + std::to_string(star.diameter)));
    }
}
