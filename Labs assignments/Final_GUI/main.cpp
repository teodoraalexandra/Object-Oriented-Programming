#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include "repository.h"
#include "basket.h"
#include <QTreeView>
#include <QDirModel>
#include <QHeaderView>
#include <sstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::vector<Coat> coats;
    std::vector<Coat> basketCoats;
    ///Users/teodoradan/Desktop/Genes.txt
    Repository repository{ coats, "/Users/teodoradan/CLionProjects/Lab10-11/Files/repository.txt"};
    Basket basket{basketCoats};
    MainWindow w{ repository , basket };
    w.show();

    return a.exec();
}




