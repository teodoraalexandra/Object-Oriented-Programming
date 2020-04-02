#include "Controller.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "Coat.h"
#include "Basket.h"

#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

int length = 0;
Repository repository;
Basket basket;
Controller controller{ repository };

struct UIException : public std::exception
{
    const char * what () const throw ()
    {
        return "UI exception caught.";
    }
};

void printMenu_modeA(string fileLocation, string myListLocation);
void printMenu_modeB(string fileLocation, string myListLocation);
void mode_A(string s, string m);
void mode_B(string s, string m, int position, int length, int basket_length);

void mode_A(string s, string m) {
    char userInput[100];
    string parameter[100];
    int i = 0;
    fflush(stdin);
    cin.get(userInput, 100);
    cin.get();
    char* split_command;
    split_command  = strtok(userInput, " ");

    int number_of_parameters = 0;
    while(split_command != NULL) {
        parameter[i] = split_command;
        number_of_parameters ++;
        i++;
        split_command = strtok(NULL, ", ");
    }

    if (parameter[0] == "add") {
        try
        {
            if (number_of_parameters != 5) {
                throw UIException();
            }
        }
        catch (UIException& e)
        {
            std::cout << "Number of parameters is not 4" << std::endl;
            std::cout << e.what() << std::endl;
            mode_A(s, m);
        }

        string name[10];
        string size[10];
        string photo[10];
        name[0] = parameter[1];
        size[0] = parameter[2];
        photo[0] = parameter[4];

        int ok = 0;
        //Validation for NAME -> if a coat with same name exist, it will not be added
        for (Coat& coat : repository.myVector) {
            if ((coat.getName().compare(name[0])) == 0) {
                cout << "This coat already exists (enter another name).\n";
                ok = 1;
            }
        }

        try
        {
            if (int price_coat = std::atoi(parameter[3].c_str()) && ok == 0) {
                price_coat = std::atoi(parameter[3].c_str());
                controller.add(name[0], size[0], price_coat, photo[0]);
                cout << "The coat has been added.\n";
                length = controller.size();
            } else {
                throw UIException();
            }
        }
        catch (UIException& e)
        {
            std::cout << "Coat has invalid price." << std::endl;
            std::cout << e.what() << std::endl;
            mode_A(s, m);
        }

        //SAVE TO FILE
        ofstream in;
        in.open (s);

        for (Coat& coat : repository.myVector) {
            in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
        }

        in.close();
        mode_A(s, m);
    }
    else if (parameter[0] == "update") {
        try
        {
            if (number_of_parameters != 5) {
                throw UIException();
            }
        }
        catch (UIException& e)
        {
            std::cout << "Number of parameters is not 4" << std::endl;
            std::cout << e.what() << std::endl;
            mode_A(s, m);
        }

        string name[10];
        string new_size[10];
        string new_photo[10];
        name[0] = parameter[1];
        new_size[0] = parameter[2];
        new_photo[0] = parameter[4];
        //We search in repository for "name"
        //If it doesn't exist a coat, ok = 0 -> "This coat does not exist"
        //In for, if found, ok = 1 -> update the coat
        int ok =0;
        i = 0;
        for (Coat& coat : repository.myVector) {
            if ((coat.getName().compare(name[0])) == 0) {
                ok = 1;
                try
                {
                    if (int price_coat = std::atoi(parameter[3].c_str()) && ok == 1) {
                        price_coat = std::atoi(parameter[3].c_str());
                        controller.update(name[0], new_size[0], price_coat, new_photo[0], i);
                        cout << "The coat has been updated.\n";
                        length = controller.size();

                    } else {
                        throw UIException();
                    }
                }
                catch (UIException& e)
                {
                    std::cout << "Coat has invalid price." << std::endl;
                    std::cout << e.what() << std::endl;
                    mode_A(s, m);
                }
            }
            i++;
        }

        if (ok == 0) {
            cout << "This coat does not exist (enter another name).\n";
        }

        //SAVE TO FILE
        ofstream in;
        in.open (s);

        for (Coat& coat : repository.myVector) {
            in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
        }

        in.close();

        mode_A(s, m);
    }
    else if (parameter[0] == "delete") {
        try
        {
            if (number_of_parameters != 2) {
                throw UIException();
            }
        }
        catch (UIException& e)
        {
            std::cout << "Number of parameters is not 1" << std::endl;
            std::cout << e.what() << std::endl;
            mode_A(s, m);
        }

        string name[10];
        name[0] = parameter[1];
        int ok = 0;
        //We search in repository for "name"
        //If it doesn't exist a coat, ok = 0 -> "This coat does not exist"
        //In for, if found, ok = 1 -> delete the coat
        i = 0;
        for (Coat& coat : repository.myVector) {
            if ((coat.getName().compare(name[0])) == 0) {
                controller.remove(i);
                //length = controller.size();
                cout << "The coat has been deleted.\n";
                ok = 1;
            }
            i ++;
        }

        if (ok == 0) {
            cout << "This coat does not exist (enter another name).\n";
        }

        //SAVE TO FILE
        ofstream in;
        in.open (s);

        for (Coat& coat : repository.myVector) {
            in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
        }

        in.close();

        mode_A(s, m);
    }
    else if (parameter[0] == "list") {
        try
        {
            if (number_of_parameters != 1) {
                throw UIException();
            }
        }
        catch (UIException& e)
        {
            std::cout << "List has no additional paramteters." << std::endl;
            std::cout << e.what() << std::endl;
            mode_A(s, m);
        }

        int ok = 0;

        for (Coat& coat : repository.myVector) {
            cout << "Name: " << coat.getName() << " Size: " << coat.getSize() << " Price: " << coat.getPrice() << " Photo: " << coat.getPhoto() << "\n";
            ok = 1;
        }

        if (ok == 0) {
            cout << "Empty repository.\n";
        }

        //SAVE TO FILE
        ofstream in;
        in.open (s);

        for (Coat& coat : repository.myVector) {
            in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
        }

        in.close();

        mode_A(s, m);
    }
    else if (parameter[0] == "exit") {
        exit(0);
    }

    else if (parameter[0] == "mode" && parameter[1] == "B") {
        printMenu_modeB(s, m);
    }
    else {
        cout << "Invalid command!\n";
        mode_A(s, m);
    }
}

