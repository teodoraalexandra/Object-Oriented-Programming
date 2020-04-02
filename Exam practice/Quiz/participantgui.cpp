//
// Created by Teodora Dan on 2019-06-12.
//

#include "participantgui.h"
#include "ui_participantgui.h"
#include <fstream>
#include <QMessageBox>
#include "participant.h"

participantgui::participantgui(controller& c, QWidget *parent) :
        QWidget(parent), ctrl {c},
        ui(new Ui::participantgui)
{
    ui->setupUi(this);
    populateList();
    ui->label->setText("0");
    connect(ui->answerButton, &QPushButton::clicked, this, &participantgui:: answerButtonHandler);
}

participantgui::~participantgui()
{
}

void participantgui::update() {
    populateList();
}

void participantgui::populateList() {
    ui->pquestionList->clear();

    for (auto& q : this->ctrl.getQuestionsByScoreDescending())
    {
        ui->pquestionList->addItem(QString::fromStdString(q.onlyForParticipants()));
    }
}

void participantgui::answerButtonHandler() {
    int idx = this->getSelectedIndex();
    QListWidgetItem *item = ui->pquestionList->item(idx);

    //chech if we can answer the question
    if (item->background().color() == "green") {
        QMessageBox msgBox;
        msgBox.setText("You have already answered.");
        msgBox.exec();
    }

    QString answer = ui->lineEdit->text();
    std::string answer_string = answer.toUtf8().constData();

    if ( answer_string == this->ctrl.getQuestions()[idx].getAnswer() ) {
        scor_participant += this->ctrl.getQuestions()[idx].getScore();
        QString s = QString::number(scor_participant);
        ui->label->setText(s);
    }

    item->setBackgroundColor("green");
}

int participantgui::getSelectedIndex() {
    if (ui->pquestionList->count() == 0)
        return -1;

    QModelIndexList index = ui->pquestionList->selectionModel()->selectedIndexes();
    int idx = index.at(0).row();
    return idx;
}
