#include "player.hpp"
#include <iostream>

namespace ariel{
    Player::Player(std::string name){
        this->name = name;
    }
    int Player::stacksize(){
        return -1;
    }
    int Player::cardesTaken(){
        return -1;
    }
}