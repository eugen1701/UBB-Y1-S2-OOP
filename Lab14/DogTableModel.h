//
// Created by sweethuman on 16.05.2020.
//

#ifndef LAB9_DOGTABLEMODEL_H
#define LAB9_DOGTABLEMODEL_H

#include "Service.h"
#include <QtCore/QAbstractTableModel>
class DogTableModel : public QAbstractTableModel {
  private:
    Service &service;
    std::string dogProperty(Dog &dog, int column) const;

  public:
    DogTableModel(Service &service) : service(service){};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
  public slots:
    void addDog();
    void removeDog();
};

#endif // LAB9_DOGTABLEMODEL_H
