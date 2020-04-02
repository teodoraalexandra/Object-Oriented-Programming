#include "questiongui.h"
#include "ui_questiongui.h"
#include <QMessageBox>

questiongui::questiongui(controller& c, QWidget *parent) :
    QWidget(parent), ctrl {c},
    ui(new Ui::questiongui)
{
    ui->setupUi(this);
    populateList();

    connect(ui->pushButton, &QPushButton::clicked, this, &questiongui::addButtonHandler);
}

questiongui::~questiongui()
{
    delete ui;
}

void questiongui::update() {
    populateList();
}

void questiongui::populateList() {
    ui->listWidget->clear();

    for (auto q: this->ctrl.getQuestions()) {
        ui->listWidget->addItem(QString::fromStdString(q.toPrint()));
    }
}

void questiongui::addButtonHandler() {
    QString id = ui->lineEdit->text();
    int id_bun = id.split(" ")[0].toInt();
    QString text = ui->lineEdit_2->text();
    std::string text_bun = text.toUtf8().constData();

    if (ui->lineEdit->text().isEmpty() or ui->lineEdit_2->text().isEmpty()) {
            QMessageBox msgBox;
            msgBox.setText("One of the field is empty");
            msgBox.exec();
    } else {
            QString name = QWidget::windowTitle();
            std::string name_bun = name.toUtf8().constData();
            question question_to_add = question{ id_bun, text_bun, name_bun };
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
