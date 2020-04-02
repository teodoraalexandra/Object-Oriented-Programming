//
// Created by Teodora Dan on 2019-06-12.
//

#ifndef QUIZ2_PRESENTERGUI_H
#define QUIZ2_PRESENTERGUI_H


#include <QWidget>
#include "observer.h"
#include "controller.h"
#include <question.h>
#include <repository.h>
#include <string>

namespace Ui {
    class presentergui;
}

class presentergui : public QWidget, public Observer
{
    Q_OBJECT

private:
    controller& ctrl;
public:
    explicit presentergui(controller& c, QWidget *parent = nullptr);
    ~presentergui();
    void update() override;

private:
    Ui::presentergui *ui;
    void populateList();
    void addButtonHandler();
    int getSelectedIndex();
};


#endif //QUIZ2_PRESENTERGUI_H
