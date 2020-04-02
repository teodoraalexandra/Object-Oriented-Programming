#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <repo.h>
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    repo repo;
    equations = repo.readFromFile();
    this->populateList(equations);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow:: updateButtonHandler);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow:: solutionButtonHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateList(std::vector<equation> equations_param) {
    if (ui->listWidget->count() > 0)
            ui->listWidget->clear();

    for (auto e : equations_param)
        {
            QString itemInList = QString::fromStdString(e.getFirst()+ "*x^2 + " + e.getSecond() + "*x + " + e.getThird());
            QListWidgetItem* item = new QListWidgetItem{ itemInList };
            ui->listWidget->addItem(item);
        }
}

void MainWindow::updateButtonHandler() {
    int idx = this->getSelectedIndex();
    QString first = ui->lineEdit->text();
    QString second = ui->lineEdit_2->text();
    QString third = ui->lineEdit_3->text();

    equation e = this->equations[idx];

    std::string stringFirst = first.toUtf8().constData();
    std::string stringSecond = second.toUtf8().constData();
    std::string stringThird = third.toUtf8().constData();

    equation newEquation = equation{ stringFirst, stringSecond, stringThird };
    e = newEquation;
    this->equations[idx] = newEquation;
    this->populateList(equations);
}

void MainWindow::solutionButtonHandler() {
    /*
     * INPUT: the index of the equation selected by the user
     * OUTPUT: in another list will be displayed the disciminant together with values of corresponding solution and their nature
     * EXCEPTION: if user click the button without selecting the equation
     */

    if (ui->listWidget_2->count() > 0)
                ui->listWidget_2->clear();

    int idx = this->getSelectedIndex();
    equation e = this->equations[idx];
    int first = std::stoi(e.getFirst());
    int second = std::stoi(e.getSecond());
    int third = std::stoi(e.getThird());
    int delta = second*second - 4*first*third;

    int x1 = ((-second) + sqrt(delta)) / (2*first);
    int x2 = ((-second) - sqrt(delta)) / (2*first);

    QString deltaString = QString::number(delta);
    QString x1String = QString::number(x1);
    QString x2String = QString::number(x2);

    QListWidgetItem* item = new QListWidgetItem { "Delta: " + deltaString };
    QListWidgetItem* item2 = new QListWidgetItem { "x1: " + x1String };
    QListWidgetItem* item3 = new QListWidgetItem { "x2: " + x2String };

    ui->listWidget_2->addItem(item);
    ui->listWidget_2->addItem(item2);
    ui->listWidget_2->addItem(item3);

    QListWidgetItem* item4 = new QListWidgetItem { "Imaginary solutions " };
    QListWidgetItem* item5 = new QListWidgetItem { "Real solutions "};
    if (delta > 0) {
        ui->listWidget_2->addItem(item5);
    } else {
        ui->listWidget_2->addItem(item4);
    }
}

int MainWindow::getSelectedIndex() {
    if (ui->listWidget->count() == 0)
        return -1;

    QModelIndexList index = ui->listWidget->selectionModel()->selectedIndexes();
    int idx = index.at(0).row();
    return idx;
}
