//
// Created by sweethuman on 01.06.2020.
//

#ifndef LAB14_ADOPTEDDOGTABLEMODEL_H
#define LAB14_ADOPTEDDOGTABLEMODEL_H
#include "Service.h"
#include "SubjectRepo.h"
#include <QtCore/QAbstractTableModel>
#include <QtGui/QPainter>
#include <QtWidgets/QStyleOptionViewItem>
#include <QtWidgets/QStyledItemDelegate>


class AdoptedDogTableModel : public QAbstractTableModel {
  private:
    Service &service;
    std::string dogProperty(Dog &dog, int column) const;

  public:
    AdoptedDogTableModel(Service &service) : service(service){};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
  public slots:
        void addDog();
    void removeDog();
    void actionReaction(Action::ExecutedAction action);
};

#endif // LAB14_ADOPTEDDOGTABLEMODEL_H
