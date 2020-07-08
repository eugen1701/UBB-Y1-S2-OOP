//
// Created by sweethuman on 19.06.2020.
//

#ifndef EXAM_GUIDE_MODEL_STARTABLEMODEL_H
#define EXAM_GUIDE_MODEL_STARTABLEMODEL_H
#include "Domain.h"
#include "Repository.h"
#include <QtCore/QModelIndex>
class StarTableModel : public QAbstractTableModel {
  private:
    Repository<Star> &issueRepo;
    std::string getProperty(Star &issue, int column) const;

  public:
    StarTableModel(Repository<Star> &service) : issueRepo(service){};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
  public slots:
    void addStar();
    void removeStar();
    void updateAll();
};

#endif // EXAM_GUIDE_MODEL_STARTABLEMODEL_H
