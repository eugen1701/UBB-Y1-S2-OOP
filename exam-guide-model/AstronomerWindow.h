//
// Created by sweethuman on 20.06.2020.
//

#ifndef EXAM_GUIDE_MODEL_ASTRONOMERWINDOW_H
#define EXAM_GUIDE_MODEL_ASTRONOMERWINDOW_H

#include "Domain.h"
#include "Repository.h"
#include <QtCore/QSortFilterProxyModel>
#include <QtWidgets/QMainWindow>
#include <ui_AstronomerWindow.h>

class ConstellationFilter : public QSortFilterProxyModel {
    Q_OBJECT
  public:
    explicit ConstellationFilter(QObject *parent = nullptr) : QSortFilterProxyModel(parent) {
        // general parameters for the custom model
        constellationRegExp.setCaseSensitivity(Qt::CaseInsensitive);
        constellationRegExp.setPatternSyntax(QRegExp::RegExp);
    }

    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override {
        QModelIndex constellationIndex = sourceModel()->index(sourceRow, 1, sourceParent);

        QString constellation = sourceModel()->data(constellationIndex).toString();

        return (constellation.contains(constellationRegExp));
    }
  public slots:
    void setConstellationFilter(const QString &regExp) {
        constellationRegExp.setPattern(regExp);
        invalidateFilter();
    }

  private:
    QRegExp constellationRegExp;
};

class AstronomerWindow : public QMainWindow {
    Q_OBJECT
  private:
    Ui::AstronomerWindow window;
    Astronomer &astron;
    QAbstractTableModel *model;
    ConstellationFilter *filterModel;
    Repository<Star> &repo;
    void setup();

  public:
    AstronomerWindow(Astronomer &astron, QAbstractTableModel *model, Repository<Star> &repo, QWidget *parent = nullptr);
  signals:
    void starAdded();
  public slots:
    void checkClick();
    void addClick();
    void modifiedSearch();
};
#endif // EXAM_GUIDE_MODEL_ASTRONOMERWINDOW_H
