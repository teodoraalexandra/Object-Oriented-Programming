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
#include "Test.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

/*class MyException : public std::exception
{
private:
    string message;

public:
    MyException(const string& s) : message(s) {}

    const char* what() const throw() override {
        return this->message.c_str();
    }
};*/

int once = 0;
int test = 0;
Repository repository;
Controller controller (repository);
UI ui (controller);

std::string fileLocation;
string myListLocation;

void run() {
    runTest();
}

int main(int argc, char* argv[]) {
    if (once == 0) {
        run();
    }
    once ++;

    //TESTING FAKE REPOSITORY (IT HAS NO FUNCTION -> ALL ARE INHERITED BY REPOSITORY)
    if (test == 0) {
        FakeRepository fakeRepository;
        Controller controller(fakeRepository);

        string name[10], size[10], photo[10];
        name[0] = "10";
        size[0] = "s";
        photo[0] = "png";
        controller.add(name[0], size[0], 40, photo[0]);
        controller.update(name[0], size[0], 50, photo[0], 0);
        controller.remove(0);
    }
    test++;

    //END OF CONTROLLER TESTS

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

        correct_path[0].pop_back();
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
                        //throw MyException ("One coat has an invalid price.\n");
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
            cout << "Mode A has been activated...\n";
            cout << "\n";
            cout << "Menu: \n";
            cout << "   add name, size, price, photograph\n";
            cout << "   update name, size, price, photograph\n";
            cout << "   delete name\n";
            cout << "   list\n";
            cout << "   back to mode-change: mode B\n";
            ui.mode_A(fileLocation, myListLocation, controller, argc, argv);
        }

        else if (parameter_text[1] == "B") {
            cout << "Mode B has been activated...\n";
            cout << "\n";
            cout << "Menu: \n";
            cout << "   next (to iterate through items)\n";
            cout << "   save name\n";
            cout << "   list size, price\n";
            cout << "   myList (see the basket)\n";
            cout << "   back to mode-change: mode A\n";
            int position_repo = 0;
            int length = controller.size();
            ui.mode_B(fileLocation, myListLocation, position_repo, length, 0, controller, argc, argv);
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