#include "secdialog.h"
#include "ui_secdialog.h"
#include "paginatedcoatstablemodel.h"
#include <QSortFilterProxyModel>

SecDialog::SecDialog(Basket &b, QWidget *parent) :
    QDialog(parent), basket { b },
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    // create the model
    this->tableModel = new GenesTableModel{ this->basket };
    // create and set the model for the paginated table view
    this->setupPaginatedTableView();
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::setupPaginatedTableView()
{
    PaginatedGenesTableModel* pagTableModel = new PaginatedGenesTableModel{ this->basket };
    ui->paginatedGenesTableView->setModel(pagTableModel);

    // force the columns to resize, according to the size of their contents
    ui->paginatedGenesTableView->resizeColumnsToContents();
    // hide the vertical header
    ui->paginatedGenesTableView->verticalHeader()->hide();
}


