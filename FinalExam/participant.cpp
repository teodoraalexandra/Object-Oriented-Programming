#include "participant.h"

participant::participant()
{
}

std::string participant::toString() {
    std::ostringstream toPrint;
    toPrint << this->name << " | " << this->score;
    return toPrint.str();
}
