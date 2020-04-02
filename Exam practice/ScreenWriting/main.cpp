#include "mainwindow.h"
#include "writergui.h"
#include "writer.h"
#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    controller ctrl;

    std::ifstream input_file;
    input_file.open("/Users/teodoradan/Desktop/writers.txt");
    if (!input_file) {
         std::cerr << "Error in opening the file" << std::endl;
     }

    //create window for each writer
    writer writer;
    std::vector<std::string> writer_names;
    while (input_file >> writer.name >> writer.expertise) {
            writer_names.push_back(writer.name);
    }

     writergui writer1 {ctrl};
     writer1.setWindowTitle(QString::fromStdString(writer_names[0]));
     ctrl.addObserver(&writer1);
     writer1.show();

     writergui writer2 {ctrl};
     writer2.setWindowTitle(QString::fromStdString(writer_names[1]));
     ctrl.addObserver(&writer2);
     writer2.show();

     writergui writer3 {ctrl};
     writer3.setWindowTitle(QString::fromStdString(writer_names[2]));
     ctrl.addObserver(&writer3);
     writer3.show();

    return a.exec();
}
