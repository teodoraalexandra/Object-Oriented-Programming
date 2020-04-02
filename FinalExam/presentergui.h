#ifndef PRESENTERGUI_H
#define PRESENTERGUI_H

#include <QWidget>
#include "observer.h"
#include "controller.h"

namespace Ui {
class presentergui;
}

class presentergui : public QWidget, public observer
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

#endif // PRESENTERGUI_H
