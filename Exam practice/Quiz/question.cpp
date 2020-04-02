//
// Created by Teodora Dan on 2019-06-12.
//

#include "question.h"

std::string question::toString() {
    std::ostringstream toPrint;
    toPrint << this->id << " | " << this->text << " | " << this->answer << " | " << this->score;
    return toPrint.str();
}

std::string question::onlyForParticipants() {
    std::ostringstream toPrint;
    toPrint << this->id << " | " << this->text << " | " << this->score;
    return toPrint.str();
}
