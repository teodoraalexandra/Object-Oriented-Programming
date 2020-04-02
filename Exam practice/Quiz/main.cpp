#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QString>
#include "presentergui.h"
#include "participantgui.h"
#include "participant.h"
#include "controller.h"
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //show the presenter window
    controller ctrl;
    presentergui presenter_window {ctrl};

    //add the observer
    ctrl.addObserver(&presenter_window);
    presenter_window.show();

    std::ifstream input_file;
    input_file.open("/Users/teodoradan/Desktop/participant.txt");
    if (!input_file) {
        std::cerr << "Error in opening the file" << std::endl;
    }

    //create window for each participant
    participant participant;
    std::vector<std::string> participant_names;
    while (input_file >> participant.name >> participant.score) {
        participant_names.push_back(participant.name);
    }

    participantgui participant1 {ctrl};
    participant1.setWindowTitle(QString::fromStdString(participant_names[0]));
    ctrl.addObserver(&participant1);
    participant1.show();

    participantgui participant2 {ctrl};
    participant2.setWindowTitle(QString::fromStdString(participant_names[1]));
    ctrl.addObserver(&participant2);
    participant2.show();

    return a.exec();
}