//
// Created by Teodora Dan on 2019-04-08.
//

#ifndef MODEL1_DOMAIN_H
#define MODEL1_DOMAIN_H

#endif //MODEL1_DOMAIN_H

#include <string.h>
#include <iostream>

#pragma once

class Player {
private:
    std::string name;
    std::string nationality;
    std::string team;
    int goals;
public:
    Player(const std::string& player_name, const std::string& player_nationality, const std::string& player_team, int player_goals);
    Player();
    std::string getName() {return this->name;};
    std::string getNationality() { return this->nationality;};
    std::string getTeam() { return this->team;};
    int getGoals() {return this->goals;};
    ~Player();
};