//
// Created by Teodora Dan on 2019-04-27.
//

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
#include <assert.h>

using namespace std;

int length_test = 0;
Repository repository_test;
Basket basket_test;
Controller controller_test (repository_test);
UI ui_test (controller_test);

void TestDelete() {
    string name[10], size[10], photo[10];
    controller_test.remove(9);
    length_test = controller_test.size();
    assert(length_test == 10); //This means that the coat has been deleted
}

void TestUpdate() {
    string name[10], size[10], photo[10];
    name[0] = "10";
    size[0] = 'm';
    photo[0] = "jpg";
    controller_test.update(name[0], size[0], 40, photo[0], 9);
    length_test = controller_test.size();
    assert(length_test == 11); //This means that the coat has been updated
}

void TestAdd() {
    string name[10], size[10], photo[10];
    name[0] = "10";
    size[0] = "s";
    photo[0] = "png";
    controller_test.add(name[0], size[0], 40, photo[0]);
    length_test = controller_test.size();
    assert(length_test == 11); //This means that the coat has been added
}

void TestCreate() {
    string line;
    ifstream in ("/Users/teodoradan/CLionProjects/Lab8-9/cmake-build-debug/repo.txt ");
    string delimiter = " ";
    string parameter[100];
    int i = 0;
    int position_of_coat = 0;
    int how_much_was_added = 0;
        while ( getline (in,line) )
        {
            size_t position_from_file = 0;
            string parameter_from_file;
            while ((position_from_file = line.find(delimiter)) != std::string::npos) {
                parameter_from_file = line.substr(0, position_from_file);
                parameter[i] = parameter_from_file;
                line.erase(0, position_from_file + delimiter.length());
                i++;
            }
            if (!parameter_from_file.empty()) {
                parameter[i] = line;
                if (int price = std::atoi(parameter[2].c_str())) {
                    controller_test.add(parameter[0], parameter[1], price, parameter[3]);
                    how_much_was_added ++;
                }
            }
            position_of_coat++;
        }
        in.close();

    assert(how_much_was_added == 10);
}

void TestController() {
    int number = 0;
    for (Coat& coat : controller_test.search()) {
        number++;
    }
    assert(number == 10);
}

void TestCoat() {
    int length = controller_test.size();
    for (int i = 0; i < length; i++) {
        Coat coat = controller_test.getCoat(i);
        if (i == 0) {
            assert(coat.getName() == "1");
            assert(coat.getSize() == "2");
            assert(coat.getPrice() == 3);
            assert(coat.getPhoto() == "4");
        }
    }
}

void TestBasket() {
    Coat coat = controller_test.getCoat(0);
    basket_test.add_basket(coat);
    assert(coat.getName() == basket_test.getCoat_basket(0).getName());
    assert(coat.getSize() == basket_test.getCoat_basket(0).getSize());
    assert(coat.getPrice() == basket_test.getCoat_basket(0).getPrice());
    assert(coat.getPhoto() == basket_test.getCoat_basket(0).getPhoto());
}

/*void TestModeInterface(int argc, char * argv[]) {
    ui_test.mode_A("/Users/teodoradan/CLionProjects/Lab8-9/cmake-build-debug/repo.txt ", "/Users/teodoradan/CLionProjects/Lab8-9/cmake-build-debug/repo.txt ", controller_test, argc, argv);
}*/

void runTest() {
    TestCreate();
    TestAdd();
    TestUpdate();
    TestDelete();
    TestController();
    TestCoat();
    TestBasket();
    //TestModeInterface();
}