void mode_B(string s, string m, int position_repo, int length, int basket_length) {
    int number_of_parameters = 0;
    char userInput[100];
    string parameter[100];
    int i = 0;
    fflush(stdin);
    cin.get(userInput, 100);
    cin.get();
    char *split_command;
    split_command = strtok(userInput, " ");
    Coat coat2 = controller.getCoat(position_repo);

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
                throw UIException();
            }
        }
        catch (UIException& e)
        {
            std::cout << "Next has no additional paramteters." << std::endl;
            std::cout << e.what() << std::endl;
            mode_B(s, m, position_repo, length, basket_length);
        }

        cout << "Name: " << coat2.getName() << " Size: " << coat2.getSize() << " Price: " << coat2.getPrice() << " Photo: " << coat2.getPhoto() << "\n";

        position_repo ++;
        if (position_repo >= length) {
            position_repo = 0;

            //SAVE TO FILE
            ofstream in;
            in.open (s);

            for (Coat& coat : repository.myVector) {
                in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
            }

            in.close();

            mode_B(s, m, position_repo, length, basket_length);
        }
        else {
            //SAVE TO FILE
            ofstream in;
            in.open (s);

            for (Coat& coat : repository.myVector) {
                in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
            }

            in.close();

            mode_B(s, m, position_repo, length, basket_length);
        }

    } else if (parameter[0] == "save") {
        int ok = 0;
        try
        {
            if (number_of_parameters != 2) {
                throw UIException();
            }
        }
        catch (UIException& e)
        {
            std::cout << "Save must take the name as a parameter." << std::endl;
            std::cout << e.what() << std::endl;
            mode_B(s, m, position_repo, length, basket_length);
        }

        for (Coat& coat : repository.myVector) {
            if (parameter[1] == coat.getName()) {
                basket.add_basket(coat);

                basket_length++;

                cout << "Trench coat has been added to your shopping basket.\n";
                ok = 1;
            }
        }

        if (ok == 0) {
            cout << "No trench coat found in repository with this name.\n";
        }

        //SAVE TO FILE
        ofstream in;
        in.open (s);

        for (Coat& coat : repository.myVector) {
            in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
        }

        in.close();

        mode_B(s, m, position_repo, length, basket_length);

    } else if (parameter[0] == "list") {
        int ok = 0;
        try
        {
            if (number_of_parameters != 3) {
                throw UIException();
            }
        }
        catch (UIException& e)
        {
            std::cout << "List has two parameters." << std::endl;
            std::cout << e.what() << std::endl;
            mode_B(s, m, position_repo, length, basket_length);
        }

        for (Coat& coat : repository.myVector) {
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
                    throw UIException();
                }
            }
            catch (UIException& e)
            {
                std::cout << "Input for price must be integer." << std::endl;
                std::cout << e.what() << std::endl;
                mode_B(s, m, position_repo, length, basket_length);
            }
        }

        if (ok == 0) {
            cout << "Trench coat with given details does not exit.\n";
        }

        //SAVE TO FILE
        ofstream in;
        in.open (s);

        for (Coat& coat : repository.myVector) {
            in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
        }

        in.close();

        mode_B(s, m, position_repo, length, basket_length);

    } else if (parameter[0] == "myList"){
        if (basket_length > 0) {
            cout<<"This is your shopping basket: \n";

            for (Coat& coat : basket.myBasket) {
                cout << "Name: " << coat.getName() << " Size: " << coat.getSize() << " Price: " << coat.getPrice() << " Photo: " << coat.getPhoto() << "\n";
            }

            fstream fout;
            fstream myfile;

            if (m.substr(m.find_last_of(".") + 1) == "csv") {
                fout.open (m);
                for (i = 0; i < basket_length; i++) {
                    // Insert the data to file
                    Coat coat = basket.getCoat_basket(i);
                    fout << coat.getName() << ", "
                         << coat.getSize() << ", "
                         << coat.getPrice() << ", "
                         << coat.getPhoto()
                         << "\n";
                }
                cout << "myList was added to a csv file\n";

            } else if (m.substr(m.find_last_of(".") + 1) == "html") {
                myfile.open (m);
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
                

            } else {
                cout << "Extension must be either csv or html.";
            }
        }

        else {
            cout << "You haven't save anything yet.\n";
        }

        //SAVE TO FILE
        ofstream in;
        in.open (s);

        for (Coat& coat : repository.myVector) {
            in << coat.getName() << " " << coat.getSize() << " " << coat.getPrice() << " " << coat.getPhoto() << "\n";
        }

        in.close();

        mode_B(s, m, position_repo, length, basket_length);

    } else if (parameter[0] == "exit") {
        exit(0);

    } else if (parameter[0] == "mode" && parameter[1] == "A") {
        printMenu_modeA(s, m);
    }

    else {
        cout << "Invalid command!\n";
        mode_B(s, m, 0, length, 0);
    }
}

