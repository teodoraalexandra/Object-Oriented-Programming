//
// Created by Teodora Dan on 2019-04-08.
//

#include "Player.h"

Player::Player(const std::string &player_name, const std::string &player_nationality, const std::string &player_team, int player_goals):
    name {player_name}, nationality {player_nationality}, team {player_team}, goals (player_goals)
{}

Player::Player() : name{""}, nationality{""}, team{""}, goals()
{}

Player::~Player()
{}