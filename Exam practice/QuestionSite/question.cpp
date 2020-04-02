#include "question.h"

#include <sstream>
#include <string>

std::string question::toPrint() {
    std::ostringstream toString;
    toString << this->id << " | " << this->text << " | " << this->name;
    return toString.str();
}
