#include "MainWindow.h"
#include "secondwindow.h"
#include "MemoryController.h"
#include "FileController.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>

MainWindow::MainWindow(Repository& _repository, Basket& _basket, QWidget *parent) : QMainWindow(parent), repository{ _repository }, basket{ _basket }
{
    ui.setupUi(this);

    QObject::connect(ui.memoryButton, &QPushButton::clicked, this, &MainWindow::memoryWidget);
    QObject::connect(ui.fileButton, &QPushButton::clicked, this, &MainWindow::fileWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::memoryWidget()
{
    this->setCursor(Qt::WaitCursor);

    std::vector<Coat> coats{ Coat{ "Name1", "Size1", "1", "Photo1" },
                             Coat{ "Name2", "Size2", "2", "Photo2" },
                             Coat{ "Name3", "Size3", "3", "Photo3" },
                             Coat{ "Name4", "Size4", "4", "Photo4" },
                             Coat{ "Name5", "Size5", "5", "Photo5" },
                             Coat{ "Name6", "Size6", "6", "Photo6" },
                             Coat{ "Name7", "Size7", "7", "Photo7" },
                             Coat{ "Name8", "Size8", "8", "Photo8" },
    };
    std::vector<Coat> basketCoats;
    std::vector<Coat> filterCoats;
    std::vector<Coat> nextCoats;

    std::vector<Coat> undoCoats{ Coat{ "Name1", "Size1", "1", "Photo1" },
                             Coat{ "Name2", "Size2", "2", "Photo2" },
                             Coat{ "Name3", "Size3", "3", "Photo3" },
                             Coat{ "Name4", "Size4", "4", "Photo4" },
                             Coat{ "Name5", "Size5", "5", "Photo5" },
                             Coat{ "Name6", "Size6", "6", "Photo6" },
                             Coat{ "Name7", "Size7", "7", "Photo7" },
                             Coat{ "Name8", "Size8", "8", "Photo8" },
    };

    std::vector<Coat> redoCoats{ Coat{ "Name1", "Size1", "1", "Photo1" },
                                 Coat{ "Name2", "Size2", "2", "Photo2" },
                                 Coat{ "Name3", "Size3", "3", "Photo3" },
                                 Coat{ "Name4", "Size4", "4", "Photo4" },
                                 Coat{ "Name5", "Size5", "5", "Photo5" },
                                 Coat{ "Name6", "Size6", "6", "Photo6" },
                                 Coat{ "Name7", "Size7", "7", "Photo7" },
                                 Coat{ "Name8", "Size8", "8", "Photo8" },
    };

    MemoryController* window = new MemoryController{ coats, basketCoats, filterCoats , nextCoats , undoCoats , redoCoats };
    this->setCursor(Qt::ArrowCursor);

    window->resize(1500, 1000);
    window->show();
}

void MainWindow::fileWidget()
{
    this->setCursor(Qt::WaitCursor);
    std::vector<Coat> coats;
    std::vector<Coat> undoCoats;
    std::vector<Coat> redoCoats;

    std::ifstream input_file;
    input_file.open("/Users/teodoradan/CLionProjects/Lab10-11/Files/repository.txt");
    if (!input_file) {
        std::cerr << "Error in opening the file" << std::endl;
        return;
    }

    Coat coat;
    while (input_file >> coat.name >> coat.size >> coat.price >> coat.photo) {
        coats.push_back(coat);
        undoCoats.push_back(coat);
        redoCoats.push_back(coat);
    }

    std::vector<Coat> basketCoats;
    std::vector<Coat> filterCoats;
    std::vector<Coat> nextCoats;

    MemoryController* window = new MemoryController{coats, basketCoats, filterCoats, nextCoats , undoCoats , redoCoats };

    this->setCursor(Qt::ArrowCursor);

    window->resize(1500, 1000);
    window->show();
}

