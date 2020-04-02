#include "writergui.h"
#include "ui_writergui.h"
#include <QTableView>
#include <QListWidgetItem>
#include <QMessageBox>
#include "mymodel.h"

writergui::writergui(controller&c, QWidget *parent) :
    QWidget(parent), ctrl {c},
    ui(new Ui::writergui)
{
    ui->setupUi(this);
    populateList();
    connect(ui->pushButton, &QPushButton::clicked, this, &writergui::addButtonHandler);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &writergui::developButtonHandler);
}

writergui::~writergui()
{
    delete ui;
}

TestModel::TestModel(QObject *parent) : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
void TestModel::populateData(const QList<QString> &description,const QList<QString> &status, const QList<QString> &creator, const QList<QString> &act)
{
    tm_description.clear();
    tm_description = description;
    tm_status.clear();
    tm_status = status;
    tm_creator.clear();
    tm_creator = creator;
    tm_act.clear();
    tm_act = act;
    return;
}

int TestModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return tm_description.length();
}

int TestModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4;
}

QVariant TestModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return tm_description[index.row()];
    } else if (index.column() == 1) {
        return tm_status[index.row()];
    } else if (index.column() == 2) {
        return tm_creator[index.row()];
    } else if (index.column() == 3) {
        return tm_act[index.row()];
    }
    return QVariant();
}

QVariant TestModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Description");
        } else if (section == 1) {
            return QString("Status");
        } else if (section == 2) {
            return  QString("Creator");
        } else if (section == 3) {
            return QString("Act");
        }
    }
    return QVariant();
}

void writergui::update()
{
    populateList();
}

void writergui::populateList()
{
    QList<QString> description;
    QList<QString> status;
    QList<QString> creator;
    QList<QString> act;

    ideas = this->ctrl.getIdeas();
    for (auto i : ideas) {
        description.append(QString::fromStdString(i.getDescription()));
        status.append(QString::fromStdString(i.getStatus()));
        creator.append(QString::fromStdString(i.getCreator()));
        act.append(QString::fromStdString(i.getAct()));
    }

    // Create model:
    TestModel *myModel = new TestModel(this);

    // Populate model with data:
    myModel->populateData(description, status, creator, act);

    // Connect model to table view:
    ui->tableView->setModel(myModel);

    // Make table header visible and display table:
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();
}

void writergui::addButtonHandler() {

    QString description = ui->lineEdit->text();
    std::string description_bun = description.toUtf8().constData();
    QString act = ui->lineEdit_2->text();
    std::string act_bun = act.toUtf8().constData();

    if (ui->lineEdit->text().isEmpty() or ui->lineEdit_2->text().isEmpty()) {
            QMessageBox msgBox;
            msgBox.setText("One of the field is empty");
            msgBox.exec();
    } else {
        std::string creator = QWidget::windowTitle().toUtf8().constData();
        idea idea_to_add = idea{description_bun, "proposed", creator, act_bun};
            int ok = 0;
            for (auto&q : this->ctrl.getIdeas()) {
                if (q.getDescription() == description_bun) {
                    ok = 1;
                    QMessageBox msgBox;
                    msgBox.setText("Sorry. This id already exists.");
                    msgBox.exec();
                }
            }

            if (ok == 0) {
                ctrl.addIdea(idea_to_add);
                this->populateList();
            }
        }
}

void writergui::developButtonHandler() {
    ideas = this->ctrl.getIdeas();
    for (auto i : ideas) {
        if (i.getStatus() == "accepted")
            ui->textEdit->append(QString::fromStdString(i.toString()));
    }
}
