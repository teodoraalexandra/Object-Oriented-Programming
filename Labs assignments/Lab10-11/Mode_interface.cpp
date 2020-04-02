//
// Created by Teodora Dan on 2019-05-13.
//

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "Controller.h"
#include "Mode_interface.h"
#include "Coat.h"
#include "Basket.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

//QT
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QString>

Basket basket;

class MyException : public std::exception
{
private:
    string message;

public:
    MyException(const string& s) : message(s)  {}

    const char* what() const throw() override {
        return this->message.c_str();
    }
};

UI::UI(Controller & otherController): controller(otherController)
{
}

/*void UI::add_slot(const std::string & name, const std::string & size, int price, const std::string & photo) {
    controller.add(name, size, price, photo);
}*/

int UI::GUI(int argc, char* argv[], Controller controller) {
    QApplication a(argc, argv);

    QWidget *big_widget = new QWidget{};
    QVBoxLayout *vertical_layout = new QVBoxLayout{};
    big_widget->setLayout(vertical_layout);

    QWidget w{};
    QLabel label("All trench coats: ");
    QListWidget list;

    QString coat_list;

    for (Coat& coat : controller.search()) {
        QString name = QString::fromStdString(coat.getName());
        QString size = QString::fromStdString(coat.getSize());
        QString price = QString::number(coat.getPrice());
        QString photo = QString::fromStdString(coat.getPhoto());
        coat_list = " Name: ";
        coat_list.append(name);
        coat_list.append(" ");
        coat_list.append("Size: ");
        coat_list.append(size);
        coat_list.append(" ");
        coat_list.append("Price: ");
        coat_list.append(price);
        coat_list.append(" ");
        coat_list.append("Photo: ");
        coat_list.append(photo);
        coat_list.append(" ");
        new QListWidgetItem(coat_list, &list);
    }

    QVBoxLayout layout{ &w };
    vertical_layout->addWidget(&label);
    vertical_layout->addWidget(&list);

    //create an information widget, with a QFormLayout
    QWidget *information = new QWidget{};
    QFormLayout *form_layout = new QFormLayout{};
    information->setLayout(form_layout);

    QLabel *labelName = new QLabel{ "&Name: " };
    QLineEdit *textBoxName = new QLineEdit{};
    labelName->setBuddy(textBoxName);
    textBoxName->text();

    form_layout->addRow(labelName, textBoxName);

    QLabel *labelSize = new QLabel{ "&Size: " };
    QLineEdit *textBoxSize = new QLineEdit{};
    labelSize->setBuddy(textBoxSize);
    textBoxSize->text();

    form_layout->addRow(labelSize, textBoxSize);

    QLabel *labelPrice = new QLabel{ "&Price: " };
    QLineEdit *textBoxPrice = new QLineEdit{};
    labelPrice->setBuddy(textBoxPrice);
    textBoxPrice->text();

    form_layout->addRow(labelPrice, textBoxPrice);

    QLabel *labelPhoto = new QLabel{ "&Photo: " };
    QLineEdit *textBoxPhoto = new QLineEdit{};
    labelPhoto->setBuddy(textBoxPhoto);
    textBoxPhoto->text();

    form_layout->addRow(labelPhoto, textBoxPhoto);

    //add the information widget to the window
    vertical_layout->addWidget(information);

    // create a widget with three buttons for three possible actions: Add, Update or Delete
    // this widget will have a QHBoxLayout
    QWidget* actions = new QWidget{};
    QHBoxLayout* horizontal_layout = new QHBoxLayout{};
    QPushButton *add = new QPushButton{ "&Add" };
    string name = textBoxName->text().toStdString();
    string size = textBoxSize->text().toStdString();
    int price = textBoxPrice->text().split(" ")[0].toInt();
    string photo = textBoxPhoto->text().toStdString();
    //QObject::connect(add, SIGNAL(clicked()), &a, SLOT(add_slot(name, size, price, photo)));

    QPushButton *update = new QPushButton{ "&Update" };
    QPushButton *remove = new QPushButton{ "&Delete" };
    horizontal_layout->addWidget(add);
    horizontal_layout->addWidget(update);
    horizontal_layout->addWidget(remove);
    actions->setLayout(horizontal_layout);

    // add the actions widget to the window
    vertical_layout->addWidget(actions);

    //show window
    big_widget->show();

    return a.exec();
}


