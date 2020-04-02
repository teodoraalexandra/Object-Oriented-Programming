#include "participantgui.h"
#include "ui_participantgui.h"
#include "QMessageBox"

participantgui::participantgui(controller& c, QWidget *parent) :
    QWidget(parent), ctrl { c },
    ui(new Ui::participantgui)
{
    ui->setupUi(this);
    populateList();
    ui->label->setText("0");
    connect(ui->pushButton, &QPushButton::clicked, this, &participantgui::answerButtonHandler);
}

participantgui::~participantgui()
{
    delete ui;
}

void participantgui::populateList() {
    ui->listWidget->clear();
    for (auto q : this->ctrl.getQuestionDescendingScore()) {
        ui->listWidget->addItem(QString::fromStdString(q.withoutAnswer()));
    }
}

void participantgui::update() {
    populateList();
}

void participantgui::answerButtonHandler() {
    /// INPUT: get the selected question calling getSelectedIndex() and the answer of the user
    /// OUTPUT: IF ANSWER IS CORRECT -> update the score of the user with the score of the question answered
    ///         OTHERWISE -> do nothing
    ///         In both cases, set the backgroynd color into green, so user can't answer the same question twice
    /// EXCEPTION: if the background is green, we show a message with QMessageBox
    ///
    int idx = this->getSelectedIndex();
    QListWidgetItem *item = ui->listWidget->item(idx);

    //chech if we can answer the question
    if (item->background().color() == "green") {
        QMessageBox msgBox;
        msgBox.setText("You have already answered.");
        msgBox.exec();
    }

    QString answer = ui->lineEdit->text();
    std::string answer_string = answer.toUtf8().constData();

    if ( answer_string == this->ctrl.getQuestionDescendingScore()[idx].getAnswer() ) {
        /// HERE WE UPDATE THE PARTICIPANT SCORE
        /// To the old score, we add the actual score of the corect answered question
        scor_participant += this->ctrl.getQuestionDescendingScore()[idx].getScore();
        QString s = QString::number(scor_participant);
        ui->label->setText(s);
    }

    item->setBackgroundColor("green");
}

int participantgui::getSelectedIndex() {
    if (ui->listWidget->count() == 0)
        return -1;

    QModelIndexList index = ui->listWidget->selectionModel()->selectedIndexes();
    int idx = index.at(0).row();
    return idx;
}
