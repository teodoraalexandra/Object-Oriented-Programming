//
// Created by Teodora Dan on 2019-06-12.
//

#include "presentergui.h"
#include "ui_presentergui.h"
#include <QMessageBox>

presentergui::presentergui(controller& c, QWidget *parent) :
        QWidget(parent), ctrl {c},
        ui(new Ui::presentergui)
{
    ui->setupUi(this);
    this->setWindowTitle("Presenter");
    populateList();

    connect(ui->addButton, &QPushButton::clicked, this, &presentergui:: addButtonHandler);
}

presentergui::~presentergui()
{
}


void presentergui::update() {
    populateList();
}

void presentergui::populateList() {
    ui->questionList->clear();

    for (auto& q : this->ctrl.getQuestionsByIdAscending())
    {
        ui->questionList->addItem(QString::fromStdString(q.toString()));
    }
}

void presentergui::addButtonHandler() {
    QString id = ui->lineEdit->text();
    int id_bun = id.split(" ")[0].toInt();
    QString text = ui->lineEdit_2->text();
    std::string text_bun = text.toUtf8().constData();
    QString answer = ui->lineEdit_3->text();
    std::string answer_bun = answer.toUtf8().constData();
    QString score = ui->lineEdit_4->text();
    int score_bun = score.split(" ")[0].toInt();

    if (ui->lineEdit->text().isEmpty() or ui->lineEdit_2->text().isEmpty() or ui->lineEdit_3->text().isEmpty() or ui->lineEdit_4->text().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText("One of the field is empty");
        msgBox.exec();
    } else {
        question question_to_add = question{id_bun, text_bun, answer_bun, score_bun};
        int ok = 0;
        for (auto&q : this->ctrl.getQuestions()) {
            if (q.getId() == id_bun) {
                ok = 1;
                QMessageBox msgBox;
                msgBox.setText("Sorry. This id already exists.");
                msgBox.exec();
            }
        }

        if (ok == 0) {
            ctrl.addQuestion(question_to_add);
            this->populateList();
        }
    }
}

int presentergui::getSelectedIndex() {
    if (ui->questionList->count() == 0)
        return -1;

    QModelIndexList index = ui->questionList->selectionModel()->selectedIndexes();
    int idx = index.at(0).row();
    return idx;
}

