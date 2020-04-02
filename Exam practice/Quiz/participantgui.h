//
// Created by Teodora Dan on 2019-06-12.
//

#ifndef QUIZ2_PARTICIPANTGUI_H
#define QUIZ2_PARTICIPANTGUI_H


#include <QWidget>
#include <question.h>
#include "observer.h"
#include "controller.h"
#include <repository.h>
#include <string>

namespace Ui {
    class participantgui;
}

class participantgui : public QWidget, public Observer
{
    Q_OBJECT

private:
    controller& ctrl;
    int scor_participant = 0;
public:
    explicit participantgui(controller& c, QWidget *parent = nullptr);
    ~participantgui();
    void update() override;

private:
    Ui::participantgui *ui;
    void populateList();
    void answerButtonHandler();
    int getSelectedIndex();
};


#endif //QUIZ2_PARTICIPANTGUI_H
