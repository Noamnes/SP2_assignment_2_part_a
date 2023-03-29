#include "doctest.h"
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
using namespace ariel;

TEST_CASE("valid stats of the game's starting:"){
    Player p1("noam"), p2("alice");
    Game game(p1,p2);
    // checking that each player starts with 26 new cards:
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    // checking that each player starts with 0 "wining" cards:
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("valid stats mid game:"){
    Player p1("noam"), p2("alice");
    Game game(p1,p2);
    game.playTurn();

    //checking that each player lost at leat one "new" card in the Turn:
    CHECK(p1.stacksize() <= 25);
    CHECK(p2.stacksize() <= 25);
    //checking that one player didn't gained "wining" cards at all:
    CHECK((p1.cardesTaken() == 0 || p2.cardesTaken() == 0));
    //checking that one player gained at least 2 "wining" cards 
    CHECK((p1.cardesTaken() >=2 || p2.cardesTaken() >= 2));
    //checking that the num of cards "lost" equels to the num of cards "wined":
    int numOfCardsLost = (26 - p1.stacksize()) + (26 - p2.stacksize());
    int numOfCardsWinned = p1.cardesTaken() + p2.cardesTaken();
    CHECK(numOfCardsLost == numOfCardsWinned);
    
    game.playTurn();
    //checking that each player lost at leat 2 "new" card in the Turn:    
    CHECK(p1.stacksize() <= 24);
    CHECK(p2.stacksize() <= 24);
    game.playTurn();
    //checking that each player lost at leat 3 "new" card in the Turn:    
    CHECK(p1.stacksize() <= 23);
    CHECK(p2.stacksize() <= 23);
    game.playTurn();
    //checking that each player lost at leat 4 "new" card in the Turn:    
    CHECK(p1.stacksize() <= 22);
    CHECK(p2.stacksize() <= 22);
    game.playTurn();
    //checking that each player lost at leat 5 "new" card in the Turn:    
    CHECK(p1.stacksize() <= 21);
    CHECK(p2.stacksize() <= 21);
    game.playTurn();
    //checking that each player lost at leat 6 "new" card in the Turn:    
    CHECK(p1.stacksize() <= 20);
    CHECK(p2.stacksize() <= 20);
    game.playTurn();
    //checking that each player lost at leat 2 "new" card in the Turn:    
    CHECK(p1.stacksize() <= 19);
    CHECK(p2.stacksize() <= 19);
}

TEST_CASE("valid stats end game:"){
    Player p1("noam"), p2("alice");
    Game game(p1,p2);
    game.playAll();
    //checking that each player lost all their "new" cards in the game:
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    //checking that the sum of the cards that has been won is 52:
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
}
