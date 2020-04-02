#ifndef QUESTIONGUI_H
#define QUESTIONGUI_H

#include <QWidget>
#include "observer.h"
#include "controller.h"

namespace Ui {
class questiongui;
}

class questiongui : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit questiongui(controller& c, QWidget *parent = nullptr);
    ~questiongui();
    controller& ctrl;
    void update() override;

private:
    Ui::questiongui *ui;
    void populateList();
    void addButtonHandler();
    void getSelectedIndex();
};

#endif // QUESTIONGUI_H
