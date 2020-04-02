//
// Created by Teodora Dan on 2019-04-23.
//

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
#include <assert.h>

using namespace std;

int length_test = 0;
Repository repository_test;
Basket basket_test;
Controller controller_test( repository_test );

void TestDelete() {
    string name[10], size[10], photo[10];
    controller_test.remove(9);
    length_test = controller_test.size();
    assert(length_test == 9); //This means that the coat has been deleted
}

void TestUpdate() {
    string name[10], size[10], photo[10];
    name[0] = "10";
    size[0] = 'm';
    photo[0] = "jpg";
    controller_test.update(name[0], size[0], 40, photo[0], 9);
    length_test = controller_test.size();
    assert(length_test == 10); //This means that the coat has been updated
    Coat coat = controller_test.getCoat(9);
    assert(coat.getSize() == size[0]);
}

void TestAdd() {
    string name[10], size[10], photo[10];
    name[0] = "10";
    size[0] = "s";
    photo[0] = "png";
    controller_test.add(name[0], size[0], 40, photo[0]);
    length_test = controller_test.size();
    assert(length_test == 10); //This means that the coat has been added
}

void TestCreate() {
    ifstream in("test.txt");
    int i = 0;
    string line;
    string delimiter = " ";
    string parameter[100];

    while(getline(in, line)) {
        size_t pos = 0;
        i = 0;
        string token;
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            parameter[i] = token;
            line.erase(0, pos + delimiter.length());
            i ++;
        }
        if (!token.empty()) {
            parameter[i] = line;
            controller_test.add(parameter[0], parameter[1], std::atoi(parameter[2].c_str()), parameter[3]);
        }
    }
    length_test = controller_test.size();
    assert(length_test == 9);
}

void runTest() {
    TestCreate();
    TestAdd();
    TestUpdate();
    TestDelete();
}
