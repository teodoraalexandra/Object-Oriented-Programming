//
// Created by Teodora Dan on 2019-05-13.
//

#ifndef LAB10_11_MODE_INTERFACE_H
#define LAB10_11_MODE_INTERFACE_H

#endif //LAB10_11_MODE_INTERFACE_H

#include <string>
#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QObject>
#include "Controller.h"
using namespace std;

class UI {
private:
    Controller &controller;

public:
    UI(Controller &controller);

    int mode_A(string fileLocation, string mylistLocation, Controller controller, int argc, char *argv[]);

    int mode_B(string fileLocation, string mylistLocation, int position, int length, int basket_length,
               Controller controller, int argc, char *argv[]);

    int GUI(int argc, char *argv[], Controller controller);

    //void add_slot(const std::string &name, const std::string &size, int price, const std::string &photo);

    ~UI();

};

