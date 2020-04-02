#include "Controller.h"
#include "Mode_interface.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "Coat.h"
#include "Basket.h"

#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

class MyException : public std::exception
{
private:
    string message;

public:
    MyException(const string& s) : message(s) {}

    const char* what() const throw() override {
        return this->message.c_str();
    }
};

Repository repository;
Controller controller (repository);
UI ui (controller);

std::string fileLocation;
string myListLocation;

int main(int argc, char* argv[]) {
    int number_parameters = 0;

    char userInput[100];

    string parameter_text[100];
    string correct_path[100];
    int i = 0;
    cout << "fileLocation _____, mylistLocation _____, mode A/ mode B \n";
    fflush(stdin);
    cin.get(userInput, 500);
    cin.get();
    char* split_command;

    split_command  = strtok(userInput, " ");

    while(split_command != NULL) {
        parameter_text[i] = split_command;
        number_parameters ++;
        i++;
        split_command = strtok(NULL, ", ");
    }

    if (parameter_text[0] == "fileLocation") {
        for (i = 1; i <= number_parameters; i++) {
            correct_path[0] = correct_path[0] + parameter_text[i] + " ";
        }

        if (number_parameters == 2) {
            correct_path[0].pop_back();
            correct_path[0].pop_back();
        } else {
            correct_path[0].pop_back();
        }

        fstream in(correct_path[0], ios::in | ios::out);

        string line;
        string delimiter = " ";
        string parameter[100];

        int position_of_coat = 0;
        while (getline(in, line)) {
            size_t position_from_file = 0;
            i = 0;
            string parameter_from_file;
            while ((position_from_file = line.find(delimiter)) != std::string::npos) {
                parameter_from_file = line.substr(0, position_from_file);
                parameter[i] = parameter_from_file;
                line.erase(0, position_from_file + delimiter.length());
                i++;
            }
            if (!parameter_from_file.empty()) {
                parameter[i] = line;

                try {
                    if (int price = std::atoi(parameter[2].c_str())) {
                        controller.add(parameter[0], parameter[1], price, parameter[3]);
                    } else {
                        throw MyException ("One coat has an invalid price.\n");
                    }
                } catch (std::exception &e) {
                    cout << e.what();
                }
            }
            position_of_coat++;
        }

        fileLocation = correct_path[0];

    } else if (parameter_text[0] == "mylistLocation") {
        for (i = 1; i <= number_parameters; i++) {
            correct_path[0] = correct_path[0] + parameter_text[i] + " ";
        }

        correct_path[0].pop_back();
        fstream in(correct_path[0], ios::in | ios::out);

        myListLocation = correct_path[0];
        myListLocation.pop_back();

    } else if (parameter_text[0] == "mode"){
        if (parameter_text[1] == "A") {
            ui.mode_A(fileLocation, myListLocation, controller, argc, argv);
        }

        else if (parameter_text[1] == "B") {
            ui.mode_B(fileLocation, myListLocation, 0, controller.size(), 0, controller, argc, argv);
        }

        else {
            cout << "This mode does not exist.\n";
            main(argc, argv);
            return 0;
        }

    } else if (parameter_text[0] == "exit") {
        exit(0);

    } else {
        cout << "Invalid command.\n";
        main(argc, argv);
    }
    main(argc, argv);
}