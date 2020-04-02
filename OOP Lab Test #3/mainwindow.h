#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <equation.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<equation> equations;

private:
    Ui::MainWindow *ui;
    void populateList(std::vector<equation> equations);
    void updateButtonHandler();
    void solutionButtonHandler();
    int getSelectedIndex();
};

#endif // MAINWINDOW_H
