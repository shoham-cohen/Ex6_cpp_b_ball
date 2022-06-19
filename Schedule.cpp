#include "Schedule.hpp"
using namespace std;

namespace Ex6{

    Schedule::Schedule(League *league){
        this->league = league;
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 20; j++){
                if(i != j){
                    Team * home_team = league-> get_Team(i);
                    Team * away_team = league-> get_Team(j);
                    Game *game = new Game(home_team, away_team);
                    games.push_back(game);
                }
            }
        }
    }

    void Schedule::Start_simulating(){
        srand(time(NULL));
        for(int i = 0; i < games.size(); i++){
            Team * winning_team = games[i]-> start_game();
        }
    }
}