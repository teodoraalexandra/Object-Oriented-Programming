#ifndef PARTICIPANTGUI_H
#define PARTICIPANTGUI_H

#include <QWidget>
#include "controller.h"
#include "observer.h"

namespace Ui {
class participantgui;
}

class participantgui : public QWidget, public observer
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

#endif // PARTICIPANTGUI_H
