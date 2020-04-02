#include <iostream>
#include "Person.h"
#include "MedicalAnalysis.h"
#include "BMI.h"
#include "BP.h"

using namespace std;

int main() {
    Person * person = new Person {"Angela"};

    cout << "What analysis?/ List\n";
    string option;
    cin >> option;
    if (option == "BMI") {
        double value;
        string date;
        cout << "Enter date: ";
        cin >> date;
        cout << "Enter a valid integer: ";
        cin >> value;
        /*if (value < 18 or value > 25) {
            std::cout << "Enter valid value.\n";
            main();
        }*/
        BMI * analysis = new BMI{date, value};
        analysis->toString();
        person->add(analysis);
    }

    else if (option == "BP") {
        int a, b;
        string date;
        cout << "Enter the date: ";
        cin >> date;
        cout << "Enter systolic value: ";
        cin >> a;
        /*if (a < 90 or a > 119) {
            std::cout << "Enter a valid value.\n";
            main();
        }*/
        cout << "Enter diastolic value: ";
        cin >> b;
        /*if (b < 60 or b > 79) {
            std::cout << "Enter a valid value.\n";
            main();
        }*/
        BP * analysis = new BP{date, a, b};
        analysis->toString();
        person->add(analysis);
    }
    else if (option == "list") {
        std::cout << person->size();
    }
    else if (option == "0") {
        return 0;
    }
    else {
        cout << "Incorect";
    }

    main();
    return 0;
}