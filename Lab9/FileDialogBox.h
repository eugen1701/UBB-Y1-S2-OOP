//
// Created by sweethuman on 10.05.2020.
//

#ifndef LAB9_FILEDIALOGBOX_H
#define LAB9_FILEDIALOGBOX_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
class FileDialogBox : public QDialog{
    Q_OBJECT
  public:
    FileDialogBox() { setup(); };
    std::string getFileName() const;
  private:
    QLineEdit *fileName;
    void setup();
};

#endif // LAB9_FILEDIALOGBOX_H
