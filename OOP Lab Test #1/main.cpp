#include <iostream>
#include <cstring>
#include <cstdlib>

#include "Player.h"
#include "DynamicVector.h"
#include "Controller.h"

using namespace std;

Repository<DynamicVector> repository;
Controller controller{ repository };
int length = controller.size();

int main() {
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

    if (parameter[0] == "init") {
        controller.add("Ana", "ROU", "csm", 50);
        controller.add("Maria", "ROU", "csm", 60);
        controller.add("Ioana", "FRA", "csm", 40);
        controller.add("Cristina", "RUS", "csm", 90);
        controller.add("Andrei", "MOL", "csm", 30);
        length = controller.size();
        main();

    } else if (parameter[0] == "add") {
        //We read from console 4 parameters which represents the player characteristics
        string name[10];
        string nationality[10];
        string team[10];
        int goals[10];

        name[0] = parameter[1];
        nationality[0] = parameter[2];
        team[0] = parameter[3];
        goals[0] = std::atoi(parameter[4].c_str());
        int ok = 0;

        //in this for loop we will search if the player with the given name exist
        for (i = 0; i < length; i++) {
            Player player = repository.getPlayer(i);
            if ((player.getName().compare(name[0])) == 0) {
                cout << "This player already exists (enter another name).\n";
                ok = 1;
                //if it exists, ok will be 1, so the player will not be added
            }
        }

        if (ok == 0) {
            controller.add(name[0], nationality[0], team[0], goals[0]);
            length = controller.size();
            cout << "The player was added with success. \n";
            //if ok remain 0 through for loop, the player will be added
        }
        main();

    } else if (parameter[0] == "list") {
        length = controller.size();
        int maximum_goals = 0;

        //SORT BY GOALS
        for (i = 0; i < length; i++) {
            Player player = repository.getPlayer(i);
            cout << "Name: " << player.getName() << " Nationality: " << player.getNationality() << " Team: " << player.getTeam() << " Goals: " << player.getGoals() << "\n";
        }

        main();

    } else if (parameter[0] == "total") {
        string nationality[10];
        nationality[0] = parameter[1];

        int sum = 0;
        //
        length = controller.size();
        for (i = 0; i < length; i++) {
            Player player = repository.getPlayer(i);
            if ((player.getNationality().compare(nationality[0])) == 0)
                sum += player.getGoals();
        }
        cout << "Total is: " << sum << "\n";
        main();

    } else if (parameter[0] == "exit") {
        return 0;

    } else {
        cout << "Invalid command.";
        main();
    }

    return 0;
}