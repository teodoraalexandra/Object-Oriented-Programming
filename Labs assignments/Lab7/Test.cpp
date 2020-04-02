//
// Created by Teodora Dan on 2019-04-23.
//

/*
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

void TestDelete() {
    string name[10], size[10], photo[10];
    controller.remove(9);
    length = controller.size();
    assert(length == 9); //This means that the coat has been deleted
}

void TestUpdate() {
    string name[10], size[10], photo[10];
    name[0] = "10";
    size[0] = 'm';
    photo[0] = "jpg";
    controller.update(name[0], size[0], 40, photo[0], 9);
    length = controller.size();
    assert(length == 10); //This means that the coat has been updated
    Coat coat = controller.getCoat(9);
    assert(coat.getSize() == size[0]);
}

void TestAdd() {
    string name[10], size[10], photo[10];
    name[0] = "10";
    size[0] = "s";
    photo[0] = "png";
    controller.add(name[0], size[0], 40, photo[0]);
    length = controller.size();
    assert(length == 10); //This means that the coat has been added
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
            controller.add(parameter[0], parameter[1], std::atoi(parameter[2].c_str()), parameter[3]);
        }
    }
    length = controller.size();
    assert(length == 9);
}

void runTest() {
    TestCreate();
    TestAdd();
    TestUpdate();
    TestDelete();
}*/
