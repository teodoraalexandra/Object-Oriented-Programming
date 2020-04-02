#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "paginatedcoatstablemodel.h"
#include <QSortFilterProxyModel>



SecondWindow::SecondWindow(Repository &r, QWidget *parent) :
    QMainWindow(parent), repo { r }
    //ui(new Ui::SecondWindowUI)
{
    //ui->setupUi(this);

    // create the model
    this->tableModel = new GenesTableModel{ this->repo };

    // set the model for the table view
    this->setupTableView();

    // set the model for the tree view
    this->setupTreeView();

    // set the model for the list view
     //this->genesListView->setModel(this->tableModel);

     // create and set the model for the paginated table view
     this->setupPaginatedTableView();

     // set the model for the table view, the one that should display images
     this->setupPictureTableView();
}

SecondWindow::~SecondWindow()
{
}

void SecondWindow::setupTableView()
{
    // set the model
    // ui.genesTableView->setModel(this->tableModel);

    // create and set a QSortFilterProxyModel and enable sorting
    //QSortFilterProxyModel* proxyModel =
        //new QSortFilterProxyModel{};
    //proxyModel->setSourceModel(this->tableModel);
    //ui->genesTableView->setSortingEnabled(true);
    //ui.genesTableView->setAlternatingRowColors(true); // use this if the background role is not used !

    // filtering
    /*proxyModel->setFilterRegExp(QRegExp("Human", Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(1);*/

    //ui->genesTableView->setModel(proxyModel);

    // force the columns to resize, according to the size of their contents
    //ui->genesTableView->resizeColumnsToContents();
    // hide the vertical header
    //ui.genesTableView->verticalHeader()->hide();
}

void SecondWindow::setupTreeView()
{
    //ui->genesTreeView->setModel(this->tableModel);
//
    // force the columns to resize, according to the size of their contents
    //ui->genesTreeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void SecondWindow::setupPaginatedTableView()
{
    PaginatedGenesTableModel* pagTableModel = new PaginatedGenesTableModel{ this->repo };
    //ui->paginatedGenesTableView->setModel(pagTableModel);

    // force the columns to resize, according to the size of their contents
    //ui->paginatedGenesTableView->resizeColumnsToContents();
    // hide the vertical header
    //ui->paginatedGenesTableView->verticalHeader()->hide();
}

void SecondWindow::setupPictureTableView()
{
    // set the model
    //ui->picturesTableView->setModel(this->tableModel);

    // set the custom delegate
    //ui->picturesTableView->setItemDelegate(new PictureDelegate{});

    // force the columns to resize, according to the size of their contents
    //ui->picturesTableView->resizeColumnsToContents();
    //ui->picturesTableView->resizeRowsToContents();
    // hide the vertical header
    //ui->picturesTableView->verticalHeader()->hide();
}

