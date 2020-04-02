#include "DynamicVector.h"
#include "DynamicVector_basket.h"
#include "Controller.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Coat.h"
#include "Basket.h"
using namespace std;

int main();
int length = 0;
Repository<DynamicVector> repository;
Basket<DynamicVector_basket> basket;
Controller controller{ repository };

void printMenu_modeA();
void printMenu_modeB();
void mode_A();
void mode_B(int position, int length, int basket_length);

void mode_A() {
    char userInput[100];
    string parameter[100];
    int i = 0;
    fflush(stdin);
    cin.get(userInput, 100);
    cin.get();
    char* split_command;
    split_command  = strtok(userInput, " ");

    while(split_command != NULL) {
        parameter[i] = split_command;
        i++;
        split_command = strtok(NULL, ", ");
    }

    if (parameter[0] == "add") {
        string name[10];
        string size[10];
        int price[10];
        string photo[10];
        name[0] = parameter[1];
        size[0] = parameter[2];
        price[0] = std::atoi(parameter[3].c_str());
        photo[0] = parameter[4];
        int ok = 0;
        //Validation for NAME -> if a coat with same name exist, it will not be added
        for (i = 0; i < length; i++) {
            Coat coat = controller.getCoat(i);
            if ((coat.getName().compare(name[0])) == 0) {
                cout << "This coat already exists (enter another name).\n";
                ok = 1;
            }
        }

        if (ok == 0) {
            controller.add(name[0], size[0], price[0], photo[0]);
            cout << "The coat has been added.\n";
            length = controller.size();
        }
        mode_A();
    }
    else if (parameter[0] == "update") {
        string name[10];
        string new_size[10];
        int new_price[10];
        string new_photo[10];
        name[0] = parameter[1];
        new_size[0] = parameter[2];
        new_price[0] = std::atoi(parameter[3].c_str());
        new_photo[0] = parameter[4];
        int ok = 0;
        //We search in repository for "name"
        //If it doesn't exist a coat, ok = 0 -> "This coat does not exist"
        //In for, if found, ok = 1 -> update the coat
        for (i = 0; i < length; i++) {
            Coat coat = controller.getCoat(i);
            if ((coat.getName().compare(name[0])) == 0) {
                controller.update(name[0], new_size[0], new_price[0], new_photo[0], i);
                cout << "The coat has been updated.\n";
                length = controller.size();
                ok = 1;
            }
        }

        if (ok == 0) {
            cout << "This coat does not exist (enter another name).\n";
        }
        mode_A();
    }
    else if (parameter[0] == "delete") {
        string name[10];
        name[0] = parameter[1];
        int ok = 0;
        //We search in repository for "name"
        //If it doesn't exist a coat, ok = 0 -> "This coat does not exist"
        //In for, if found, ok = 1 -> delete the coat
        for (i = 0; i < length; i++) {
            Coat coat = controller.getCoat(i);
            if ((coat.getName().compare(name[0])) == 0) {
                controller.remove(i);
                length = controller.size();
                cout << "The coat has been deleted.\n";
                ok = 1;
            }
        }

        if (ok == 0) {
            cout << "This coat does not exist (enter another name).\n";
        }

        mode_A();
    }
    else if (parameter[0] == "list") {
        int ok = 0;
        for (i = 0; i < length; i++) {
            Coat coat = controller.getCoat(i);
            cout << "Name: " << coat.getName() << " Size: " << coat.getSize() << " Price: " << coat.getPrice() << " Photo: " << coat.getPhoto() << "\n";
            ok = 1;
        }
        if (ok == 0) {
            cout << "Empty repository.\n";
        }
        mode_A();
    }
    else if (parameter[0] == "exit") {
        return;
    }

    else if (parameter[0] == "mode" && parameter[1] == "B") {
        printMenu_modeB();
    }
    else {
        cout << "Invalid command!\n";
        mode_A();
    }
}

void mode_B(int position_repo, int length, int basket_length) {
    char userInput[100];
    string parameter[100];
    int i = 0;
    fflush(stdin);
    cin.get(userInput, 100);
    cin.get();
    char *split_command;
    split_command = strtok(userInput, " ");

    Coat coat = controller.getCoat(position_repo);
    while (split_command != NULL) {
        parameter[i] = split_command;
        i++;
        split_command = strtok(NULL, ", ");
    }
    if (parameter[0] == "next") {
        cout << "Name: " << coat.getName() << " Size: " << coat.getSize() << " Price: " << coat.getPrice() << " Photo: " << coat.getPhoto() << "\n";

        position_repo ++;
        if (position_repo >= length) {
            position_repo = 0;
            mode_B(position_repo, length, basket_length);
        }
        else {
            mode_B(position_repo, length, basket_length);
        }

    } else if (parameter[0] == "save") {
        int ok = 0;
        for (i = 0; i < length; i++) {
            Coat coat = controller.getCoat(i);
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

        mode_B(position_repo, length, basket_length);

    } else if (parameter[0] == "list") {
        int ok = 0;
        for (i = 0; i < length; i++) {
            Coat coat = controller.getCoat(i);
            int user_price = std::atoi(parameter[2].c_str());
            if (parameter[1] == coat.getSize() && coat.getPrice() < user_price) {
                cout << "Name: " << coat.getName() << " Size: " << coat.getSize() << " Price: " << coat.getPrice()
                     << " Photo: " << coat.getPhoto() << "\n";
                ok = 1;
            }
        }

        if (ok == 0) {
            cout << "Trench coat with given details does not exit.\n";
        }
        mode_B(position_repo, length, basket_length);

    } else if (parameter[0] == "mylist"){
        cout<<"This is your shopping basket: \n";
        for (i = 0; i < basket_length; i++) {
            Coat coat = basket.getCoat_basket(i);
            cout << "Name: " << coat.getName() << " Size: " << coat.getSize() << " Price: " << coat.getPrice() << " Photo: " << coat.getPhoto() << "\n";
        }
        mode_B(position_repo, length, basket_length);

    } else if (parameter[0] == "exit") {
        return;

    } else if (parameter[0] == "mode" && parameter[1] == "A") {
        printMenu_modeA();
    }

    else {
        cout << "Invalid command!\n";
        mode_B(0, length, 0);
    }
}

void printMenu_modeA() {
    cout << "Mode A has been activated...\n";
    cout << "\n";
    cout << "Menu: \n";
    cout << "   add name, size, price, photograph\n";
    cout << "   update name, size, price, photograph\n";
    cout << "   delete name\n";
    cout << "   list\n";
    cout << "   back to mode-change: mode B\n";
    mode_A();
}

void printMenu_modeB() {
    cout << "Mode B has been activated...\n";
    cout << "\n";
    cout << "Menu: \n";
    cout << "   next (to iterate through items)\n";
    cout << "   save name\n";
    cout << "   list size, price\n";
    cout << "   mylist (see the basket)\n";
    cout << "   back to mode-change: mode A\n";
    int position_repo = 0;
    mode_B(position_repo, length, 0);
}

int main() {
    char modeInput[100];

    cout << "Enter the mode: <mode X>\n";
    fflush(stdin);
    cin.get(modeInput, 100);
    cin.get();
    if (strcmp(modeInput, "mode A") == 0) {
        printMenu_modeA();
    }

    else if (strcmp(modeInput, "mode B") == 0) {
        printMenu_modeB();
    }

    else if (strcmp(modeInput, "exit") == 0) {
        return 0;
    }

    else {
        cout << "This mode does not exist.\n";
        main();
    }
    return 0;
}