void printMenu_modeA(string fileLocation, string myListLocation) {
    cout << "Mode A has been activated...\n";
    cout << "\n";
    cout << "Menu: \n";
    cout << "   add name, size, price, photograph\n";
    cout << "   update name, size, price, photograph\n";
    cout << "   delete name\n";
    cout << "   list\n";
    cout << "   back to mode-change: mode B\n";
    mode_A(fileLocation, myListLocation);
}

void printMenu_modeB(string fileLocation, string myListLocation) {
    cout << "Mode B has been activated...\n";
    cout << "\n";
    cout << "Menu: \n";
    cout << "   next (to iterate through items)\n";
    cout << "   save name\n";
    cout << "   list size, price\n";
    cout << "   myList (see the basket)\n";
    cout << "   back to mode-change: mode A\n";
    int position_repo = 0;
    length = controller.size();
    mode_B(fileLocation, myListLocation, position_repo, length, 0);
}

string fileLocation;
string myListLocation;
int main() {
    int number_parameters = 0;
    //char modeInput[100];

    char userInput[100];

    string parameter_text[100];
    string correct_path[100];
    int i = 0;
    cout << "fileLocation _____, mylistLocation _____, mode A/ mode B \n";
    fflush(stdin);
    cin.get(userInput, 100);
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
        if (number_parameters == 2) {
            correct_path[0] = parameter_text[1];
        } else {
            for (i = 1; i < number_parameters; i++) {
                correct_path[0] = correct_path[0] + parameter_text[i] + " ";
            }
        }

        correct_path[0].pop_back();
        ifstream in(correct_path[0]);
        try {
            if (!in) {
                throw UIException();
            }
        }
        catch (UIException &e) {
            std::cout << "File was not found." << std::endl;
            std::cout << e.what() << std::endl;
            main();
        }

        string line;
        string delimiter = " ";
        string parameter[100];

        int position_of_coat = 0;
        while (getline(in, line)) {
            size_t pos = 0;
            i = 0;
            string token;
            while ((pos = line.find(delimiter)) != std::string::npos) {
                token = line.substr(0, pos);
                parameter[i] = token;
                line.erase(0, pos + delimiter.length());
                i++;
            }
            if (!token.empty()) {
                parameter[i] = line;

                try {
                    if (int price = std::atoi(parameter[2].c_str())) {
                        controller.add(parameter[0], parameter[1], price, parameter[3]);
                    } else {
                        throw UIException();
                    }
                }
                catch (UIException &e) {
                    std::cout << "Coat from position " << position_of_coat << " has invalid price." << std::endl;
                    std::cout << e.what() << std::endl;
                }
            }
            position_of_coat++;
        }
        fileLocation = correct_path[0];

    } else if (parameter_text[0] == "mylistLocation") {
        if (number_parameters == 2) {
            correct_path[0] = parameter_text[1];
        } else {
            for (i = 1; i < number_parameters; i++) {
                correct_path[0] = correct_path[0] + parameter_text[i] + " ";
            }
        }

        correct_path[0].pop_back();
        ifstream in(correct_path[0]);
        try {
            if (!in) {
                throw UIException();
            }
        }
        catch (UIException &e) {
            std::cout << "File was not found." << std::endl;
            std::cout << e.what() << std::endl;
            main();
        }
        myListLocation = correct_path[0];

    } else if (parameter_text[0] == "mode"){
        if (parameter_text[1] == "A") {

            printMenu_modeA(fileLocation, myListLocation);
        }

        else if (parameter_text[1] == "B") {
            printMenu_modeB(fileLocation, myListLocation);
        }

        else {
            cout << "This mode does not exist.\n";
            main();
            return 0;
        }

    } else if (parameter_text[0] == "exit") {
        exit(0);

    } else {
        cout << "Invalid command";
        main();
    }
    main();
}

