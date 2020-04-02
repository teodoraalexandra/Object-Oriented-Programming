#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>

class StringListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    StringListModel(QObject *parent = nullptr)
        : QAbstractListModel(parent) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    //for editable
    Qt::ItemFlags flags(const QModelIndex &index) const override;
        bool setData(const QModelIndex &index, const QVariant &value,
                     int role = Qt::EditRole) override;

    //insert and remove rows
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;

private:
    QStringList stringList;
};

#endif // MYMODEL_H
