#include <iostream>
#include "player.hpp"
#include "game.hpp"
namespace ariel{
    Game::Game(Player& player1 ,Player& player2) : p1(player1), p2(player2) {}
    void Game::playTurn(){}
    void Game::printLastTurn(){}
    void Game::playAll(){}
    void Game::printWiner(){}
    void Game::printLog(){}
    void Game::printStats(){}
}