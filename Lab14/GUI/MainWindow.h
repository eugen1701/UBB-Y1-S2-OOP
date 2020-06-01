//
// Created by sweethuman on 08.05.2020.
//

#ifndef LAB9_MAINWINDOW_H
#define LAB9_MAINWINDOW_H

#include "../Service.h"
#include "../SubjectRepo.h"
#include <QDialog>
#include <QHeaderView>
#include <QSortFilterProxyModel>
#include <QtGui/QPainter>
#include <QtWidgets/QErrorMessage>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStyledItemDelegate>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <limits>
#include <ui_mainWindow.h>

class ImageDelegate : public QStyledItemDelegate {
  protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &opt, const QModelIndex &index) const {
        QPixmap image{index.data().toString() + ".jpg"};

        painter->drawPixmap(opt.rect, image);
    }
};

class AdoptedDogsWidget : public QDialog {
  private:
    QTableView *view;

  public:
    AdoptedDogsWidget(QSortFilterProxyModel *model, QWidget *parent = nullptr) : QDialog{parent} {
        QHBoxLayout *layout = new QHBoxLayout(this);
        this->view = new QTableView;
        this->view->setModel(model);
        QHeaderView *verticalHeader = this->view->verticalHeader();
        verticalHeader->setSectionResizeMode(QHeaderView::Fixed);
        verticalHeader->setDefaultSectionSize(200);
        this->view->setColumnWidth(3, 200);
        layout->addWidget(this->view);
        this->view->setItemDelegateForColumn(3, new ImageDelegate);
    }
};

class MainWindow : public QMainWindow {
    Q_OBJECT
  public:
    MainWindow(Service &service, SubjectRepo &dogs, SubjectRepo &adoptedDogs, QWidget *parent = nullptr)
        : service(service), dogs(dogs), adoptedDogs(adoptedDogs) {
        window.setupUi(this);
        setup();
    }
    ~MainWindow() {
    }

  private:
    Ui::MainWindow window;
    Service &service;
    SubjectRepo &dogs;
    SubjectRepo &adoptedDogs;
    AdoptedDogsWidget *adoptedWidget;
    void setup();
    void createActions();
  private slots:
    void undo();
    void redo();
};

#endif // LAB9_MAINWINDOW_H
