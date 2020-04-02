#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include "participantgui.h"
#include "presentergui.h"
#include "controller.h"
#include "participant.h"
#include <assert.h>
using namespace std;

void test() {
    //for the add operation
    controller c;
    question q1 { 1, "2", "3", 4};
    c.addQuestion(q1);
    question q2 { 2, "2", "3", 4};
    c.addQuestion(q2);
    assert( c.questions.size() == 2 );
}

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
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
