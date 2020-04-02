#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainWindow.h"
#include "Repository.h"
#include "Basket.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(Repository& _repository, Basket& _basket, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindowUI ui;
    Repository& repository;
    Basket& basket;

public:
    void memoryWidget();
    void fileWidget();
};

#endif // MAINWINDOW_H
