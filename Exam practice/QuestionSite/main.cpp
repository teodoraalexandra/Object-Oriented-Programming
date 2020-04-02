#include "mainwindow.h"
#include "questiongui.h"
#include "user.h"
#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    controller ctrl;

    std::ifstream input_file;
    input_file.open("/Users/teodoradan/Desktop/user.txt");
    if (!input_file) {
       std::cerr << "Error in opening the file" << std::endl;
    }

    //create window for each participant
    user user;
    std::vector<std::string> user_names;
    while (input_file >> user.name) {
           user_names.push_back(user.name);
    }

    questiongui window1 {ctrl};
    window1.setWindowTitle(QString::fromStdString(user_names[0]));
    ctrl.addObserver(&window1);
    window1.show();

    questiongui window2 {ctrl};
    window2.setWindowTitle(QString::fromStdString(user_names[1]));
    ctrl.addObserver(&window2);
    window2.show();

    return a.exec();
}
