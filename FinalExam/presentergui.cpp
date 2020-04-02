#include "presentergui.h"
#include "ui_presentergui.h"
#include "QMessageBox"
#include <iostream>
#include <fstream>
using namespace std;

presentergui::presentergui(controller& c, QWidget *parent) :
    QWidget(parent), ctrl {c},
    ui(new Ui::presentergui)
{
    ui->setupUi(this);
    this->setWindowTitle("Presenter");
    populateList();

    connect(ui->pushButton, &QPushButton:: clicked, this, &presentergui::addButtonHandler);
}

presentergui::~presentergui()
{
    delete ui;
}

void presentergui::populateList() {
    ui->listWidget->clear();

    for (auto q: this->ctrl.getQuestionSortId()) {
        ui->listWidget->addItem(QString::fromStdString(q.toString()));
    }
}

void presentergui::update() {
    populateList();
}

void presentergui::addButtonHandler() {
    /// INPUT: id, text, answer, score from the four line edits
    /// OUTPUT: if there are no exception, we add our question in the controller, and call the populateList()
    /// EXCEPTION: #1 : if the question with the same id exists (->QMessageBox)
    /// EXCEPTION: #2 : if one of the fields are empty (->QMessageBox)
    /// We convert from QString all input (either to int or string) and create the question_to_add
    int ok = 0;
    QString id = ui->lineEdit->text();
    int id_bun = id.split(" ")[0].toInt();
    QString text = ui->lineEdit_2->text();
    std::string text_bun = text.toUtf8().constData();
    QString answer = ui->lineEdit_3->text();
    std::string answer_bun = answer.toUtf8().constData();
    QString score = ui->lineEdit_4->text();
    int score_bun = score.split(" ")[0].toInt();

    question question_to_add = question{ id_bun, text_bun, answer_bun, score_bun };

    for (auto q: this->ctrl.getQuestions()) {
        if (id_bun == q.getId()) {
            ok = 1;
            QMessageBox msgBox;
            msgBox.setText("This ID already exists.");
            msgBox.exec();
        }
    }

    if (ui->lineEdit->text().isEmpty() or ui->lineEdit_2->text().isEmpty() or ui->lineEdit_3->text().isEmpty() or ui->lineEdit_4->text().isEmpty()) {
        ok = 1;
        QMessageBox msgBox;
        msgBox.setText("One field is empty.");
        msgBox.exec();
    }

    if (ok == 0) {
        ctrl.addQuestion(question_to_add);
        populateList();
    }

    //save to file
    ofstream myfile ("/Users/teodoradan/Desktop/questions.txt");
    if (myfile.is_open())
    {
        for (auto q: ctrl.getQuestions()) {
            myfile << q.getId() << " " << q.getText() << " " << q.getAnswer() << " " << q.getScore() << "\n";
        }
        myfile.close();
    }

    else cout << "Error in opening the file";
}
