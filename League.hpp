#include "Team.hpp"
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

using namespace std;

namespace Ex6{

    class League{
        vector<Team*> Teams = {};
    public:
        League(); // random constructor
        League(vector<Team*> teams);
        Team* get_Team(int i);
        vector<Team*> &get_Teams();
        void Print_league_stats();
        vector<string> teams_name = {"Lakers",
                                     "Bulls",
                                     "Warriors",
                                     "Kings", 
                                     "Jazz",
                                     "Clippers", 
                                     "Nets", 
                                     "Pacers", 
                                     "Celtics",
                                     "Hornets", 
                                     "Heat",
                                     "Mavericks", 
                                     "Grizzlies", 
                                     "Pelicans", 
                                     "Timberwolves",
                                     "Raptors",
                                     "Knicks", 
                                     "Nuggets", 
                                     "76ers", 
                                     "Suns"
                                    };
    };
}