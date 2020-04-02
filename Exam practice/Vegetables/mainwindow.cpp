#include "mainwindow.h"
#include "repo.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    repo repo;
    //std::vector<vegetable> vegetables;
    vegetables = repo.readFromFile();
    this->populateList(vegetables);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow:: filterButtonHandler);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::deleteButtonHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

struct sortAlphabetically
{
    inline bool operator() (const vegetable& v1, const vegetable& v2)
    {
        return (v1.getName() < v2.getName());
    }
};



void MainWindow::populateList(std::vector<vegetable> vegetables_param) {
    if (ui->listWidget->count() > 0)
            ui->listWidget->clear();

    std::sort(vegetables_param.begin(), vegetables_param.end(), sortAlphabetically());
    for (auto v : vegetables_param)
        {
            QString itemInList = QString::fromStdString(v.getFamily() + " - " + v.getName() + " - " + v.getPart());
            QFont f{ "Verdana", 15 };
            QListWidgetItem* item = new QListWidgetItem{ itemInList };
            item->setFont(f);
            ui->listWidget->addItem(item);
        }
}

void MainWindow::filterButtonHandler() {
    if (ui->listWidget_2->count() > 0)
        ui->listWidget_2->clear();

    repo repo;
    std::vector<vegetable> vegetables;
    vegetables = repo.readFromFile();
    for (auto v : vegetables)
    {
        QString itemInList = QString::fromStdString(v.getFamily());
        QString family = ui->lineEdit->text();
        if (itemInList == family) {
            QString itemInListT = QString::fromStdString(v.getFamily() + " - " + v.getName() + " - " + v.getPart());
            QFont f{ "Verdana", 15 };
            QListWidgetItem* item = new QListWidgetItem { itemInListT };
            item->setFont(f);
            ui->listWidget_2->addItem(item);
        }
    }
}

void MainWindow::deleteButtonHandler() {
    int idx = this->getSelectedIndex();

    this->vegetables.erase(vegetables.begin() + idx);
    this->populateList(vegetables);
}

int MainWindow::getSelectedIndex() {
    if (ui->listWidget->count() == 0)
        return -1;

    QModelIndexList index = ui->listWidget->selectionModel()->selectedIndexes();
    int idx = index.at(0).row();
    return idx;
}