int UI::mode_A(string fileLocation, string mylistLocation, Controller controller, int argc, char* argv[]) {
    return GUI(argc, argv, controller);

    //VALIDATIONS:
        //add
            //number of parameters
            //valid price
            //unexistent coat
        //update
            //number of parameters
            //valid price
            //existent coat
        //remove
            //number of parameters
            //existent coat
}

int UI::mode_B(string fileLocation, string mylistLocation, int position_repo, int length, int basket_length, Controller controller, int argc, char* argv[]) {
    int number_of_parameters = 0;
    char userInput[100];
    string parameter[100];
    int i = 0;
    fflush(stdin);
    cin.get(userInput, 100);
    cin.get();
    char *split_command;
    split_command = strtok(userInput, " ");
    Coat coat_B = controller.getCoat(position_repo);

    while (split_command != NULL) {
        parameter[i] = split_command;
        number_of_parameters ++;
        i++;
        split_command = strtok(NULL, ", ");
    }

    if (parameter[0] == "next") {
        try
        {
            if (number_of_parameters != 1) {
                //throw MyException ("Next has no additional parameters.\n");
            }
        }
        catch (std::exception &e)
        {
            cout << e.what();
            mode_B(fileLocation, mylistLocation, position_repo, length, basket_length, controller, argc, argv);
        }

        cout << "Name: " << coat_B.getName() << " Size: " << coat_B.getSize() << " Price: " << coat_B.getPrice() << " Photo: " << coat_B.getPhoto() << "\n";

        position_repo ++;
        if (position_repo >= length) {
            position_repo = 0;

            //SAVE TO FILE
            ofstream in;
            in.open (fileLocation);

            for (Coat& coat : controller.search()) {
                in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
            }

            in.close();

            mode_B(fileLocation, mylistLocation, position_repo, length, basket_length, controller, argc, argv);
        }
        else {
            //SAVE TO FILE
            ofstream in;
            in.open (fileLocation);

            for (Coat& coat : controller.search()) {
                in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
            }

            in.close();

            mode_B(fileLocation, mylistLocation, position_repo, length, basket_length, controller, argc, argv);
        }

    } else if (parameter[0] == "save") {
        int ok = 0;
        try
        {
            if (number_of_parameters != 2) {
                //throw MyException ("Save must take the name as a parameter.\n");
            }
        }
        catch (std::exception &e)
        {
            cout << e.what();
            mode_B(fileLocation, mylistLocation, position_repo, length, basket_length, controller, argc, argv);
        }

        for (Coat& coat : controller.search()) {
            if (parameter[1] == coat.getName()) {
                basket.add_basket(coat);

                basket_length++;

                cout << "Trench coat has been added to your shopping basket.\n";
                ok = 1;

                ofstream myfile;
                myfile.open (mylistLocation);

                if (mylistLocation.substr(mylistLocation.find_last_of(".") + 1) == "csv") {
                    for (i = 0; i < basket_length; i++) {
                        // Insert the data to file
                        Coat coat = basket.getCoat_basket(i);
                        myfile << coat.getName() << ", "
                             << coat.getSize() << ", "
                             << coat.getPrice() << ", "
                             << coat.getPhoto()
                             << "\n";
                    }

                    myfile.close();
                    cout << "myList was added to a csv file\n";

                    //OPENING IN BROWSER
                    string text_edit = "'/Applications/Google Chrome.app/Contents/MacOS/Google Chrome'";
                    string path_open;

                    path_open = text_edit + " " + "'" + mylistLocation + "'";
                    system(path_open.c_str());

                } else if (mylistLocation.substr(mylistLocation.find_last_of(".") + 1) == "html") {
                    myfile << "<!DOCTYPE html><html><head><title>Coat shopping basket</title></head><body><table border='1'>";
                    myfile << "<tr><td>Name</td><td>Size</td><td>Price</td><td>Photo</td></tr>";

                    for (i = 0; i < basket_length; i++) {
                        Coat coat = basket.getCoat_basket(i);
                        myfile << "<tr><td>" << coat.getName() << "</td><td>" << coat.getSize() << "</td>"
                               << "<td>" << coat.getPrice() << "</td>"
                               << "<td>" << coat.getPhoto() << "</td></tr>";
                    }

                    myfile << "</table></body></html>";
                    myfile.close();
                    cout << "myList was added to a html file\n";

                    //OPENING IN BROWSER
                    string google = "'/Applications/Google Chrome.app/Contents/MacOS/Google Chrome'";
                    string path_open;

                    path_open = google + " " + "'" + mylistLocation + "'";
                    system(path_open.c_str());

                } else if ((mylistLocation.substr(mylistLocation.find_last_of(".") + 1) == "txt")) {
                    for (i = 0; i < basket_length; i++) {
                        // Insert the data to file
                        Coat coat = basket.getCoat_basket(i);
                        myfile << coat.getName() << " "
                               << coat.getSize() << " "
                               << coat.getPrice() << " "
                               << coat.getPhoto()
                               << "\n";
                    }
                    cout << "myList was added to a txt file\n";

                } else {
                    cout << "Extension must be either csv or html or txt.";
                }
            }
        }

        if (ok == 0) {
            cout << "No trench coat found in repository with this name.\n";
        }

        //SAVE TO FILE
        ofstream in;
        in.open (fileLocation);

        for (Coat& coat : controller.search()) {
            in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
        }

        in.close();

        mode_B(fileLocation, mylistLocation, position_repo, length, basket_length, controller, argc, argv);

    } else if (parameter[0] == "list") {
        int ok = 0;
        try
        {
            if (number_of_parameters != 3) {
                //throw MyException ("List has two parameters.\n");
            }
        }
        catch (std::exception &e)
        {
            cout << e.what();
            mode_B(fileLocation, mylistLocation, position_repo, length, basket_length, controller, argc, argv);
        }

        for (Coat& coat : controller.search()) {
            try
            {
                if (int user_price = std::atoi(parameter[2].c_str())) {
                    user_price = std::atoi(parameter[2].c_str());
                    if (parameter[1] == coat.getSize() && coat.getPrice() < user_price) {
                        cout << "Name: " << coat.getName() << " Size: " << coat.getSize() << " Price: " << coat.getPrice()
                             << " Photo: " << coat.getPhoto() << "\n";
                        ok = 1;
                    }
                } else {
                    //throw MyException ("Input for price must be integer.\n");
                }
            }
            catch (std::exception &e)
            {
                cout << e.what();
                mode_B(fileLocation, mylistLocation, position_repo, length, basket_length, controller, argc, argv);
            }
        }

        if (ok == 0) {
            cout << "Trench coat with given details does not exit.\n";
        }

        //SAVE TO FILE
        ofstream in;
        in.open (fileLocation);

        for (Coat& coat : controller.search()) {
            in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
        }

        in.close();

        mode_B(fileLocation, mylistLocation, position_repo, length, basket_length, controller, argc, argv);

    } else if (parameter[0] == "myList"){
        if (basket_length > 0) {
            cout<<"This is your shopping basket: \n";

            for (Coat& coat : basket.myBasket) {
                cout << "Name: " << coat.getName() << " Size: " << coat.getSize() << " Price: " << coat.getPrice() << " Photo: " << coat.getPhoto() << "\n";
            }
        }

        else {
            cout << "You haven't save anything yet.\n";
        }

        //SAVE TO FILE
        ofstream in;
        in.open (fileLocation);

        for (Coat& coat : controller.search()) {
            in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
        }

        in.close();

        mode_B(fileLocation, mylistLocation, position_repo, length, basket_length, controller, argc, argv);

    } else if (parameter[0] == "exit") {
        exit(0);

    } else if (parameter[0] == "mode" && parameter[1] == "A") {
        mode_A(fileLocation, mylistLocation, controller, argc, argv);
    }

    else {
        cout << "Invalid command!\n";
        mode_B(fileLocation, mylistLocation, 0, length, 0, controller, argc, argv);
    }
}

UI::~UI()
{
}