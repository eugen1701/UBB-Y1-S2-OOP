//
// Created by sweethuman on 10.05.2020.
//

#include "FileDialogBox.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
void FileDialogBox::setup() {
    auto mainLayout = new QVBoxLayout(this);
    auto button_layout = new QHBoxLayout();
    auto cancel_button = new QPushButton("Cancel");
    auto ok_button = new QPushButton("Ok");
    fileName = new QLineEdit();
    mainLayout->addWidget(new QLabel("Enter File Name for storage: "));
    mainLayout->addWidget(fileName);
    mainLayout->addLayout(button_layout);
    button_layout->addWidget(cancel_button);
    button_layout->addWidget(ok_button);
    ok_button->setDefault(true);
    QObject::connect(ok_button, &QPushButton::clicked, this, &FileDialogBox::accept);
    QObject::connect(cancel_button, &QPushButton::clicked, this, &FileDialogBox::reject);
}
std::string FileDialogBox::getFileName() const {
    return fileName->text().toStdString();
}
