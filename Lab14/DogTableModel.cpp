//
// Created by sweethuman on 16.05.2020.
//

#include "DogTableModel.h"
int DogTableModel::rowCount(const QModelIndex &parent) const {
    return service.getDogs().size();
}

int DogTableModel::columnCount(const QModelIndex &parent) const {
    return 4;
}
QVariant DogTableModel::data(const QModelIndex &index, int role) const {
    switch (role) {
    case Qt::DisplayRole: {
        auto dog = service.getDogs()[index.row()];
        return QVariant(QString::fromStdString(dogProperty(dog, index.column())));
    }
    default:
        return QVariant();
    }
}
std::string DogTableModel::dogProperty(Dog &dog, int column) const {
    switch (column) {
    case 0:
        return dog.getBreed();
    case 1:
        return dog.getName();
    case 2:
        return std::to_string(dog.getAge());
    case 3:
        return dog.getPhotograph();
    default:
        return "";
    }
}

QVariant DogTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
        case 0:
            return QVariant(QString("Breed"));
        case 1:
            return QVariant(QString("Name"));
        case 2:
            return QVariant(QString("Age"));
        case 3:
            return QVariant(QString("Photograph"));
        }
    }
    return QVariant();
}
bool DogTableModel::insertRows(int row, int count, const QModelIndex &parent) {
    if(row > rowCount() || row < 0){
        return false;
    }
    emit layoutAboutToBeChanged();
    beginInsertRows(parent, row, row+count);
    endInsertRows();
    emit layoutChanged();
    return true;
}
bool DogTableModel::removeRows(int row, int count, const QModelIndex &parent) {
    if(row > rowCount() || row < 0){
        return false;
    }
    emit layoutAboutToBeChanged();
    beginRemoveRows(parent, row, row+count);
    endRemoveRows();
    emit layoutChanged();
    return true;
}
void DogTableModel::addDog() {
    insertRows(rowCount()-1,0);
}
void DogTableModel::removeDog() {
    removeRows(rowCount()-1, 0);
}
