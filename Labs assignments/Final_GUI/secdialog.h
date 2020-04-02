#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <repository.h>
#include <basket.h>
#include <coattablemodel.h>
#include <QTableView>
#include <QListView>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(Basket& b, QWidget *parent = nullptr);
    ~SecDialog();

private:
    Ui::SecDialog *ui;
    Basket& basket;
    GenesTableModel* tableModel;
    QListView* genesListView;

    void setupPaginatedTableView();
};

#endif // SECDIALOG_H
