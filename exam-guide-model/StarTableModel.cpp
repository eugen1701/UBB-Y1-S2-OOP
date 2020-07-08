//
// Created by sweethuman on 19.06.2020.
//

#include "StarTableModel.h"
int StarTableModel::rowCount(const QModelIndex &parent) const {
    return issueRepo.getAll().size();
}

int StarTableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}
QVariant StarTableModel::data(const QModelIndex &index, int role) const {
    switch (role) {
    case Qt::DisplayRole: {
        auto dog = issueRepo.getAll()[index.row()];
        return QVariant(QString::fromStdString(getProperty(dog, index.column())));
    }
    default:
        return QVariant();
    }
}
std::string StarTableModel::getProperty(Star &issue, int column) const {
    switch (column) {
    case 0:
        return issue.name;
    case 1:
        return issue.constellation;
    case 2:
        return std::to_string(issue.ra);
    case 3:
        return std::to_string(issue.dec);
    case 4:
        return std::to_string(issue.diameter);
    default:
        return "";
    }
}

QVariant StarTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
        case 0:
            return QVariant(QString("Name"));
        case 1:
            return QVariant(QString("Constellation"));
        case 2:
            return QVariant(QString("Right Ascension"));
        case 3:
            return QVariant(QString("Declination"));
        case 4:
            return QVariant(QString("Diameter"));
        }
    }
    return QVariant();
}
bool StarTableModel::insertRows(int row, int count, const QModelIndex &parent) {
    if (row > rowCount() || row < 0) {
        return false;
    }
    emit layoutAboutToBeChanged();
    beginInsertRows(parent, row, row + count);
    endInsertRows();
    emit layoutChanged();
    return true;
}
bool StarTableModel::removeRows(int row, int count, const QModelIndex &parent) {
    if (row > rowCount() || row < 0) {
        return false;
    }
    emit layoutAboutToBeChanged();
    beginRemoveRows(parent, row, row + count);
    endRemoveRows();
    emit layoutChanged();
    return true;
}
void StarTableModel::addStar() {
    insertRows(rowCount() - 1, 0);
}
void StarTableModel::removeStar() {
    removeRows(rowCount(), 0);
}
void StarTableModel::updateAll() {
    removeRows(0, rowCount());
    insertRows(0, rowCount());
}