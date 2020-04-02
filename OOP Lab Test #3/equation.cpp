#include "equation.h"

std::string equation::toString() {
    std::ostringstream toPrint;
    toPrint << this->first << "*x^2 + " << this->second << " *x + " << this->third << "\n";
    return toPrint.str();
}
