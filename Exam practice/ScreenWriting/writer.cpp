#include "writer.h"

writer::writer()
{
}

std::string writer::toString() {
    std::ostringstream toPrint;
    toPrint << this->name << " | " << this->expertise;
    return toPrint.str();
}
