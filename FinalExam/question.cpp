#include "question.h"
#include <sstream>


std::string question::toString() {
    std::ostringstream toPrint;
    toPrint << this->id << " | " << this->text << " | " << this->answer << " | " << this->score;
    return toPrint.str();
}

std::string question::withoutAnswer() {
    std::ostringstream toPrint;
    toPrint << this->id << " | " << this->text << " | " << this->score;
    return toPrint.str();
}
