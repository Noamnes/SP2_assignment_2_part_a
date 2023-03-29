#ifndef player_hpp
#define player_hpp

#include <iostream>
namespace ariel{
    class Player{
        private:
            std::string name;
        public:
            Player(std::string); // should i write here all the data members and functions ?? and constructors/destructors ??
            int stacksize();
            int cardesTaken();
    }; 
}
#endif