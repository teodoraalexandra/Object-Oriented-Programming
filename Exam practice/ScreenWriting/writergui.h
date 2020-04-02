#ifndef WRITERGUI_H
#define WRITERGUI_H

#include <QWidget>
#include <QAbstractTableModel>
#include "observer.h"
#include <vector>
#include "controller.h"

namespace Ui {
class writergui;
}

class TestModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TestModel(QObject *parent = 0);

    void populateData(const QList<QString> &description,const QList<QString> &status, const QList<QString> &creator, const QList<QString> &act);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QList<QString> tm_description;
    QList<QString> tm_status;
    QList<QString> tm_creator;
    QList<QString> tm_act;
};

class writergui : public QWidget, public observer
{
    Q_OBJECT
public:
    controller& ctrl;
public:
    explicit writergui(controller& c, QWidget *parent = nullptr);
    ~writergui();
    void update() override;

private:
    Ui::writergui *ui;
    void populateList();
    void addButtonHandler();
    void developButtonHandler();
    std::vector<idea> ideas;
};

#endif // WRITERGUI_H
