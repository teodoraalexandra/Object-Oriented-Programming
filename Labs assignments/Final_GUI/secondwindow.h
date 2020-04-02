#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <repository.h>
#include <coattablemodel.h>
#include <QTableView>
#include <ui_secondwindow.h>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    SecondWindow(Repository& r, QWidget *parent = nullptr);
    ~SecondWindow();

private:
    Ui::SecondWindow *ui;
    Repository& repo;
    GenesTableModel* tableModel;
    QListView* genesListView;
    QTableView* paginatedGenesTableView;

    void setupTableView();
    void setupTreeView();
    void setupPaginatedTableView();
    void setupPictureTableView();
};

#endif // SECONDWINDOW_H
