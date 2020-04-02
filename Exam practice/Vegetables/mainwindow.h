#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vegetable.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<vegetable> vegetables;

private:
    Ui::MainWindow *ui;
    void populateList(std::vector<vegetable> vegetables);
    void filterButtonHandler();
    void deleteButtonHandler();
    int getSelectedIndex();
};

#endif // MAINWINDOW_H
