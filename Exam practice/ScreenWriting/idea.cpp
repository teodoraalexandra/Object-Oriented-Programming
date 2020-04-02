#include "idea.h"

std::string idea::toString() {
    std::ostringstream toPrint;
    toPrint << this->description << " | " << this->status << " | " << this->creator << " | " << this->act;
    return toPrint.str();
}
