#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "League.hpp"

using namespace std;

namespace Ex6{

    class Schedule{
        
        vector<Game*> games;
        League* league;

    public:
        Schedule(League *league);
        void Start_simulating(); 
        League* get_League(){
            return league;
        }   
    };

}