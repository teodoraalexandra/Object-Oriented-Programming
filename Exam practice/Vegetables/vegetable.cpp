#include "vegetable.h"

vegetable::vegetable()
{
}

std::string vegetable::toString() {
    std::ostringstream toPrint;
    toPrint << this->family << " famili | " << this->name << " | " << this->part << "\n";
    return toPrint.str();
}
